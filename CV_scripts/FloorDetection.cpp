#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using namespace cv;

cv::Mat filter_color(cv::Mat im, ushort y_low, ushort y_high, ushort u_low, ushort u_high, ushort v_low, ushort v_high, ushort resize_factor)
{
    cv::Mat image, YUV, croppedImage, FilteredImage;
    cv::resize(im, image, cv::Size(round(im.cols / resize_factor), round(im.rows / resize_factor)));
    int resize_value = 0.45*image.rows;
    croppedImage = image(cv::Range(resize_value, image.rows), cv::Range(0, image.cols));
    cv::cvtColor(croppedImage, YUV, cv::COLOR_BGR2YUV);
    int rows = (int) YUV.rows;
    int cols = (int) YUV.cols;
    std::vector<vector<int>> Filtered(rows, vector<int>(cols,0));

    // std::cout<<rows<<" "<<cols;

    // for (int i=0; i < YUV.rows; i++)
    // {
    //     for (int j=0; j<YUV.cols; j++)
    //     {
    //         std::cout<< Filtered[i][j]<<" ";
    //     } 
    //     std::cout<<"\n";
    // }
    cv::Vec3b color, color_show;

    for(int y=0; y<cols; y++)
    {
        for(int x=0; x<rows; x++)
        {
            color = YUV.at<cv::Vec3b>(cv::Point(y,x));
            if ((color[0] >= y_low) and (color[0] <= y_high) and (color[1] >= u_low) and (color[1] <= u_high) and (color[2] >= v_low) and (color[2] <= v_high))
            {
                Filtered[x][y] = 1;
            }
        }
    }

    FilteredImage.create(rows, cols, YUV.type());
    FilteredImage.setTo(cv::Scalar(0, 0, 0));
    for(int y=0; y<rows; y++)
    {
        for(int x=0; x<cols; x++)
        {
            if (Filtered[y][x] == 0)
            {
                Vec3b & color_show = FilteredImage.at<cv::Vec3b>(cv::Point(x,y));
                color_show[2] = 254;
            }
        }
    }
    // cv::namedWindow("Filtered Image", cv::WINDOW_AUTOSIZE);
    // cv::imshow("Filtered Image", FilteredImage);

    return FilteredImage;
}

bool filter_color_square(cv::Mat sq, ushort y_low, ushort y_high, ushort u_low, ushort u_high, ushort v_low, ushort v_high, ushort resize_factor, ushort passFactor)
{
    cv::Mat image_sq, YUV_sq;
    cv::resize(sq, image_sq, cv::Size(round(sq.cols / resize_factor), round(sq.rows / resize_factor)));
    cv::cvtColor(image_sq, YUV_sq, cv::COLOR_BGR2YUV);
    int rows_sq = (int) YUV_sq.rows;
    int cols_sq = (int) YUV_sq.cols;

    cv::Vec3b color_sq;

    int sum_sq = 0;
    int total_size_sq = rows_sq * cols_sq;

    for(int y=0; y<cols_sq; y++)
    {
        for(int x=0; x<rows_sq; x++)
        {
            color_sq = YUV_sq.at<cv::Vec3b>(cv::Point(y,x));
            if ((color_sq[0] >= y_low) and (color_sq[0] <= y_high) and (color_sq[1] >= u_low) and (color_sq[1] <= u_high) and (color_sq[2] >= v_low) and (color_sq[2] <= v_high))
            {
                sum_sq += 1;
            }
        }
    }

    double average_sq = (double) sum_sq / total_size_sq;
    bool cond = 0;
    
    if (average_sq >= passFactor)
    {
        cond = 1;
    }

    return cond;
}

int main()
{
    cv::Mat image, filtered_image;
    image = cv::imread("./../Data/cyberzoo_poles/2_original.jpg", 1);
    // std::cout<<"Size before:"<<cv::Size(round(image.cols / 3), round(image.rows / 3));

    filtered_image = filter_color(image, 70, 90, 100, 130, 100, 135, 1);
 
    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display Image", image);
    cv::namedWindow("Filtered Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Filtered Image", filtered_image);
    cv::waitKey(0);
    return 0;
}
