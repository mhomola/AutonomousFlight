import numpy as np
import cv2
import matplotlib.pyplot as plt
import utils
import time
from pathlib import Path
import OF_core

'''                        Globals                                     '''
data_folder  = Path('Data') / Path('cyberzoo_poles')
image_folder = Path(data_folder/'20190121-135009' )
nav_file     = Path('20190121-135121.csv')

vizualize_flow = True

def main():
    id = 100    # picture id in the ordered list 
    # Change the numbers utils the images for answering the questions:
    img_list     = utils.load_data(image_folder)
    
    # Load & Interpoalte drone-state data:
    nav_data_raw = utils.get_nav_data(data_folder, nav_file)
    time_lst     = utils.get_time_stamps(img_list)
    nav_data     = utils.interpolate_state(time_lst, nav_data_raw)
    print('Drone state: \n',nav_data.iloc[[id]])

    # Load images:
    prev_bgr = utils.get_single_image(img_list[id], image_dir_name = image_folder, graphics = False)
    bgr      = utils.get_single_image(img_list[id+1], image_dir_name = image_folder, graphics = False)
    
    # Calaucalte OF for both hemishperes:
    subsampling_factor = 1    
    lk_params = dict(winSize=(21, 21), maxLevel=2,\
         criteria=(cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT,\
         10, 0.03))
    params = dict(lk_params = lk_params, subsampling = subsampling_factor)

    t0 = get_flow_command(prev_bgr, bgr, params)

    # Time Analysis part:
    bgr_lst = []
    num_imgs = 50
    for _id in range(id,id + num_imgs+1):
        _bgr = utils.get_single_image(img_list[_id], image_dir_name = image_folder, graphics = False)
        bgr_lst.append(_bgr)

    time_analysis_subsampling(bgr_lst, params, num_imgs = num_imgs)
    # time_analysis_winSize(bgr_lst, params, num_imgs = num_imgs)
    # time_analysis_maxLevel(img_list, lk_params, num_imgs = 5)


    # Check for time improvements:
    print(f'Time ellapsed: {time.time() - t0} s')

    # Show full OF on image:
    if vizualize_flow:
        _,_,flow_vectors_l = OF_core.show_flow(prev_bgr, bgr,\
            dense = True, graphics = True, params = params)

def get_flow_command(prev_bgr, bgr, params):

    # Split image horizontally in 2 hemishperes:
    height, width = prev_bgr.shape[:2]
    prev_bgr_l = prev_bgr[:,:width//2]
    prev_bgr_r = prev_bgr[:,width//2:]
    bgr_l = bgr[:,:width//2]
    bgr_r = bgr[:,width//2:]


    # NOTE keep graphics= False since half-iamges are not very interesting but still slow
    t0 = time.time()   #start timer
    _,_,flow_vectors_l = OF_core.show_flow(prev_bgr_l, bgr_l,\
         dense = True, graphics = False, params = params)
    _,_,flow_vectors_r = OF_core.show_flow(prev_bgr_r, bgr_r,\
         dense = True, graphics = False, params = params)

    # Get heading change command:
    OF_core.calc_heading_com(flow_vectors_l, flow_vectors_r)
    return t0

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#                                       Time Analysis
# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
def time_analysis_subsampling(img_lst, params : dict, num_imgs : int = 5):
    """ Time versus varying Window Size.
    """
    time_lst,plotting_lst = [],[]
    subsampling_lst = range(1,11)

    for i,f in enumerate(subsampling_lst):
        params['subsampling'] = f
        print(f)
        t0 = time.time()
        for id in range(num_imgs):
            get_flow_command(img_lst[id],img_lst[id+1], params=params)
        
        time_lst.append((time.time() - t0)/num_imgs)
        plotting_lst.append(1/f) 

    fig,ax = plt.subplots()
    ax.set_title(f'Time Complexity Analysis')
    plt.plot(plotting_lst, time_lst)
    ax.set_xlabel('Subsampling Factor [-]')
    ax.set_ylabel('Avg. Time [s]')

def time_analysis_winSize(img_lst, params : dict, num_imgs : int = 5):
    """ Time versus varying Window Size.
    """
    time_lst = []
    win_size_lst = range(5,100,10)

    
    for win_size in win_size_lst:
        params['winSize'] = (win_size, win_size)

        t0 = time.time()
        for id in range(num_imgs):
            get_flow_command(img_lst[id],img_lst[id+1], params=params)

        time_lst.append((time.time() - t0)/num_imgs)

    fig,ax = plt.subplots()
    ax.set_title(f'Time Complexity Analysis - {num_imgs} samples average')
    plt.plot(win_size_lst, time_lst)
    ax.set_xlabel('Window Size [pixels]')
    ax.set_ylabel('Avg. Time [s]')


def time_analysis_maxLevel(img_lst, params : dict, num_imgs : int = 5):
    """ Time versus varying Maximum Level of Pyramid depth.
    """
    time_lst = []
    param_lst = range(0,12)

    for v in param_lst:
        # change the looping paramter
        params['maxLevel'] = v
        t0 = time.time()
        for id in range(num_imgs):
            OF_core.show_flow(img_lst[id], img_lst[id+1], dense = True,\
                    graphics = False, params = params)
    
        time_lst.append((time.time() - t0)/num_imgs)

    fig,ax = plt.subplots()
    ax.set_title(f'Time Complexity Analysis - {num_imgs} samples average')
    plt.plot(param_lst, time_lst)
    ax.set_xlabel('Pyramid Levels [-]')
    ax.set_ylabel('Avg. Time [s]')
    plt.tight_layout()



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

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#                                       De-rotation
# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

def correct_rot(id, nav_data, height, width, flow_vectors_l, flow_vectors_r):

    # Calcualte rotational flow:
    x_ar = np.arange(0,width)
    y_ar = np.arange(0,height)
    u_r = np.zeros((width,height))
    v_r = np.zeros((width,height))
    p = nav_data['rate_p'][id]
    q = nav_data['rate_q'][id]
    r = nav_data['rate_r'][id]
    
    for x in x_ar:
        for y in y_ar:
            u_r[x,y], v_r[x,y] = calc_rot_flow(x,y,p,q,r)
    rot_flow = np.concatenate((u_r,v_r)).reshape(height, width, 2)

    # Corect for rotation:
    flow_vectors_l = flow_vectors_l - rot_flow[:,:width//2,:]
    flow_vectors_r = flow_vectors_r - rot_flow[:,width//2:,:]
    return flow_vectors_l,flow_vectors_r



def calc_rot_flow(x ,y , A = 0. ,B = 0.,C = 0.):
    """ Working progress."""
    u_r = A * x * y - B*x**2 - B + C*y
    v_r = -C * x + A + A * y**2 - B*x*y

    return u_r, v_r


if __name__ == '__main__':
    main()
    plt.show()
    print('Done!')