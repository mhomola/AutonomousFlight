# matplotlib inline
from typing import List, Any

import cv2
import numpy as np
import matplotlib.pyplot as plt
import os
import re
import time
import sys
import pandas as pd
import utils

image_folder = os.getcwd() + '/../Data/cyberzoo_poles/20190121-135009'
FoV = 180  # deg


def filter_color(im, y_low=50, y_high=200, u_low=120, u_high=130, v_low=120, v_high=130, resize_factor=3):
    """"
    This is a piece of code inspired by the Binder example code for filtering the ground color from an image.
    The inputs are the image and the YUV bounds needed for color filtration. resize_factor resizes the image pixel-wise.
    The output is a filtered image.
    """

    im = cv2.resize(im, (int(im.shape[1] / resize_factor), int(im.shape[0] / resize_factor)))   # Image to be considered
    imred = im[int(im.shape[0] * 0.45):im.shape[0], :, :]                                       # Cropping the image
    YUV = cv2.cvtColor(imred, cv2.COLOR_BGR2YUV)
    Filtered = np.zeros([YUV.shape[0], YUV.shape[1]])

    # YUV filtering
    for y in range(YUV.shape[0]):
        for x in range(YUV.shape[1]):
            if (y_low <= YUV[y, x, 0] <= y_high and
                    u_low <= YUV[y, x, 1] <= u_high and
                    v_low <= YUV[y, x, 2] <= v_high):
                Filtered[y, x] = 1

    plt.figure()
    RGB = cv2.cvtColor(im, cv2.COLOR_BGR2RGB)
    plt.imshow(RGB)
    plt.title('Original image')
    # plt.show()

    plt.figure()
    plt.imshow(Filtered)
    plt.title('Filtered image')
    # plt.show()

    return (Filtered)


def filter_color_square(sq, y_low=50, y_high=200, u_low=120, u_high=130, v_low=120, v_high=130, resize_factor=1,
                        passFactor=0.5):
    """"
    This is a function for filtering the ground in the squares. The input is a certain square patch of the image and YUV
    parameters. The color is then filtered and averaged. Furthermore, a certain pass factor is chosen, which determines how
    much % of pixels needs to fall within a certain band of colors to be considered a "go" zone. An output is a boolean
    with the following meaning: True = squared passed filtration, False = square didn't pass filtration
    """

    sq = cv2.resize(sq, (int(sq.shape[1] / resize_factor), int(sq.shape[0] / resize_factor))) # Square section of the image to be considered
    YUV = cv2.cvtColor(sq, cv2.COLOR_BGR2YUV)
    Filtered = np.zeros([YUV.shape[0], YUV.shape[1]])

    # YUV filtering
    for y in range(YUV.shape[0]):
        for x in range(YUV.shape[1]):
            if (y_low <= YUV[y, x, 0] <= y_high and
                    u_low <= YUV[y, x, 1] <= u_high and
                    v_low <= YUV[y, x, 2] <= v_high):
                Filtered[y, x] = 1

    avgsum = np.sum(Filtered) / np.size(Filtered)   # Checking how many % of the pixels in the square belong within the YUV bounds
    return avgsum >= passFactor                     # Checking whether the % of pixels belonging to the YUV bounds exceeds the required pass factor


def go_decision(Filtered):
    """"
    This is a function for evaluating which directions to go. If more ground is sensed on the right side, the drone
    will go right, and vice versa. The input is an image with filtered ground. The output is a boolean, with the following
    meaning: True = go right / False = go left.
    """

    sumRight = np.sum(Filtered[int(Filtered.shape[0] / 2):Filtered.shape[0],
                      int(Filtered.shape[1] / 2):Filtered.shape[1]])            # Summation of the green squares on the right
    sumLeft = np.sum(Filtered[int(Filtered.shape[0] / 2):Filtered.shape[0],
                     0:np.sum(int(Filtered.shape[1] / 2))])                     # Summation of the green squares on the left

    if sumRight < sumLeft:
        return False
    return True


