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

int row_num=4;
int img_per_row=20;
int nr_squares = 68;

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

bool filter_color_square(cv::Mat sq, ushort y_low, ushort y_high, ushort u_low, ushort u_high, ushort v_low, ushort v_high, ushort resize_factor, float passFactor)
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

bool is_carpet(int *pixel, cv::Mat image)
{
    cv::Mat new_image;
    int height = (int) (image.rows * 0.4);
    int index = pixel[0];
    bool status = 0, cond;
    while ((index > height) and (status == 0))
    {
        index -= 10;
        new_image = image(cv::Range(index, index + pixel[2]), cv::Range(pixel[1], pixel[1] + pixel[2]));
        cond = filter_color_square(new_image, 70, 90, 100, 130, 100, 135, 1, 0.5);
        if (cond)
        {
            status = 1;
        }
    }
    return status;
}

int **gen_squares(int rows, int cols)
{
    int base_dim1_t, base_dim2_t;
    double base_dim2;
    int sq_size = (int) (cols / 40);
    int **dimensions = new int*[nr_squares];
    for (size_t h = 0; h < nr_squares; h++)
      {
            dimensions[h] = new int[3];
      }
    int sum=0;
    for (int i=0; i<row_num; i++)
    {
        base_dim1_t = rows - 2 * (i + 1) * sq_size;
        base_dim2 = (double) (cols / (img_per_row + 2));
        for (int j=0; j < img_per_row - 2 * i; j++)
        {
            base_dim2_t = (int) ((j + i + 1.5) * base_dim2 - sq_size / 2);
            dimensions[i*img_per_row - (2 * sum) + j][0] = base_dim1_t;
            dimensions[i*img_per_row - (2 * sum) + j][1] = base_dim2_t;
            dimensions[i*img_per_row - (2 * sum) + j][2] = sq_size;
        }
        sum += i;
    }
    return dimensions;
}

bool *square_mesh(int **dims, cv::Mat image)
{
    int size = dims[0][2];
    cv::Mat square;
    bool outcome;
    bool *go_zone = new bool[nr_squares];
    for (int i=0; i<nr_squares; i++)
    {
        square = image(cv::Range(dims[i][0], dims[i][0] + size), cv::Range(dims[i][1], dims[i][1] + size));
        outcome = (filter_color_square(square, 70, 90, 100, 130, 100, 135, 1, 0.5) or is_carpet(dims[i], image));
        // 
        go_zone[i] = outcome;
    }
    return go_zone;
}

cv::Mat show_square_mesh(int **dims, cv::Mat image)
{
    bool *array_squares = square_mesh(dims, image);
    int size = dims[0][2];
    for (int i=0; i<nr_squares; i++)
    {
        if (array_squares[i])
        {
            image(cv::Range(dims[i][0], dims[i][0] + size), cv::Range(dims[i][1], dims[i][1] + size)).setTo(cv::Scalar(0, 255, 0));
        }
        else
        {
            image(cv::Range(dims[i][0], dims[i][0] + size), cv::Range(dims[i][1], dims[i][1] + size)).setTo(cv::Scalar(0, 0, 255));
        }
    }
    return image;
}

int main()
{
    cv::Mat image, filtered_image, squares_image;
    image = cv::imread("./../../../Data/cyberzoo_poles/2_original.jpg", 1);
    // std::cout<<"Size before:"<<cv::Size(round(image.cols / 3), round(image.rows / 3));

    filtered_image = filter_color(image, 70, 90, 100, 130, 100, 135, 3);

    int **squares = new int*[nr_squares];
    for (int h = 0; h < nr_squares; h++)
    {
        squares[h] = new int[3];
    }
    squares = gen_squares(image.rows, image.cols);

    // for (int i=0; i<nr_squares; i++)
    // {
    //     for (int j=0; j<3; j++)
    //     {
    //         std::cout<<squares[i][j]<<"  ";
    //     }
    //     std::cout<<"\n";
    // }

    bool *go_zone = new bool[nr_squares];
    go_zone = square_mesh(squares, filtered_image);

    squares_image = show_square_mesh(squares, filtered_image);

 
    // cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    // cv::imshow("Display Image", image);
    // cv::namedWindow("Filtered Image", cv::WINDOW_AUTOSIZE);
    // cv::imshow("Filtered Image", filtered_image);
    cv::namedWindow("Squares Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Squares Image", squares_image);
    cv::waitKey(0);
    return 0;
}
