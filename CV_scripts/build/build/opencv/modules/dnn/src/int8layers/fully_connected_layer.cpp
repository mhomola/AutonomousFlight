// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.

#include "../precomp.hpp"
#include "layers_common.hpp"

#include <opencv2/dnn/shape_utils.hpp>

namespace cv
{
namespace dnn
{

class FullyConnectedLayerInt8Impl CV_FINAL : public InnerProductLayerInt8
{
public:
    enum { VEC_ALIGN = 32 };
    FullyConnectedLayerInt8Impl(const LayerParams& params)
    {
        setParamsFrom(params);
        output_zp = params.get<int>("zeropoints");
        axis = params.get<int>("axis", 1);
        if (blobs.size() == 3)
        {
            // blobs[0] - Weights
            // blobs[1] - Bias fused with offset
            // blobs[2] - Multipliers for output stage
            int numOutput = params.get<int>("num_output");
            int innerSize = (int)blobs[0].total() / numOutput;

            CV_Assert(blobs[0].dims >= 2 && (size_t)(innerSize * numOutput) == blobs[0].total());
            CV_Assert((size_t)numOutput == blobs[1].total());

            weightsMat = blobs[0] = blobs[0].reshape(1, numOutput);
            int vecsize = weightsMat.cols;
            if (vecsize % VEC_ALIGN != 0)
            {
                int vecsize_aligned = (int)alignSize(vecsize, VEC_ALIGN);
                Mat weightsBuf(weightsMat.rows, vecsize_aligned, weightsMat.type());
                Mat wpadding = weightsBuf.colRange(vecsize, vecsize_aligned);
                wpadding.setTo(Scalar::all(0));
                weightsMat = weightsBuf.colRange(0, vecsize);
                blobs[0].copyTo(weightsMat);
            }
            biasMat = blobs[1] = blobs[1].reshape(1, 1);
            outputMultiplier = blobs[2];
        }
    }

    bool getMemoryShapes(const std::vector<MatShape> &inputs,
                         const int requiredOutputs,
                         std::vector<MatShape> &outputs,
                         std::vector<MatShape> &) const CV_OVERRIDE
    {
        int numOutput, cAxis;
        CV_CheckEQ(inputs.size(), (size_t)1, "");
        CV_CheckEQ(blobs[0].dims, 2, "");
        numOutput = blobs[0].size[0];
        CV_Assert((size_t)numOutput == blobs[1].total());
        cAxis = normalize_axis(axis, inputs[0]);

        MatShape outShape(cAxis + 1);
        for (int i = 0; i < cAxis; ++i)
            outShape[i] = inputs[0][i];
        outShape.back() = numOutput;

        outputs.resize(1, outShape);
        return false;
    }

    virtual bool supportBackend(int backendId) CV_OVERRIDE
    {
        return backendId == DNN_BACKEND_OPENCV;
    }

    virtual bool setActivation(const Ptr<ActivationLayer>& layer) CV_OVERRIDE
    {
        Ptr<ActivationLayerInt8> activ_int8 = layer.dynamicCast<ActivationLayerInt8>();
        if (!activ_int8.empty())
        {
            activ = activ_int8;
            if (!activ_int8->blobs.empty())
                activ_int8->blobs[0].convertTo(activationLUT, CV_32S);
            return true;
        }
        return false;
    }

    class FullyConnected : public ParallelLoopBody
    {
    public:
        FullyConnected() : srcMat(0), weights(0), biasMat(0), outputMultiplier(0), activationLUT(0), activ(0),
                           dstMat(0), nstripes(0), outZp(0), useAVX2(false), useAVX512(false) {}

        static void run(const Mat& srcMat, const Mat& weights, const Mat& biasMat, const Mat& outputMultiplier,
                        const Mat& activationLUT, Mat& dstMat, const ActivationLayerInt8* activ, int nstripes, int outZp)
        {
            CV_Assert( srcMat.dims == 2 && srcMat.cols == weights.cols &&
                       dstMat.rows == srcMat.rows && dstMat.cols == weights.rows &&
                       srcMat.type() == weights.type() && srcMat.type() == CV_8S &&
                       dstMat.type() == CV_32S && biasMat.type() == CV_32S &&
                       biasMat.isContinuous() && (int)biasMat.total() == dstMat.cols );

            FullyConnected p;

            p.srcMat = &srcMat;
            p.weights = &weights;
            p.biasMat = &biasMat;
            p.outputMultiplier = &outputMultiplier;
            p.activationLUT = &activationLUT;
            p.dstMat = &dstMat;
            p.nstripes = nstripes;
            p.outZp = outZp;
            p.activ = !activationLUT.empty() ? activ : 0;
            p.useAVX2 = checkHardwareSupport(CPU_AVX2);
            p.useAVX512 = CV_CPU_HAS_SUPPORT_AVX512_SKX;

            parallel_for_(Range(0, nstripes), p, nstripes);
        }