def gen_squares(image_d1, image_d2):
    """"
    This function creates a mesh of squares within an image shot by camera. The idea is select patches of the image
    to be considered, so that the drone does not evaluate all the pixels within the image. Therefore, sufficient
    images should be considered to represent the image adequatly, but too many as to avoid an expensive algorithm.

    The inputs are the dimension of the image in height (image_d1) and in length (image_d2). The output is an array
    of the pixel location and size of the "patches" within an image.
    """

    row_num = 4                     # Number of rows
    sq_size = int(image_d2 / 40)    # Size of a square (in pixels)
    img_per_row = 20                # Number of squares in the bottom row

    dimensions = []                 # Array to store the position and size of the squares

    for i in range(row_num):
        base_dim1_t = image_d1 - 2 * (i + 1) * sq_size
        base_dim2 = (image_d2 / (img_per_row + 2))
        for j in range(img_per_row - 2 * i):
            base_dim2_t = int((j + i + 1.5) * base_dim2 - sq_size / 2)
            dimensions.append([base_dim1_t, base_dim2_t, sq_size])

    return dimensions, img_per_row


def is_carpet(pixel, image):
    """
    Function is used to see if red squares (called pixels in the program) are actually a carpet (so they should become
    green) or not; it assumes that between the pixel and 60% height of the image (this value was considered high enough
    to be above the horizon but also low enough for saving computational time) there is a space of grass which should be
    find by checking pixels going up the image.
    Args:
        pixel: (array) the square dimensions ([height (240 -> 0), width (0->520), square size])
        image: (int) the image processed (it is used only for getting its height)

    Returns: (bool) true = carpet; false = obstacle
    """
    height = int(len(image) * 0.4)
    index = pixel[0]  # starting height of the pixel
    status = False  # used to check if a grass line between borders of the grass and carpet can be found
    while index > height and not status:  # stop if a grass area was found or you bypassed the required height
        index -= 10  # Move the square 10 pixels (actual pixels of the image this time) up
        img = image[int(index):int(index + pixel[2]), int(pixel[1]):int(pixel[1] + pixel[2])]  # Build square
        go_zone = filter_color_square(img, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135)  # Check
        if go_zone:  # If a grass area was found stop the while loop and return the result to plot the square
            status = True
    return status


def square_mesh(dims, image):
    """"
    This function takes the (pixel) locations and sizes of squares to be considered withing the image and an image
    itself. It returns the imagine with the regions colored based on whether the zone is free to go or not (i.e. an
    obstacle stands in the way). Green square = go zone, Red square = no-go zone
    """

    size = dims[0][2]  # Size of one "test" square

    go_zone = []

    for i in range(len(dims[:])):

        """"
        This for cycle loops through all of the squares and examines whether they are of the ground color. If they are
        (or if they are a carpet), it colors them green within the image. If they are not, it colors them red. 
        """

        img = image[int(dims[i][0]):int(dims[i][0] + size), int(dims[i][1]):int(dims[i][1] + size)]
        go_zone.append(filter_color_square(sq=img, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135) or
                       is_carpet(dims[i], image)) # Checking the color of the squares

        if go_zone[i]:  # Coloring is performed here
            image[int(dims[i][0]):int(dims[i][0] + size), int(dims[i][1]):int(dims[i][1] + size), :] = [0, 255, 0]
        elif is_carpet(dims[i], image):
            image[int(dims[i][0]):int(dims[i][0] + size), int(dims[i][1]):int(dims[i][1] + size), :] = [0, 255, 0]
        else:
            image[int(dims[i][0]):int(dims[i][0] + size), int(dims[i][1]):int(dims[i][1] + size), :] = [0, 0, 255]

    return image, go_zone


