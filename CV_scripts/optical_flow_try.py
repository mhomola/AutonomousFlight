import numpy as np
import cv2
import matplotlib.pyplot as plt
import utils
import time


'''                        Globals                                     '''
data_folder = r'Data\cyberzoo_poles'
image_folder = str(data_folder + r'\20190121-135009' )
nav_file = r'\20190121-135121.csv'


def main():
    id = 50 # picture id in the ordered list 

    # Change the numbers utils the images for answering the questions:
    img_list     = utils.load_data(image_folder)
    
    # Load & Interpoalte drone-state data:
    nav_data_raw = utils.get_nav_data(data_folder, nav_file)
    time_lst = utils.get_time_stamps(img_list)
    nav_data = utils.interpolate_state(time_lst, nav_data_raw)
    print('Drone state: \n',nav_data.iloc[[id]])

    # Load images:
    prev_bgr = utils.get_single_image(img_list[id], image_dir_name = image_folder, graphics = False)
    bgr = utils.get_single_image(img_list[id+1], image_dir_name = image_folder, graphics = False)
    

    # Split image horizontally in 2 hemishperes:
    height, width = prev_bgr.shape[:2]
    prev_bgr_l = prev_bgr[:,:width//2]
    prev_bgr_r= prev_bgr[:,width//2:]
    bgr_l = bgr[:,:width//2]
    bgr_r = bgr[:,width//2:]

    # Calaucalte OF for both hemishperes:
    lk_params = dict(winSize=(21, 21), maxLevel=2,\
         criteria=(cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT, 10, 0.03))
    # # keep graphics= False ssince half-iamges are not very interesting but still slow
    t0 = time.time()   #start timer
    _,_,flow_vectors_l = utils.show_flow(prev_bgr_l, bgr_l,\
         dense = True, graphics = False, params = lk_params)
    _,_,flow_vectors_r = utils.show_flow(prev_bgr_r, bgr_r,\
         dense = True, graphics = False, params = lk_params)

    # Get heading change command:
    utils.calc_heading_com(flow_vectors_l, flow_vectors_r)

    # Check for time improvements:
    print(f'Time ellapsed: {time.time() - t0} s')

    # Show full OF on image:
    _,_,flow_vectors_l = utils.show_flow(prev_bgr, bgr,\
         dense = True, graphics = True, params = lk_params)


    # Time Analysis part:
    # time_analysis_winSize(img_list, lk_params, num_imgs = 5)
    # time_analysis_maxLevel(img_list, lk_params, num_imgs = 5)
    # points_old, flow_vectors, pu, pv = simple_OF_fit(prev_bgr, bgr)


def time_analysis_winSize(img_list, lk_params,num_imgs : int = 10):
    """ Time versus varying Window Size.
    """
    time_lst = []
    win_size_lst = range(5,100,10)

    for win_size in win_size_lst:
        lk_params['winSize'] = (win_size, win_size)

        t0 = time.time()
        for id in range(100,100 + num_imgs,1):
            utils.show_flow(img_list[id], img_list[id+1],\
                image_folder,'', image_type = '', dense = True,\
                    graphics = False, params = lk_params)

        time_lst.append((time.time() - t0)/num_imgs)

    fig,ax = plt.subplots()
    ax.set_title('Time Complexity - analysis')
    plt.plot(win_size_lst, time_lst)
    ax.set_xlabel('Window Size [pixels]')
    ax.set_ylabel('Avg. Time [s]')


def time_analysis_maxLevel(img_list, lk_params, num_imgs = 10):
    """ Time versus varying Maximum Level of Pyramid depth.
    """
    time_lst = []
    param_lst = range(0,12)

    for v in param_lst:
        lk_params['maxLevel'] = v
        t0 = time.time()
        for id in range(100,100 + num_imgs,1):
            utils.show_flow(img_list[id], img_list[id+1],\
                image_folder,'', image_type = '', dense = True,\
                    graphics = False, params = lk_params)
        
        time_lst.append((time.time() - t0)/num_imgs)

    fig,ax = plt.subplots()
    ax.set_title('Time Complexity - analysis')
    plt.plot(param_lst, time_lst)
    ax.set_xlabel('Pyramid Levels [-]')
    ax.set_ylabel('Avg. Time [s]')



def simple_OF_fit(prev_bgr, bgr, plotting = True):

    # LS fit of OF for 2 iamges
    points_old, points_new, flow_vectors = utils.show_flow(prev_bgr,bgr)

    n_points   = points_old.shape[0]
    pu, errs_u = utils.get_flow_fit(n_points, points_old[:,0], flow_vectors[:,0])
    pv, errs_v = utils.get_flow_fit(n_points, points_old[:,1], flow_vectors[:,1])
    error      = (np.mean(errs_u) + np.mean(errs_v)) / 2.0    # total error

    if plotting:
        # Plot the fit:
        plt.figure()
        plt.plot(points_old[:,0], flow_vectors[:,0], 'x');
        
        min_x = np.min(points_old[:,0]);
        u_min_x = np.dot(np.asarray([min_x, 1]).reshape(1,2), pu);
        max_x = np.max(points_old[:,0]);
        u_max_x = np.dot(np.asarray([max_x, 1]).reshape(1,2), pu);

        plt.plot([min_x, max_x], [u_min_x, u_max_x], 'r');
        plt.xlabel('x [px]');
        plt.ylabel('u [px]');
        plt.title('Horizontal flow fit')

        
        # Plot the fit:
        plt.figure()
        plt.plot(points_old[:,1], flow_vectors[:,1], 'x');
        min_y = np.min(points_old[:,1]);
        v_min_y = np.dot(np.asarray([min_y, 1]).reshape(1,2), pv);
        max_y = np.max(points_old[:,1]);
        v_max_y = np.dot(np.asarray([max_y, 1]).reshape(1,2), pv);
        plt.plot([min_y, max_y], [v_min_y, v_max_y], 'r');
        plt.xlabel('y [px]');
        plt.ylabel('v [px]');
        plt.title('Vertical flow fit')


    return points_old,flow_vectors,pu,pv




if __name__ == '__main__':
    main()
    plt.show()
    print('Done!')