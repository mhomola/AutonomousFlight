/// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.
//
// Tencent is pleased to support the open source community by making WeChat QRCode available.
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.

#ifndef __OPENCV_BARCODE_SUPER_SCALE_HPP__
#define __OPENCV_BARCODE_SUPER_SCALE_HPP__


namespace cv {
namespace barcode {

class SuperScale
{
public:
    SuperScale() = default;

    ~SuperScale() = default;

    int init(const std::string &proto_path, const std::string &model_path);

    void processImageScale(const Mat &src, Mat &dst, float scale, const bool &use_sr, int sr_max_size = 160);

private:
    dnn::Net srnet_;
    bool net_loaded_ = false;

    int superResolutionScale(const cv::Mat &src, cv::Mat &dst);
};

}  // namespace barcode
}  // namespace cv
#endif //__OPENCV_BARCODE_SUPER_SCALE_HPP__
