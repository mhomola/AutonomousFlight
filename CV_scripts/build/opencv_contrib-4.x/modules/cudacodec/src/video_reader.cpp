/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                           License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#include "precomp.hpp"

using namespace cv;
using namespace cv::cuda;
using namespace cv::cudacodec;

#ifndef HAVE_NVCUVID

Ptr<VideoReader> cv::cudacodec::createVideoReader(const String&, const std::vector<int>&, const bool) { throw_no_cuda(); return Ptr<VideoReader>(); }
Ptr<VideoReader> cv::cudacodec::createVideoReader(const Ptr<RawVideoSource>&, const bool) { throw_no_cuda(); return Ptr<VideoReader>(); }

#else // HAVE_NVCUVID

void videoDecPostProcessFrame(const GpuMat& decodedFrame, GpuMat& _outFrame, int width, int height, cudaStream_t stream);

using namespace cv::cudacodec::detail;

namespace
{
    class VideoReaderImpl : public VideoReader
    {
    public:
        explicit VideoReaderImpl(const Ptr<VideoSource>& source);
        ~VideoReaderImpl();

        bool nextFrame(GpuMat& frame, Stream& stream) CV_OVERRIDE;

        FormatInfo format() const CV_OVERRIDE;

        bool grab(Stream& stream) CV_OVERRIDE;

        bool retrieve(OutputArray frame, const size_t idx) const CV_OVERRIDE;

        bool set(const VideoReaderProps propertyId, const double propertyVal) CV_OVERRIDE;

        bool get(const VideoReaderProps propertyId, double& propertyVal) const CV_OVERRIDE;

        bool get(const int propertyId, double& propertyVal) const CV_OVERRIDE;

    private:
        bool internalGrab(GpuMat& frame, Stream& stream);

        Ptr<VideoSource> videoSource_;

        Ptr<FrameQueue> frameQueue_ = 0;
        Ptr<VideoDecoder> videoDecoder_ = 0;
        Ptr<VideoParser> videoParser_ = 0;

        CUvideoctxlock lock_;

        std::deque< std::pair<CUVIDPARSERDISPINFO, CUVIDPROCPARAMS> > frames_;
        std::vector<RawPacket> rawPackets;
        GpuMat lastFrame;
        static const int decodedFrameIdx = 0;
        static const int extraDataIdx = 1;
        static const int rawPacketsBaseIdx = 2;
    };

    FormatInfo VideoReaderImpl::format() const
    {
        return videoSource_->format();
    }

    VideoReaderImpl::VideoReaderImpl(const Ptr<VideoSource>& source) :
        videoSource_(source),
        lock_(0)
    {
        // init context
        GpuMat temp(1, 1, CV_8UC1);
        temp.release();

        CUcontext ctx;
        cuSafeCall( cuCtxGetCurrent(&ctx) );
        cuSafeCall( cuvidCtxLockCreate(&lock_, ctx) );
        frameQueue_.reset(new FrameQueue());
        videoDecoder_.reset(new VideoDecoder(videoSource_->format().codec, ctx, lock_));
        videoParser_.reset(new VideoParser(videoDecoder_, frameQueue_));
        videoSource_->setVideoParser(videoParser_);
        videoSource_->start();
    }

    VideoReaderImpl::~VideoReaderImpl()
    {
        frameQueue_->endDecode();
        videoSource_->stop();
    }

    class VideoCtxAutoLock
    {
    public:
        VideoCtxAutoLock(CUvideoctxlock lock) : m_lock(lock) { cuSafeCall( cuvidCtxLock(m_lock, 0) ); }
        ~VideoCtxAutoLock() { cuvidCtxUnlock(m_lock, 0); }

    private:
        CUvideoctxlock m_lock;
    };

    bool VideoReaderImpl::internalGrab(GpuMat& frame, Stream& stream) {
        if (videoParser_->hasError())
            CV_Error(Error::StsError, "Parsing/Decoding video source failed, check GPU memory is available and GPU supports hardware decoding.");

        if (frames_.empty())
        {
            CUVIDPARSERDISPINFO displayInfo;
            rawPackets.clear();
            for (;;)
            {
                if (frameQueue_->dequeue(displayInfo, rawPackets))
                    break;

                if (videoParser_->hasError())
                    CV_Error(Error::StsError, "Parsing/Decoding video source failed, check GPU memory is available and GPU supports hardware decoding.");

                if (frameQueue_->isEndOfDecode())
                    return false;

                // Wait a bit
                Thread::sleep(1);
            }

            bool isProgressive = displayInfo.progressive_frame != 0;
            const int num_fields = isProgressive ? 1 : 2 + displayInfo.repeat_first_field;
            videoSource_->updateFormat(videoDecoder_->format());

            for (int active_field = 0; active_field < num_fields; ++active_field)
            {
                CUVIDPROCPARAMS videoProcParams;
                std::memset(&videoProcParams, 0, sizeof(CUVIDPROCPARAMS));

                videoProcParams.progressive_frame = displayInfo.progressive_frame;
                videoProcParams.second_field      = active_field;
                videoProcParams.top_field_first   = displayInfo.top_field_first;
                videoProcParams.unpaired_field    = (num_fields == 1);
                videoProcParams.output_stream = StreamAccessor::getStream(stream);

                frames_.push_back(std::make_pair(displayInfo, videoProcParams));
            }
        }

        if (frames_.empty())
            return false;

        std::pair<CUVIDPARSERDISPINFO, CUVIDPROCPARAMS> frameInfo = frames_.front();
        frames_.pop_front();

        {
            VideoCtxAutoLock autoLock(lock_);

            // map decoded video frame to CUDA surface
            GpuMat decodedFrame = videoDecoder_->mapFrame(frameInfo.first.picture_index, frameInfo.second);

            // perform post processing on the CUDA surface (performs colors space conversion and post processing)
            // comment this out if we include the line of code seen above
            videoDecPostProcessFrame(decodedFrame, frame, videoDecoder_->targetWidth(), videoDecoder_->targetHeight(), StreamAccessor::getStream(stream));

            // unmap video frame
            // unmapFrame() synchronizes with the VideoDecode API (ensures the frame has finished decoding)
            videoDecoder_->unmapFrame(decodedFrame);
        }

        // release the frame, so it can be re-used in decoder
        if (frames_.empty())
            frameQueue_->releaseFrame(frameInfo.first);

        return true;
    }

