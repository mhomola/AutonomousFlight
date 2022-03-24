"""
Created on Wed Mar 07 10:46:05 2018

Script that can be run on a directory, calculates optical flow and extracts useful information from the flow field.

@author: Guido de Croon.
"""



if __name__ == '__main__':        
    # extract_flow_information(image_dir_name = './images_landing/', image_type = 'png', verbose=True, graphics = True, flow_graphics = True);
    # Change flow_gaphics to True in order to see images and optical flow:
    extract_flow_information(flow_graphics=False)
