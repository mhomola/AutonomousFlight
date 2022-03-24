#include "floor_detection_funcs.h"

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

// #include <iostream>
// #include <chrono>

using namespace std;
using namespace cv;

int row_num = 4;
int img_per_row = 20;
int nr_squares = 68;


// cv::Mat filter_color(cv::Mat im, ushort y_low, ushort y_high, ushort u_low, ushort u_high, ushort v_low, ushort v_high, ushort resize_factor)
// {
//     cv::Mat image, YUV, croppedImage, FilteredImage;
//     cv::resize(im, image, cv::Size(round(im.cols / resize_factor), round(im.rows / resize_factor)));
//     int resize_value = 0.45*image.rows;
//     croppedImage = image(cv::Range(resize_value, image.rows), cv::Range(0, image.cols));
//     cv::cvtColor(croppedImage, YUV, cv::COLOR_BGR2YUV);
//     int rows = (int) YUV.rows;
//     int cols = (int) YUV.cols;
//     std::vector<vector<int>> Filtered(rows, vector<int>(cols,0));

//     // std::cout<<rows<<" "<<cols;

//     // for (int i=0; i < YUV.rows; i++)
//     // {
//     //     for (int j=0; j<YUV.cols; j++)
//     //     {
//     //         std::cout<< Filtered[i][j]<<" ";
//     //     } 
//     //     std::cout<<"\n";
//     // }
//     cv::Vec3b color, color_show;

//     for(int y=0; y<cols; y++)
//     {
//         for(int x=0; x<rows; x++)
//         {
//             color = YUV.at<cv::Vec3b>(cv::Point(y,x));
//             if ((color[0] >= y_low) and (color[0] <= y_high) and (color[1] >= u_low) and (color[1] <= u_high) and (color[2] >= v_low) and (color[2] <= v_high))
//             {
//                 Filtered[x][y] = 1;
//             }
//         }
//     }
//     FilteredImage.create(rows, cols, YUV.type());
//     FilteredImage.setTo(cv::Scalar(0, 0, 0));
//     for(int y=0; y<rows; y++)
//     {
//         for(int x=0; x<cols; x++)
//         {
//             if (Filtered[y][x] == 0)
//             {
//                 Vec3b & color_show = FilteredImage.at<cv::Vec3b>(cv::Point(x,y));
//                 color_show[2] = 254;
//             }
//         }
//     }
//     // cv::namedWindow("Filtered Image", cv::WINDOW_AUTOSIZE);
//     // cv::imshow("Filtered Image", FilteredImage);
//     return FilteredImage;
// }

bool filter_color_square(cv::Mat sq, ushort y_low, ushort y_high, ushort u_low, ushort u_high, ushort v_low, ushort v_high, ushort resize_factor, float passFactor)
{
    cv::Mat image_sq, YUV_sq;
    cv::resize(sq, image_sq, cv::Size(round(sq.cols / resize_factor), round(sq.rows / resize_factor)));
    cv::cvtColor(image_sq, YUV_sq, cv::COLOR_BGR2YUV);
    ushort rows_sq = (int) YUV_sq.rows;
    ushort cols_sq = (int) YUV_sq.cols;

    cv::Vec3b color_sq;

    ushort sum_sq = 0;
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
        go_zone[i] = outcome;
    }
    return go_zone;
}

