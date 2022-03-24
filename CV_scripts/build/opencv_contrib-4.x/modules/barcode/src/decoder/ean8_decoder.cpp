// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.
// Copyright (c) 2020-2021 darkliang wangberlinT Certseeds

#include "../precomp.hpp"
#include "ean8_decoder.hpp"

namespace cv {
namespace barcode {
static constexpr size_t EAN8BITS_NUM = 70;
static constexpr size_t EAN8DIGIT_NUM = 8;

Result Ean8Decoder::decode(const vector<uchar> &data) const
{
    std::string result;
    char decode_result[EAN8DIGIT_NUM + 1]{'\0'};
    if (data.size() < EAN8BITS_NUM)
    {
        return Result("Wrong Size", BarcodeType::NONE);
    }
    pair<uint, uint> pattern;
    if (!findStartGuardPatterns(data, pattern))
    {
        return Result("Begin Pattern Not Found", BarcodeType::NONE);
    }
    uint start = pattern.second;
    Counter counter(vector<int>{0, 0, 0, 0});
    size_t end = data.size();
    int first_char_bit = 0;
    for (int i = 0; i < 4 && start < end; ++i)
    {
        int bestMatch = decodeDigit(data, counter, start, get_A_or_C_Patterns());
        if (bestMatch == -1)
        {
            return Result("Decode Error", BarcodeType::NONE);
        }
        decode_result[i] = static_cast<char>('0' + bestMatch % 10);
        start = counter.sum + start;
        first_char_bit += (bestMatch >= 10) << i;
    }

    Counter middle_counter(vector<int>(MIDDLE_PATTERN().size()));

    if (!findGuardPatterns(data, start, true, MIDDLE_PATTERN(), middle_counter, pattern))
    {
        return Result("Middle Pattern Not Found", BarcodeType::NONE);
    }

    start = pattern.second;
    for (int i = 0; i < 4 && start < end; ++i)
    {
        int bestMatch = decodeDigit(data, counter, start, get_A_or_C_Patterns());
        if (bestMatch == -1)
        {
            return Result("Decode Error", BarcodeType::NONE);
        }
        decode_result[i + 4] = static_cast<char>('0' + bestMatch);
        start = counter.sum + start;
    }
    Counter end_counter(vector<int>(BEGIN_PATTERN().size()));
    if (!findGuardPatterns(data, start, false, BEGIN_PATTERN(), end_counter, pattern))
    {
        return Result("End Pattern Not Found", BarcodeType::NONE);
    }
    result = string(decode_result);
    if (!isValid(result))
    {
        return Result("Wrong: " + result.append(string(EAN8DIGIT_NUM - result.size(), ' ')), BarcodeType::NONE);
    }
    return Result(result, BarcodeType::EAN_8);
}

Ean8Decoder::Ean8Decoder()
{
    this->digit_number = EAN8DIGIT_NUM;
    this->bits_num = EAN8BITS_NUM;
}

}
}
