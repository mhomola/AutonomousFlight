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


#data_folder = r'Data\cyberzoo_poles'
#image_folder = str(data_folder + r'\20190121-135009' )
image_folder = r'C:\Users\mhomo\OneDrive\Dokumenty\University\GitHub\AutonomousFlight\CV_scripts\Data\cyberzoo_poles\20190121-135009'
#print('folder',image_folder)


def filter_color(im, y_low=50, y_high=200, u_low=120, u_high=130, v_low=120, v_high=130, resize_factor=1):
    #im = icv2.imread(image_name)
    im = cv2.resize(im, (int(im.shape[1] / resize_factor), int(im.shape[0] / resize_factor)))
    YUV = cv2.cvtColor(im, cv2.COLOR_BGR2YUV)
    Filtered = np.zeros([YUV.shape[0], YUV.shape[1]])
    for y in range(YUV.shape[0]):
        for x in range(YUV.shape[1]):
            if (y_low <= YUV[y, x, 0] <= y_high and
                    u_low <= YUV[y, x, 1] <= u_high and
                    v_low <= YUV[y, x, 2] <= v_high):
                Filtered[y, x] = 1

    print('got here')

    plt.figure()
    RGB = cv2.cvtColor(im, cv2.COLOR_BGR2RGB)
    plt.imshow(RGB)
    plt.title('Original image')
    plt.show()

    plt.figure()
    plt.imshow(Filtered)
    plt.title('Filtered image')
    plt.show()

def main():
    id = 75
    img_list = utils.load_data(image_folder)
    print(len(img_list))
    print("got here 2")
    image = utils.get_single_image(img_list[id], image_dir_name = image_folder, graphics=False)
    filter_color(im = image, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135)
    print("Done")

if __name__ == '__main__':
    main()
    plt.show()
    print('Done!')