cv::Mat show_square_mesh(int **dims, bool *array_squares, cv::Mat image)
{
    // bool *array_squares = square_mesh(dims, image);
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

std::vector<float> getAngle(bool *go_zone_state, int first_row_len, int sq_size, int sq_margin, int screen_width, int sq_spacing)
{
    std::vector<float> angles;
    int angle;

    for (int i = 0; i<(first_row_len-4); i++)
    {
        if (((int)(go_zone_state[2+i])+(int)(go_zone_state[2+i+first_row_len-1])+(int)(go_zone_state[2+i+2*first_row_len-4])) <= 1)
        {
            angle = -90+((sq_margin+sq_size/2)+sq_spacing*(2+i))*180/screen_width;
            angles.push_back(angle);
        }
    }
    return angles;
}

int get_green_row(bool *go_zone_state, int first_row_len)
{
    int count = 0;
    for (int i=nr_squares - 1; i >= nr_squares - first_row_len; i--)
    {
        if (go_zone_state[i])
        {
            count++;
        }
    }

    if (count == first_row_len){
        return 3;
    }

    count = 0;

    for (int i=nr_squares - (first_row_len+1); i >= nr_squares - (2*first_row_len+2); i--)
    {
       if (go_zone_state[i])
        {
            count++;
        }
    }

    if (count == (first_row_len+2)){
        return 2;
    }

    count = 0;

    for (int i=nr_squares - (2*first_row_len+3); i >= 0; i--)
    {
        if (go_zone_state[i])
        {
            count++;
        }
    }

    if (count == (first_row_len+4)){
        return 1;
    }

    return 0;
}

/*
std::tuple<int,std::vector<float>> objectDetection(cv::Mat im)
{
    cv::Mat filtered_image, squares_image;

    // image = cv::imread("./../Data/cyberzoo_poles/2_original.jpg", 1);


    // filtered_image = filter_color(im, 70, 90, 100, 130, 100, 135, 1);

    int **squares = new int*[nr_squares];
    for (int h = 0; h < nr_squares; h++)
    {
        squares[h] = new int[3];
    }
    squares = gen_squares(im.rows, im.cols);

    bool *go_zone = new bool[nr_squares];
    go_zone = square_mesh(squares, im);

    int closest_green = get_green_row(go_zone, img_per_row-6);
    std::vector<float> angles = getAngle(go_zone, img_per_row, squares[0][2], squares[0][1], im.cols, squares[1][1]-squares[0][1]);

    // squares_image = show_square_mesh(squares, go_zone, im);

    // cv::namedWindow("Squares Image", cv::WINDOW_AUTOSIZE);
    // cv::imshow("Squares Image", squares_image);
    // cv::waitKey(0);

    return std::make_tuple(closest_green, angles);
}
*/

bool go_right(bool *go_zone_state){

	

	int green_right = 0;
	int green_left = 0;
	
	for (int i = 0; i < (int)((img_per_row)/2); i++){
		if (go_zone_state[i]){
			green_left++;
		}
	}
	
	for (int i = img_per_row; i < (int)(img_per_row + ((img_per_row-2))/2); i++){
		if (go_zone_state[i]){
			green_left++;
		}
	}
	
	for (int i = 2*img_per_row-2; i < (int)(2*img_per_row-2 + (img_per_row-4)/2); i++){
		if (go_zone_state[i]){
			green_left++;
		}
	}
	
	for (int i = 3*img_per_row-6; i < (int)(3*img_per_row-6 + (img_per_row-6)/2); i++){
		if (go_zone_state[i]){
			green_left++;
		}
	}
	
	for (int i = (int)((img_per_row)/2); i < img_per_row; i++){
		if (go_zone_state[i]){
			green_right++;
		}
	}
	
	for (int i = (int)(img_per_row + (img_per_row-2)/2); i < 2*img_per_row-2; i++){
		if (go_zone_state[i]){
			green_right++;
		}
	}
	
	for (int i = (int)(2*img_per_row-2 + (img_per_row-4)/2); i < 3*img_per_row-6; i++){
		if (go_zone_state[i]){
			green_right++;
		}
	}
	
	for (int i = (int)(3*img_per_row-6 + (img_per_row-6)/2); i < nr_squares; i++){
		if (go_zone_state[i]){
			green_right++;
		}
	}

	if (green_right >= green_left){
		return 1;
	}
	return 0;
}

cv::Mat rotate_image(cv::Mat non_rotated_image)
{
    cv::Mat new_image;
    double angle = 90;

    // get rotation matrix for rotating the image around its center in pixel coordinates
    cv::Point2f center((non_rotated_image.cols-1)/2.0, (non_rotated_image.rows-1)/2.0);
    cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
    // determine bounding rectangle, center not relevant
    cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), non_rotated_image.size(), angle).boundingRect2f();
    // adjust transformation matrix
    rot.at<double>(0,2) += bbox.width/2.0 - non_rotated_image.cols/2.0;
    rot.at<double>(1,2) += bbox.height/2.0 - non_rotated_image.rows/2.0;

    cv::warpAffine(non_rotated_image, new_image, rot, bbox.size());
    // cv::imwrite("rotated_im.png", new_image);
    // cv::namedWindow("Old Image", cv::WINDOW_AUTOSIZE);
    // cv::imshow("Old Image", non_rotated_image);
    // cv::namedWindow("New Image", cv::WINDOW_AUTOSIZE);
    // cv::imshow("New Image", new_image);
    // std::cout<<new_image.cols<<" "<<new_image.rows<<"\n";
    
    return new_image;
}

void objectDetection(char *im, int rows, int cols, float *output)
{
    cv::Mat old_image(rows, cols, CV_8UC2, im);
    cv::Mat image = rotate_image(image);

    // image = cv::imread("./../Data/cyberzoo_poles/2_original.jpg", 1);


    // filtered_image = filter_color(im, 70, 90, 100, 130, 100, 135, 1);

    int **squares = new int*[nr_squares];
    for (int h = 0; h < nr_squares; h++)
    {
        squares[h] = new int[3];
    }
    squares = gen_squares(rows, cols);

    bool *go_zone = new bool[nr_squares];
    go_zone = square_mesh(squares, image);
    
    bool goright = go_right(go_zone);

    int closest_green = get_green_row(go_zone, img_per_row-6);
    std::vector<float> angles = getAngle(go_zone, img_per_row, squares[0][2], squares[0][1], cols, squares[1][1]-squares[0][1]);

    // TODO Fill output vec
    output[0] = goright;
    output[1] = closest_green;

    for (int i=0; i<angles.size();i++)
    {
        output[i+2] = angles[i];
    }
    

    // squares_image = show_square_mesh(squares, go_zone, im);

    // cv::namedWindow("Squares Image", cv::WINDOW_AUTOSIZE);
    // cv::imshow("Squares Image", squares_image);
    // cv::waitKey(0);
}
