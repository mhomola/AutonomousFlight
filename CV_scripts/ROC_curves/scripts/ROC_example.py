from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
import sys
import warnings
import cv2

if sys.version_info[0] < 3:
    warnings.warn("This script should run using Python 3, which is currently not the case. The plot might not generate correctly.")

path = './../ROC_dataset/'


def filter_color(im, y_low=50, y_high=200, u_low=120, u_high=130, v_low=120, v_high=130, resize_factor=3):
    """"
    This is a piece of code inspired by the Binder example code for filtering the ground color from an image.
    The inputs are the image and the YUV bounds needed for color filtration. resize_factor resizes the image pixel-wise.
    The output is a filtered image.
    """

    im = cv2.resize(im, (int(im.shape[1] / resize_factor), int(im.shape[0] / resize_factor)))
    imred = im[int(im.shape[0] * 0.45):im.shape[0], :, :]
    YUV = cv2.cvtColor(imred, cv2.COLOR_BGR2YUV)
    Filtered = np.zeros([YUV.shape[0], YUV.shape[1]])

    for y in range(YUV.shape[0]):
        for x in range(YUV.shape[1]):
            if (y_low <= YUV[y, x, 0] <= y_high and
                    u_low <= YUV[y, x, 1] <= u_high and
                    v_low <= YUV[y, x, 2] <= v_high):
                Filtered[y, x] = 1

    # plt.figure()
    # RGB = cv2.cvtColor(im, cv2.COLOR_BGR2RGB)
    # plt.imshow(RGB)
    # plt.title('Original image')
    # # plt.show()
    #
    # plt.figure()
    # plt.imshow(Filtered)
    # plt.title('Filtered image')
    # # plt.show()

    return (Filtered)


def filter_color_square(sq, y_low=50, y_high=200, u_low=120, u_high=130, v_low=120, v_high=130, resize_factor=1,
                        passFactor=0.5):
    """"
    This is a function for filtering the ground in the squares. The input is a certain square patch of the image and YUV
    parameters. The color is then filtered and averaged. Furthermore, a certain pass factor is chosen, which determines how
    much % of pixels needs to fall within a certain band of colors to be considered a "go" zone. An output is a boolean
    with the following meaning: True = squared passed filtration, False = square didn't pass filtration
    """

    sq = cv2.resize(sq, (int(sq.shape[1] / resize_factor), int(sq.shape[0] / resize_factor)))
    YUV = cv2.cvtColor(sq, cv2.COLOR_BGR2YUV)
    Filtered = np.zeros([YUV.shape[0], YUV.shape[1]])

    for y in range(YUV.shape[0]):
        for x in range(YUV.shape[1]):
            if (y_low <= YUV[y, x, 0] <= y_high and
                    u_low <= YUV[y, x, 1] <= u_high and
                    v_low <= YUV[y, x, 2] <= v_high):
                Filtered[y, x] = 1

    avgsum = np.sum(Filtered) / np.size(Filtered)
    return avgsum >= passFactor


def go_decision(Filtered):
    """"
    This is a function for evaluating which directions to go. If more ground is sensed on the right side, the drone
    will go right, and vice versa. The input is an image with filtered ground. The output is a boolean, with the following
    meaning: True = go right / False = go left.
    """

    sumRight = np.sum(Filtered[int(Filtered.shape[0] / 2):Filtered.shape[0],
                      int(Filtered.shape[1] / 2):Filtered.shape[1]])
    sumLeft = np.sum(Filtered[int(Filtered.shape[0] / 2):Filtered.shape[0],
                     0:np.sum(int(Filtered.shape[1] / 2))])

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

    row_num = 7
    sq_size = int(image_d2 / 40)
    img_per_row = 40

    dimensions = []

    for i in range(row_num):
        base_dim1_t = image_d1 - (i+1) * sq_size
        base_dim2 = (image_d2 / (img_per_row + 2))
        for j in range(img_per_row+2):
            base_dim2_t = int((j+0.5) * base_dim2 - sq_size / 2)
            dimensions.append([base_dim1_t, base_dim2_t, sq_size])

    return dimensions, img_per_row


def is_carpet(pixel, image, param, param2):
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
        index -= 7  # Move the square 10 pixels (actual pixels of the image this time) up
        img = image[int(index):int(index + pixel[2]), int(pixel[1]):int(pixel[1] + pixel[2])]  # Build square
        go_zone = filter_color_square(img, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135, resize_factor=param2,
                                      passFactor=param)  # Check
        if go_zone:  # If a grass area was found stop the while loop and return the result to plot the square
            status = True
    return status


def square_mesh(dims, image, param, param2):
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
        go_zone.append(filter_color_square(sq=img, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135,
                                           resize_factor=param2, passFactor=param) or is_carpet(dims[i], image, param, param2))

        if go_zone[i]:  # Coloring is performed here
            image[int(dims[i][0]):int(dims[i][0] + size), int(dims[i][1]):int(dims[i][1] + size), :] = [0, 255, 0]
        elif is_carpet(dims[i], image, param, param2):
            image[int(dims[i][0]):int(dims[i][0] + size), int(dims[i][1]):int(dims[i][1] + size), :] = [0, 255, 0]
        else:
            image[int(dims[i][0]):int(dims[i][0] + size), int(dims[i][1]):int(dims[i][1] + size), :] = [0, 0, 255]

    return image, go_zone