def getAngle(go_zone_state,first_row_len, sq_size, sq_margin, screen_width, sq_spacing):

    """"
    Function for angle detection of obstacles, which returns the angles at which the obstacles are detected.
    The idea is that it goes through the columns of the square grid that contain at least 3 squares. If at least two of
    bottom 3 squares are red, this is considered to be an obstacle. The angle is estimated based on the knowledge
    of the position of the squares within the image and the field of view of the image. It is assumed that the angles
    between the squares are linearly spaced. This might not be 100% accurate, but it is sufficient for the navigation
    of the drone.
    """
    angles = []
    for i in range(first_row_len-4):
        if (int(go_zone_state[2+i])+int(go_zone_state[2+i+first_row_len-1])+int(go_zone_state[2+i+2*first_row_len-4])) <= 1:
            angles.append(-np.pi/2+((sq_margin+sq_size/2)+sq_spacing*(2+i))*np.pi/screen_width) # Angle estimate calculation

    return angles

def get_green_row(go_zone_state, first_row_len):

    """"
    This algorithm iterates through the rows of the squares grid and it checks whether a row is full of green squares.
    The algorithm evaluates each row to examine whether it contains only green squares or not.
    The further the row containing only green squares is from the bottom of the image, the more confidence can be put
    into the motion of the drone, as no obstacles are detected nearby. This means, for example, that the drone can speed
    up and thus cover more distance in the limited time.

    The rows are checked from the top to the bottom. If no red squares are detected in the row, the id of this row is
    output and no further rows are considered. The reason for skipping the rest of the rows is that all the obstacles
    in Cyberzoo are vertical, therefore, if an obstacle is not detected in a top row, it is not likely it will be
    detected in a bottom row.

    The ids are asssigned as follows:

    Top row: 0
    2nd row from top: 1
    3rd row from top: 2
    Bottom row: 3
    """

    if go_zone_state[-1:-first_row_len]:                            # Top row
        return 0
    elif go_zone_state[-(first_row_len+1):-(2*first_row_len+2)]:    # 2nd row from top
        return 1
    elif go_zone_state[-(2*first_row_len+3):-(2*first_row_len+4)]:  # 3rd row from top
        return 2
    return 3                                                        # Bottom top


def main():
    # Image loading
    # id = 75
    # img_list = utils.load_data(image_folder)
    # image1 = utils.get_single_image(img_list[id], image_dir_name = image_folder, graphics=False)

    image = cv2.imread(os.getcwd() + './../Data/cyberzoo_poles/2_original.jpg')
    print(np.shape(image))

    # Decision based on amount of pixels
    Filtered = filter_color(im=image, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135)
    DecisionRight = go_decision(Filtered)
    print('Decision RIGHT status: ', DecisionRight)

    # Square definition
    # dims = [200,400,20]
    dims = gen_squares(image.shape[0], image.shape[1])[0]
    sq_per_row = gen_squares(image.shape[0], image.shape[1])[1]
    # Square testing

    meshed_image = square_mesh(dims, image)
    # goZone = filter_color_square(sq = square, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135)

    # if goZone:
    #    image[dims[0]:dims[0]+dims[2],dims[1]:dims[1]+dims[2],:] = [0, 255, 0]
    # else:
    #    image[dims[0]:dims[0]+dims[2],dims[1]:dims[1]+dims[2],:] = [0, 0, 255]
    print(dims)

    obstacle = get_green_row(meshed_image[1],sq_per_row)
    print("row: ", 4-obstacle)

    angles = getAngle(meshed_image[1], sq_per_row, dims[0][2], dims[0][1], len(image[0][:]), dims[1][1]-dims[0][1])
    print(meshed_image[1], sq_per_row, dims[0][2], dims[0][1], len(image[0][:]), dims[1][1]-dims[0][1])
    print(angles)

    plt.figure()
    RGB = cv2.cvtColor(meshed_image[0], cv2.COLOR_BGR2RGB)
    plt.imshow(RGB)
    plt.xlabel('Pixels in x-direction [-]')
    plt.ylabel('Pixels in y-direction [-]')
    plt.title('Filtered image')
    plt.rcParams.update({'font.size': 32})
    plt.show()

if __name__ == '__main__':
    main()
    plt.show()
