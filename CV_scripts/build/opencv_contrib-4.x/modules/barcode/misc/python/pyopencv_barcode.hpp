#ifdef HAVE_OPENCV_BARCODE
typedef std::vector<cv::barcode::BarcodeType> vector_BarcodeType;

template<> struct pyopencvVecConverter<cv::barcode::BarcodeType>
{
    static bool to(PyObject* obj, std::vector<cv::barcode::BarcodeType>& value, const ArgInfo& info)
    {
        return pyopencv_to_generic_vec(obj, value, info);
    }
    static PyObject* from(const std::vector<cv::barcode::BarcodeType>& value)
    {

        return pyopencv_from_generic_vec(value);
    }
};

template<>
bool pyopencv_to(PyObject *o, std::vector<cv::barcode::BarcodeType>& types, const ArgInfo& info)
{
  return pyopencvVecConverter<cv::barcode::BarcodeType>::to(o, types, info);
}
#endif  // HAVE_OPENCV_BARCODE