def getAngle(go_zone_state,first_row_len, sq_size, sq_margin, screen_width, sq_spacing):

    """"
    Function for angle detection of obstacles, which returns the angles
    """

    angles = []
    for i in range(first_row_len-4):
        if (int(go_zone_state[2+i])+int(go_zone_state[2+i+first_row_len-1])+int(go_zone_state[2+i+2*first_row_len-4])) <= 1:
            angles.append(-90+((sq_margin+sq_size/2)+sq_spacing*(2+i))*180/screen_width)

    return angles

def get_green_row(go_zone_state, first_row_len):

    if go_zone_state[-1:-first_row_len]:
        return 0
    elif go_zone_state[-(first_row_len+1):-(2*first_row_len+2)]:
        return 1
    elif go_zone_state[-(2*first_row_len+3):-(2*first_row_len+4)]:
        return 2
    return 3

def main(path, param, param2):
    # Image loading
    # id = 75
    # img_list = utils.load_data(image_folder)
    # image1 = utils.get_single_image(img_list[id], image_dir_name = image_folder, graphics=False)
    image = cv2.imread(path)
    # image = cv2.resize(image, (520, 200))
    image = image[149:240, 0:520]

    # Decision based on amount of pixels
    # Filtered = filter_color(im=image, y_low=70, y_high=90, u_low=100, u_high=130, v_low=100, v_high=135)

    # Square definition
    # dims = [200,400,20]
    dims = gen_squares(image.shape[0], image.shape[1])[0]
    sq_per_row = gen_squares(image.shape[0], image.shape[1])[1]
    # Square testing

    meshed_image = square_mesh(dims, image, param, param2)
    goZone = meshed_image[1]
    for i in range(len(goZone)):
        if goZone[i]:

           image[dims[i][0]:dims[i][0]+dims[i][2], dims[i][1]:dims[i][1]+dims[i][2], :] = [0, 0, 0]
        else:
           image[dims[i][0]:dims[i][0]+dims[i][2], dims[i][1]:dims[i][1]+dims[i][2], :] = [255, 255, 255]

    return image

def my_obstacle_filter(im, param, param2):
    """ An example of a filter that can be used to generate ROC curves.
    This filter is a simple color filter around orange. Replace this with your own filter.

    :param im: image to be filtered
    :param param: filter parameter that will be varied between 0.0 and 1.0
    :return: filtered image where detected objects have a value of [255,255,255]
    """
    # Set up the filter based on the input parameter
    filtered_im = main(im, param, param2)
    color_converted = cv2.cvtColor(filtered_im, cv2.COLOR_BGR2RGB)
    filtered_im = Image.fromarray(color_converted)
    # filtered_im.show()

    return filtered_im


