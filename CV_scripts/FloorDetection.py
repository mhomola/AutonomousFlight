#matplotlib inline
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
    #imred = im[int(im.shape[0]/2):im.shape[0], int(im.shape[1]/2):im.shape[1],:]
    YUV = cv2.cvtColor(im, cv2.COLOR_BGR2YUV)
    Filtered = np.zeros([YUV.shape[0], YUV.shape[1]])
    print(YUV.shape[0]/3)
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


def filter_color_square(sq, y_low=50, y_high=200, u_low=120, u_high=130, v_low=120, v_high=130, resize_factor=3, passFactor = 0.6):

    sq = cv2.resize(sq, (int(sq.shape[1] / resize_factor), int(sq.shape[0] / resize_factor)))
    YUV = cv2.cvtColor(sq, cv2.COLOR_BGR2YUV)
    Filtered = np.zeros([YUV.shape[0], YUV.shape[1]])
    print(YUV.shape[0] / 3)
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

def gen_squares():



    return None

def main():

    # Image loading
    id = 75
    img_list = utils.load_data(image_folder)
    image = utils.get_single_image(img_list[id], image_dir_name = image_folder, graphics=False)

    # Square definition
    dims = [50,50,20]

    # Decision based on amount of pixels
    Filtered = filter_color(im = image, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135)
    DecisionRight = go_decision(Filtered)
    print('Decision RIGHT status: ', DecisionRight)

    # Square testing
    square = image[dims[0]:dims[0]+dims[2],dims[1]:dims[1]+dims[2],:]
    print('sqshape',square.shape)
    goZone = filter_color_square(sq = square, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135)

    if goZone:
        image[dims[0]:dims[0]+dims[2],dims[1]:dims[1]+dims[2],:] = [0, 255, 0]
    else:
        image[dims[0]:dims[0]+dims[2],dims[1]:dims[1]+dims[2],:] = [0, 0, 255]

    plt.figure()
    RGB = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    plt.imshow(RGB)
    plt.title('Original image')
    print(image)
    plt.show()

if __name__ == '__main__':
    main()
    plt.show()