    bool VideoReaderImpl::grab(Stream& stream) {
        return internalGrab(lastFrame, stream);
    }

    bool VideoReaderImpl::retrieve(OutputArray frame, const size_t idx) const {
        if (idx == decodedFrameIdx) {
            if (!frame.isGpuMat())
                CV_Error(Error::StsUnsupportedFormat, "Decoded frame is stored on the device and must be retrieved using a cv::cuda::GpuMat");
            frame.getGpuMatRef() = lastFrame;
        }
        else if (idx == extraDataIdx) {
            if (!frame.isMat())
                CV_Error(Error::StsUnsupportedFormat, "Extra data  is stored on the host and must be retrueved using a cv::Mat");
            videoSource_->getExtraData(frame.getMatRef());
        }
        else{
            if (idx >= rawPacketsBaseIdx && idx < rawPacketsBaseIdx + rawPackets.size()) {
                if (!frame.isMat())
                    CV_Error(Error::StsUnsupportedFormat, "Raw data is stored on the host and must retrievd using a cv::Mat");
                Mat tmp(1, rawPackets.at(idx - rawPacketsBaseIdx).size, CV_8UC1, rawPackets.at(idx - rawPacketsBaseIdx).Data(), rawPackets.at(idx - rawPacketsBaseIdx).size);
                frame.getMatRef() = tmp;
            }
        }
        return !frame.empty();
    }

    bool VideoReaderImpl::set(const VideoReaderProps propertyId, const double propertyVal) {
        switch (propertyId) {
        case VideoReaderProps::PROP_RAW_MODE :
            videoSource_->SetRawMode(static_cast<bool>(propertyVal));
            break;
        }
        return true;
    }

    bool VideoReaderImpl::get(const VideoReaderProps propertyId, double& propertyVal) const {
        switch (propertyId)
        {
        case VideoReaderProps::PROP_DECODED_FRAME_IDX:
            propertyVal =  decodedFrameIdx;
            return true;
        case VideoReaderProps::PROP_EXTRA_DATA_INDEX:
            propertyVal = extraDataIdx;
            return true;
        case VideoReaderProps::PROP_RAW_PACKAGES_BASE_INDEX:
            if (videoSource_->RawModeEnabled()) {
                propertyVal = rawPacketsBaseIdx;
                return true;
            }
            else
                break;
        case VideoReaderProps::PROP_NUMBER_OF_RAW_PACKAGES_SINCE_LAST_GRAB:
            propertyVal = rawPackets.size();
            return true;
        case::VideoReaderProps::PROP_RAW_MODE:
            propertyVal = videoSource_->RawModeEnabled();
            return true;
        case::VideoReaderProps::PROP_LRF_HAS_KEY_FRAME: {
            const int iPacket = propertyVal - rawPacketsBaseIdx;
            if (videoSource_->RawModeEnabled() && iPacket >= 0 && iPacket < rawPackets.size()) {
                propertyVal = rawPackets.at(iPacket).containsKeyFrame;
                return true;
            }
            else
                break;
        }
        default:
            break;
        }
        return false;
    }

    bool VideoReaderImpl::get(const int propertyId, double& propertyVal) const {
        return videoSource_->get(propertyId, propertyVal);
    }

    bool VideoReaderImpl::nextFrame(GpuMat& frame, Stream& stream)
    {
        if (!internalGrab(frame, stream))
            return false;
        return true;
    }
}

Ptr<VideoReader> cv::cudacodec::createVideoReader(const String& filename, const std::vector<int>& params, const bool rawMode)
{
    CV_Assert(!filename.empty());

    Ptr<VideoSource> videoSource;

    try
    {
        // prefer ffmpeg to cuvidGetSourceVideoFormat() which doesn't always return the corrct raw pixel format
        Ptr<RawVideoSource> source(new FFmpegVideoSource(filename, params));
        videoSource.reset(new RawVideoSourceWrapper(source, rawMode));
    }
    catch (...)
    {
        if (params.size()) throw;
        videoSource.reset(new CuvidVideoSource(filename));
    }

    return makePtr<VideoReaderImpl>(videoSource);
}

Ptr<VideoReader> cv::cudacodec::createVideoReader(const Ptr<RawVideoSource>& source, const bool rawMode)
{
    Ptr<VideoSource> videoSource(new RawVideoSourceWrapper(source, rawMode));
    return makePtr<VideoReaderImpl>(videoSource);
}

#endif // HAVE_NVCUVID