def generate_ROC_plot():
    """ Generates a simple ROC plot"""
    plot_data = []
    plot_data2 = []
    plot_data3 = []
    n_images = 5    # Number of images in folder
    for param in np.linspace(0.0, 1.000001, 10):
        # Initialize totals
        true_positives = 0
        false_positives = 0
        ground_truth_positives = 0
        ground_truth_negatives = 0

        for i in range(1, n_images + 1):
            # Set image paths
            original_path = path + 'original/' + str(i) + '_original.jpg'
            ground_truth_path = path + 'mask/' + str(i) + '_mask.png'

            # Analyze ground truth image
            ground_truth_im = Image.open(ground_truth_path, 'r')
            ground_truth_im = ground_truth_im.crop((0, 149, 520, 240))
            # ground_truth_im.show()
            ground_truth_pixels = np.asarray(ground_truth_im.getdata())
            ground_truth_obstacles = np.all(ground_truth_pixels == [255, 255, 255], axis=1)

            # Analyze original image
            # im = Image.open(original_path, 'r')
            filtered_im = my_obstacle_filter(original_path, param, 1)
            # filtered_im.show()
            filtered_im_pixels = np.asarray(filtered_im.getdata())
            filtered_im_obstacles = np.all(filtered_im_pixels == [255, 255, 255], axis=1)

        #     # Update totals of positives/negatives
            true_positives += np.sum((filtered_im_obstacles == True) & (ground_truth_obstacles == True))
            false_positives += np.sum((filtered_im_obstacles == True) & (ground_truth_obstacles == False))
        #
            ground_truth_positives += np.sum((ground_truth_obstacles == True))
            ground_truth_negatives += np.sum((ground_truth_obstacles == False))
        #
        # # Calculate rates
        # print(true_positives, false_positives, ground_truth_positives, ground_truth_negatives)
        false_positive_rate = false_positives / ground_truth_negatives
        true_positive_rate = true_positives / ground_truth_positives
        # filtered_im.show()
        # ground_truth_im.show()
        #
        # # Add datapoint to plot_data
        plot_data.append((false_positive_rate, true_positive_rate))


    for param in np.linspace(0.0, 1.000001, 10):
        # Initialize totals
        true_positives = 0
        false_positives = 0
        ground_truth_positives = 0
        ground_truth_negatives = 0

        for i in range(1, n_images + 1):
            # Set image paths
            original_path = path + 'original/' + str(i) + '_original.jpg'
            ground_truth_path = path + 'mask/' + str(i) + '_mask.png'

            # Analyze ground truth image
            ground_truth_im = Image.open(ground_truth_path, 'r')
            ground_truth_im = ground_truth_im.crop((0, 149, 520, 240))
            # ground_truth_im.show()
            ground_truth_pixels = np.asarray(ground_truth_im.getdata())
            ground_truth_obstacles = np.all(ground_truth_pixels == [255, 255, 255], axis=1)

            # Analyze original image
            # im = Image.open(original_path, 'r')
            filtered_im = my_obstacle_filter(original_path, param, 6)
            # filtered_im.show()
            filtered_im_pixels = np.asarray(filtered_im.getdata())
            filtered_im_obstacles = np.all(filtered_im_pixels == [255, 255, 255], axis=1)

        #     # Update totals of positives/negatives
            true_positives += np.sum((filtered_im_obstacles == True) & (ground_truth_obstacles == True))
            false_positives += np.sum((filtered_im_obstacles == True) & (ground_truth_obstacles == False))
        #
            ground_truth_positives += np.sum((ground_truth_obstacles == True))
            ground_truth_negatives += np.sum((ground_truth_obstacles == False))
        #
        # # Calculate rates
        # print(true_positives, false_positives, ground_truth_positives, ground_truth_negatives)
        false_positive_rate = false_positives / ground_truth_negatives
        true_positive_rate = true_positives / ground_truth_positives
        # filtered_im.show()
        # ground_truth_im.show()
        #
        # # Add datapoint to plot_data
        plot_data2.append((false_positive_rate, true_positive_rate))

    for param in np.linspace(0.0, 1.00001, 10):
        # Initialize totals
        true_positives = 0
        false_positives = 0
        ground_truth_positives = 0
        ground_truth_negatives = 0

        for i in range(1, n_images + 1):
            # Set image paths
            original_path = path + 'original/' + str(i) + '_original.jpg'
            ground_truth_path = path + 'mask/' + str(i) + '_mask.png'

            # Analyze ground truth image
            ground_truth_im = Image.open(ground_truth_path, 'r')
            ground_truth_im = ground_truth_im.crop((0, 149, 520, 240))
            # ground_truth_im.show()
            ground_truth_pixels = np.asarray(ground_truth_im.getdata())
            ground_truth_obstacles = np.all(ground_truth_pixels == [255, 255, 255], axis=1)

            # Analyze original image
            # im = Image.open(original_path, 'r')
            filtered_im = my_obstacle_filter(original_path, param, 12)
            # filtered_im.show()
            filtered_im_pixels = np.asarray(filtered_im.getdata())
            filtered_im_obstacles = np.all(filtered_im_pixels == [255, 255, 255], axis=1)

        #     # Update totals of positives/negatives
            true_positives += np.sum((filtered_im_obstacles == True) & (ground_truth_obstacles == True))
            false_positives += np.sum((filtered_im_obstacles == True) & (ground_truth_obstacles == False))
        #
            ground_truth_positives += np.sum((ground_truth_obstacles == True))
            ground_truth_negatives += np.sum((ground_truth_obstacles == False))
        #
        # # Calculate rates
        # print(true_positives, false_positives, ground_truth_positives, ground_truth_negatives)
        false_positive_rate = false_positives / ground_truth_negatives
        true_positive_rate = true_positives / ground_truth_positives
        # filtered_im.show()
        # ground_truth_im.show()
        #
        # # Add datapoint to plot_data
        plot_data3.append((false_positive_rate, true_positive_rate))

    # filtered_im.show()
    # ground_truth_im.show()
    # # Create x and y data from plot_data
    # print(plot_data)
    x = [item[0] for item in plot_data]
    y = [item[1] for item in plot_data]
    # print(x)
    # print(y)

    x2 = [item[0] for item in plot_data2]
    y2 = [item[1] for item in plot_data2]

    x3 = [item[0] for item in plot_data3]
    y3 = [item[1] for item in plot_data3]

    # Plot
    plt.plot(x, y, linewidth=2, label='Resize factor=1')
    plt.plot(x2, y2, linewidth=2, label='Resize factor=6')
    plt.plot(x3, y3, linewidth=2, label='Resize factor=12')
    plt.plot([0, 1], [0, 1], '--', linewidth=2, label='Random classifier')
    plt.legend(loc='best')
    # plt.rcParams.update({'font.size':10})
    plt.xlabel("False Positive Rate", fontdict={'size': 14})
    plt.ylabel("True Positive Rate", fontdict={'size': 14})
    plt.xlim(0, 1)
    plt.ylim(0, 1)
    plt.grid()
    plt.show()


# Main script
generate_ROC_plot()

