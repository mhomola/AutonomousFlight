#matplotlib inline
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

def filter_color(im, y_low=50, y_high=200, u_low=120, u_high=130, v_low=120, v_high=130, resize_factor=3):

    im = cv2.resize(im, (int(im.shape[1] / resize_factor), int(im.shape[0] / resize_factor)))
    imred = im[int(im.shape[0]*0.45):im.shape[0],:,:]
    YUV = cv2.cvtColor(imred, cv2.COLOR_BGR2YUV)
    Filtered = np.zeros([YUV.shape[0], YUV.shape[1]])

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
    plt.show()

    plt.figure()
    plt.imshow(Filtered)
    plt.title('Filtered image')
    plt.show()

    return(Filtered)


def filter_color_square(sq, y_low=50, y_high=200, u_low=120, u_high=130, v_low=120, v_high=130, resize_factor=1, passFactor = 0.4):

    sq = cv2.resize(sq, (int(sq.shape[1] / resize_factor), int(sq.shape[0] / resize_factor)))
    YUV = cv2.cvtColor(sq, cv2.COLOR_BGR2YUV)
    Filtered = np.zeros([YUV.shape[0], YUV.shape[1]])

    for y in range(YUV.shape[0]):
        for x in range(YUV.shape[1]):
            if (y_low <= YUV[y, x, 0] <= y_high and
                    u_low <= YUV[y, x, 1] <= u_high and
                    v_low <= YUV[y, x, 2] <= v_high):
                Filtered[y, x] = 1

    avgsum = np.sum(Filtered)/np.size(Filtered)
    return avgsum >= passFactor


def go_decision(Filtered):
    sumRight = np.sum(Filtered[int(Filtered.shape[0]/2):Filtered.shape[0],
                      int(Filtered.shape[1]/2):Filtered.shape[1]])
    sumLeft = np.sum(Filtered[int(Filtered.shape[0]/2):Filtered.shape[0],
                      0:np.sum(int(Filtered.shape[1]/2))])

    if sumRight < sumLeft:
        return False
    return True


def gen_squares(image_d1,image_d2):

    row_num = 4
    sq_size = int(image_d2/40)
    img_per_row = 20

    dimensions = []

    for i in range(row_num):
        base_dim1_t = image_d1 - 2*(i+1)*sq_size
        base_dim2 = (image_d2/(img_per_row+2))
        for j in range(img_per_row-2*i):
            base_dim2_t = int((j+i+1.5)*base_dim2 - sq_size/2)
            dimensions.append([base_dim1_t, base_dim2_t, sq_size])


    return dimensions

def square_mesh(dims, image):

    size = dims[0][2]

    for i in range(len(dims[:])):

        img = image[int(dims[i][0]):int(dims[i][0] + size), int(dims[i][1]):int(dims[i][1] + size)]
        go_zone = filter_color_square(sq=img, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135)

        if go_zone:
            image[int(dims[i][0]):int(dims[i][0]+size),int(dims[i][1]):int(dims[i][1]+size), :] = [0, 255, 0]
        else:
            image[int(dims[i][0]):int(dims[i][0]+size),int(dims[i][1]):int(dims[i][1]+size), :] = [0, 0, 255]

    return image

def main():

    # Image loading
    id = 75
    img_list = utils.load_data(image_folder)
    image = utils.get_single_image(img_list[id], image_dir_name = image_folder, graphics=False)

    # Decision based on amount of pixels
    Filtered = filter_color(im=image, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135)
    DecisionRight = go_decision(Filtered)
    print('Decision RIGHT status: ', DecisionRight)


    # Square definition
    #dims = [200,400,20]
    dims = gen_squares(image.shape[0], image.shape[1])
    # Square testing

    meshed_image = square_mesh(dims, image)
    #goZone = filter_color_square(sq = square, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135)

    #if goZone:
    #    image[dims[0]:dims[0]+dims[2],dims[1]:dims[1]+dims[2],:] = [0, 255, 0]
    #else:
    #    image[dims[0]:dims[0]+dims[2],dims[1]:dims[1]+dims[2],:] = [0, 0, 255]

    plt.figure()
    RGB = cv2.cvtColor(meshed_image, cv2.COLOR_BGR2RGB)
    plt.imshow(RGB)
    plt.title('Original image')
    plt.show()

if __name__ == '__main__':
    main()
    plt.show()
