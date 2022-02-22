import numpy as np
import cv2
import matplotlib.pyplot as plt
import utils


data_folder = r'Data\cyberzoo_poles'
image_folder = str(data_folder + r'\20190121-135009' )
nav_file = r'\20190121-135121.csv'
id1= 100
id2 = 200

def main():
    
    # Change the numbers utils the images for answering the questions:
    
    img_list = utils.load_data(image_folder)
    nav_data = utils.get_time_stamps(data_folder, nav_file)
    delta_t = nav_data['time'][id2] - nav_data['time'][id1]
    freq = (nav_data['time'][1:] - nav_data['time'][:-1])
    
    print(f'Average sampling freq: {freq}')
    print(f'Time between shots: {delta_t:0.2f} s')

    
    points_old, points_new, flow_vectors = utils.show_flow(img_list[id1], img_list[id2],\
        image_folder,'', image_type = '')

    n_points = points_old.shape[0];

    # make a matrix A with elements [x,1] 
    A_hor = np.concatenate((points_old[:,0].reshape(n_points,1), np.ones([points_old.shape[0], 1])), axis=1);
    # Moore-Penrose pseudo-inverse:
    # https://en.wikipedia.org/wiki/Moore%E2%80%93Penrose_inverse
    pseudo_inverse_A_hor = np.linalg.pinv(A_hor);
    # target = horizontal flow:
    u_vector = flow_vectors[:,0];
    # solve the linear system:
    pu = np.dot(pseudo_inverse_A_hor, u_vector);
    # calculate how good the fit is:
    errs_u = np.abs(np.dot(A_hor, pu) - u_vector);

    # Plot the fit:
    plt.figure();
    plt.plot(points_old[:,0], flow_vectors[:,0], 'x');
    min_x = np.min(points_old[:,0]);
    u_min_x = np.dot(np.asarray([min_x, 1]).reshape(1,2), pu);
    max_x = np.max(points_old[:,0]);
    u_max_x = np.dot(np.asarray([max_x, 1]).reshape(1,2), pu);
    plt.plot([min_x, max_x], [u_min_x, u_max_x], 'r');
    plt.xlabel('x [px]');
    plt.ylabel('u [px]');
    plt.title('Horizontal flow fit')

    # make a matrix A with elements [y,1]
    A_ver = np.concatenate((points_old[:,1].reshape(n_points,1), np.ones([points_old.shape[0], 1])), axis=1);
    # Moore-Penrose pseudo-inverse:
    # https://en.wikipedia.org/wiki/Moore%E2%80%93Penrose_inverse
    pseudo_inverse_A_ver = np.linalg.pinv(A_ver);
    # target = vertical flow:
    v_vector = flow_vectors[:,1];
    pv = np.dot(pseudo_inverse_A_ver, v_vector);
    errs_v = np.abs(np.dot(A_ver, pv) - v_vector);
    err = (np.mean(errs_u) + np.mean(errs_v)) / 2.0;

    # Plot the fit:
    plt.figure();
    plt.plot(points_old[:,1], flow_vectors[:,1], 'x');
    min_y = np.min(points_old[:,1]);
    v_min_y = np.dot(np.asarray([min_y, 1]).reshape(1,2), pv);
    max_y = np.max(points_old[:,1]);
    v_max_y = np.dot(np.asarray([max_y, 1]).reshape(1,2), pv);
    plt.plot([min_y, max_y], [v_min_y, v_max_y], 'r');
    plt.xlabel('y [px]');
    plt.ylabel('v [px]');
    plt.title('Vertical flow fit');

    

if __name__ == '__main__':
    main()
    plt.show()
    print('Done!')