        void operator()(const Range& r) const CV_OVERRIDE
        {
            int valign = FullyConnectedLayerInt8Impl::VEC_ALIGN;
            int nsamples = srcMat->rows;
            int nw0 = weights->rows;
            int k, vecsize = srcMat->cols;
            int vecsize_aligned = (int)alignSize(vecsize, VEC_ALIGN);
            size_t total = (size_t)nsamples*nw0;
            size_t stripeSize = (total + nstripes - 1)/nstripes;
            size_t stripeStart = r.start*stripeSize;
            size_t stripeEnd = r.end == nstripes ? total : std::min(r.end*stripeSize, total);
            size_t wstep = weights->step1();
            AutoBuffer<int8_t> srcbuf(vecsize_aligned + valign);
            int8_t* sptr = alignPtr(srcbuf.data(), (int)(valign*sizeof(int8_t)));
            const int* lutptr = !activationLUT->empty() ? activationLUT->ptr<int>() : 0;

            for( k = vecsize; k < vecsize_aligned; k++ )
                sptr[k] = 0;

            for( size_t ofs = stripeStart; ofs < stripeEnd; )
            {
                int sampleIdx = (int)(ofs / nw0);
                int delta = (int)(ofs - (size_t)sampleIdx*nw0);
                const int8_t* sptr_ = srcMat->ptr<int8_t>(sampleIdx);
                const int8_t* wptr = weights->ptr<int8_t>(delta);
                int* dptr = dstMat->ptr<int>(sampleIdx) + delta;
                const int* biasptr = biasMat->ptr<int>() + delta;
                const float* multptr = outputMultiplier->ptr<float>() + delta;
                int nw = std::min(nw0 - delta, (int)(stripeEnd - ofs));

                memcpy(sptr, sptr_, vecsize*sizeof(sptr[0]));
            #if CV_TRY_AVX512_SKX
                if( useAVX512 )
                    opt_AVX512_SKX::fastGEMM1T( sptr, wptr, wstep, biasptr, multptr, dptr, nw, vecsize, outZp );
                else
            #endif
            #if CV_TRY_AVX2
                if( useAVX2 )
                    opt_AVX2::fastGEMM1T( sptr, wptr, wstep, biasptr, multptr, dptr, nw, vecsize, outZp );
                else
            #endif
                {
                    int i = 0;
            #if CV_SIMD
                    for( ; i  <= nw - 4; i += 4, wptr += 4*wstep )
                    {
                        v_int32x4 vs0 = v_setzero_s32(), vs1 = v_setzero_s32(),
                                  vs2 = v_setzero_s32(), vs3 = v_setzero_s32();
                        v_int32x4 outzp = v_setall_s32(outZp), outmin = v_setall_s32(-128), outmax = v_setall_s32(127);
                        v_int32x4 s = v_load(biasptr + i);
                        v_float32x4 mult = v_load(multptr + i);

                        for( k = 0; k < vecsize; k += 16 )
                        {
                            v_int8x16 v = v_load_aligned(sptr + k);
                            vs0 = v_dotprod_expand_fast(v, v_load_aligned(wptr + k), vs0);
                            vs1 = v_dotprod_expand_fast(v, v_load_aligned(wptr + wstep + k), vs1);
                            vs2 = v_dotprod_expand_fast(v, v_load_aligned(wptr + wstep*2 + k), vs2);
                            vs3 = v_dotprod_expand_fast(v, v_load_aligned(wptr + wstep*3 + k), vs3);
                        }

                        s += v_int32x4(v_reduce_sum(vs0), v_reduce_sum(vs1), v_reduce_sum(vs2), v_reduce_sum(vs3));
                        v_int32x4 out = outzp + v_round(v_cvt_f32(s)*mult);
                        v_store(dptr + i, v_min(v_max(out, outmin), outmax));
                    }
            #endif

                    for( ; i < nw; i++, wptr += wstep )
                    {
                        int s0 = biasptr[i];
                        float mult0 = multptr[i];

                        for( k = 0; k < vecsize; k++ )
                        {
                            int8_t v = sptr[k];
                            s0 += (int)v*wptr[k];
                        }
                        int out0 = outZp + (int)std::round(s0*mult0);
                        dptr[i] = std::min(std::max(out0, -128), 127);
                    }
                }

                if(activ)
                    activ->forwardSlice(dptr, lutptr, dptr, 1, 1, delta, delta + nw);

                ofs += nw;
            }
        }

        const Mat *srcMat, *weights, *biasMat, *outputMultiplier, *activationLUT;
        const ActivationLayerInt8* activ;
        Mat* dstMat;
        int nstripes, outZp;
        bool useAVX2;
        bool useAVX512;
    };

    void forward(InputArrayOfArrays inputs_arr, OutputArrayOfArrays outputs_arr, OutputArrayOfArrays internals_arr) CV_OVERRIDE
    {
        CV_TRACE_FUNCTION();
        CV_TRACE_ARG_VALUE(name, "name", name.c_str());

        std::vector<Mat> input, output;
        inputs_arr.getMatVector(input);
        outputs_arr.getMatVector(output);

        int axisCan = normalize_axis(axis, input[0].dims);
        int outerSize = input[0].total(0, axisCan);
        Mat srcMat = input[0].reshape(1, outerSize);

        Mat dstMat = output[0].reshape(1, outerSize);
        Mat dstMatInt32= Mat(shape(dstMat), CV_32S);

        const int nstripes = getNumThreads();
        FullyConnected::run(srcMat, weightsMat, biasMat, outputMultiplier, activationLUT, dstMatInt32, activ.get(), nstripes, output_zp);
        dstMatInt32.convertTo(dstMat, CV_8S);
    }

    virtual int64 getFLOPS(const std::vector<MatShape> &inputs,
                           const std::vector<MatShape> &outputs) const CV_OVERRIDE
    {
        CV_UNUSED(inputs); // suppress unused variable warning
        long flops = 0;

        int innerSize = blobs[0].size[1];
        for(int i = 0; i < outputs.size(); i++)
        {
            flops += CV_BIG_INT(3)*innerSize*total(outputs[i]);
        }

        return flops;

    }

    Mat weightsMat, biasMat, outputMultiplier, activationLUT;
    Ptr<ActivationLayerInt8> activ;
};

Ptr<InnerProductLayerInt8> InnerProductLayerInt8::create(const LayerParams& params)
{
    return Ptr<InnerProductLayerInt8>(new FullyConnectedLayerInt8Impl(params));
}

}
}
