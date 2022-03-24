/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                          License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Copyright (C) 2013, OpenCV Foundation, all rights reserved.
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

#ifdef HAVE_NVCUVID

RawPacket::RawPacket(const unsigned char* _data, const size_t _size, const bool _containsKeyFrame) : size(_size), containsKeyFrame(_containsKeyFrame) {
    data = cv::makePtr<unsigned char*>(new unsigned char[size]);
    memcpy(*data, _data, size);
};

cv::cudacodec::detail::FrameQueue::~FrameQueue() {
    if (isFrameInUse_)
        delete[] isFrameInUse_;
}

void cv::cudacodec::detail::FrameQueue::init(const int _maxSz) {
    AutoLock autoLock(mtx_);
    maxSz = _maxSz;
    displayQueue_ = std::vector<CUVIDPARSERDISPINFO>(maxSz, CUVIDPARSERDISPINFO());
    isFrameInUse_ = new volatile int[maxSz];
    std::memset((void*)isFrameInUse_, 0, sizeof(*isFrameInUse_) * maxSz);
}

bool cv::cudacodec::detail::FrameQueue::waitUntilFrameAvailable(int pictureIndex)
{
    while (isInUse(pictureIndex))
    {
        // Decoder is getting too far ahead from display
        Thread::sleep(1);

        if (isEndOfDecode())
            return false;
    }

    return true;
}

void cv::cudacodec::detail::FrameQueue::enqueue(const CUVIDPARSERDISPINFO* picParams, const std::vector<RawPacket> rawPackets)
{
    // Mark the frame as 'in-use' so we don't re-use it for decoding until it is no longer needed
    // for display
    isFrameInUse_[picParams->picture_index] = true;

    // Wait until we have a free entry in the display queue (should never block if we have enough entries)
    do
    {
        bool isFramePlaced = false;

        {
            AutoLock autoLock(mtx_);

            if (framesInQueue_ < maxSz)
            {
                const int writePosition = (readPosition_ + framesInQueue_) % maxSz;
                displayQueue_.at(writePosition) = *picParams;
                for (const auto& rawPacket : rawPackets)
                    rawPacketQueue.push(rawPacket);
                framesInQueue_++;
                isFramePlaced = true;
            }
        }

        if (isFramePlaced) // Done
            break;

        // Wait a bit
        Thread::sleep(1);
    } while (!isEndOfDecode());
}

bool cv::cudacodec::detail::FrameQueue::dequeue(CUVIDPARSERDISPINFO& displayInfo, std::vector<RawPacket>& rawPackets)
{
    AutoLock autoLock(mtx_);

    if (framesInQueue_ > 0)
    {
        int entry = readPosition_;
        displayInfo = displayQueue_.at(entry);
        while (!rawPacketQueue.empty()) {
            rawPackets.push_back(rawPacketQueue.front());
            rawPacketQueue.pop();
        }
        readPosition_ = (entry + 1) % maxSz;
        framesInQueue_--;
        return true;
    }

    return false;
}

#endif // HAVE_NVCUVID
