from importlib.resources import path
import os
import cv2
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import time
from pathlib import Path



# Data  Loading
def load_data(path_image_folder : path):
    dir_list = os.listdir(path_image_folder)

    for i,img_name in enumerate(dir_list):
        dir_list[i] = Path(img_name) 

    return dir_list

def get_nav_data(data_folder : path, file: path):

    file_path = data_folder / file
    nav_data = pd.read_csv(file_path)

    return nav_data

def get_time_stamps(img_list):
    time_lst = []
    for img in img_list:
        time_lst.append(float(img.stem)/10**6)
    time_lst = np.sort(time_lst)

    return time_lst

def interpolate_state(new_time : 'list[float]', data : pd.DataFrame):

    new_data = pd.DataFrame()
    new_data['time'] = new_time[:]
    old_time = data['time']

    for col in data.columns[1:]:
        new_data[col] = np.interp(new_time, old_time, data[col])

    return new_data


def get_single_image(image_nr : int, image_dir_name : Path, graphics=True):
    
    image_name = Path(str(image_nr))
    path_to_image = image_dir_name / image_name

    _bgr = cv2.imread(str(path_to_image))

    if type(_bgr) != np.ndarray:
        raise TypeError('Wrong parsing of the iamge file! Check its name: ', path_to_image.name)
    bgr = cv2.rotate(_bgr, cv2.cv2.ROTATE_90_COUNTERCLOCKWISE)

    if graphics:
        plt.figure()
        plt.imshow(bgr)
        plt.title('Image, nr ' + str(image_nr))

    return bgr


