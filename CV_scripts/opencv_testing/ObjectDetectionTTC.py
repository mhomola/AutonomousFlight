# Based on a paper by Mori and Scherer: First Results in Detecting and Avoiding
# Frontal Obstacles from a Monocular Camera for MAVs
#

import sys
import cv2
import numpy as np
import matplotlib.pyplot as plt


def loadCapture(path):
    """
    This function loads the video found at the given path. Raises exception
    in case no video was found, or the function was unable to open it.
    """

    capture = cv2.VideoCapture(path)

    if not capture.isOpened():
        raise Exception("Could not load video!")

    return capture


def getKeypoints(prevFrame, currFrame, method ='ORB', hessianThreshold=400):
    """
    This function obtains keypoints from consecutive frames using a specified
    method. Difference with paper: ORB is used instead of SURF (more efficient).
    A common value for the Hessian threshold is 300-500.
    """

    # Improvement: use U-SURF instead of surf since orientation is not important?
    if method == 'SURF':

        # Create SURF object, set threshold for Hessian
        detector = cv2.xfeatures2d.SURF_create(hessianThreshold)

        # Find keypoints and descriptors for both frames
        prevKeypoints, prevDescriptors = detector.detectAndCompute(prevFrame, None)
        currKeypoints, currDescriptors = detector.detectAndCompute(currFrame, None)

    elif method == 'ORB':

        # Create ORB detector
        detector = cv2.ORB_create()

        # Find keypoints and descriptors for both frames
        prevKeypoints, prevDescriptors = detector.detectAndCompute(prevFrame, None)
        currKeypoints, currDescriptors = detector.detectAndCompute(currFrame, None)

    return detector, prevKeypoints, prevDescriptors, currKeypoints, currDescriptors


def matchKeypoints(prevDescriptors, currDescriptors, method='ORB'):
    """
    This function matches keypoints from consecutive frames using brute-force
    matching. The paper used SURF.
    """

    if method == 'ORB':

        # Create brute-force matcher based on Hamming distance
        matcher = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)

    elif method == 'SURF':

        # L2 distance (Euclidean) for SURF
        matcher = cv2.BFMatcher(cv2.NORM_L2, crossCheck=True)

    # Match descriptors
    matches = matcher.match(prevDescriptors, currDescriptors)

    return matches


def filterMatches(matches, prevKeypoints, currKeypoints, threshold=30):
    """
    This function discards matches between consecutive frames based on the
    distance between keypoints, which has to be below a certain threshold,
    and based on the fact whether their scale increases (keypoints that
    don't increase in scale are not useful for TTC). In the paper, the
    threshold for the L2 distance (Euclidean) was 0.25. For ORB, most
    inliers are included (and most outliers excluded) with a threshold
    of 64.
    """

    # queryIdx refers to prevKeypoints, trainIdx refers to currKeypoints
    filteredMatches = list(
        filter(lambda m: m.distance < threshold and currKeypoints[m.trainIdx].size > prevKeypoints[m.queryIdx].size,
               matches))

    # Check if length is reasonable
    # print(len(filteredMatches))

    return filteredMatches


def createTemplate(prevKeypoint, currKeypoint, frame, scale=1.2 / 9 * 20):
    """
    This function creates a template around the location of a keypoint in the
    current frame, based on the size of a keypoint in the previous frame.
    The (seemingly random) size is taken from the paper.
    """

    # Create function that limits pixel coordinates to be within the frame
    clampInt = lambda px, pxMin, pxMax: int(max(min(pxMax, px), pxMin))

    # And one that creates an extent tuple based on centers and delta
    extent = lambda row, col, delta: (clampInt(row - delta / 2, 0, frame.shape[0]),
                                      clampInt(row + delta / 2, 0, frame.shape[0]),
                                      clampInt(col - delta / 2, 0, frame.shape[1]),
                                      clampInt(col + delta / 2, 0, frame.shape[1]))

    # Get location and size of keypoints
    location = currKeypoint.pt  # given as (x, y), not (r, c)!
    size = prevKeypoint.size * scale
    box = extent(location[1], location[0], size)

    # Get template
    template = frame[box[0]:box[1], box[2]:box[3]]

    return template


def matchTemplates(matches, prevKeypoints, currKeypoints, prevFrame, currFrame):
    """
    This function creates templates of a certain size around each matched
    keypoint. The (seemingly random) size is taken from the paper.
    """

    # Matches that are on the object
    matchesOnObject = []

    # Use actual frame or edges (Canny)?

    for m in matches:

        prevTemplate = createTemplate(prevKeypoints[m.queryIdx], currKeypoints[m.trainIdx], prevFrame)

        # Very large nr to start off
        templateMatchMin = 1e9
        templateMatches = []

        # Scales from paper
        # Start from 1: we only consider increases in size
        for s in np.arange(1., 2.1, 0.1):

            scaledPrevTemplate = cv2.resize(prevTemplate, (0, 0), fx=s, fy=s)

            currTemplate = createTemplate(prevKeypoints[m.queryIdx], currKeypoints[m.trainIdx], currFrame,
                                          scale=1.2 / 9 * 20 * s)

            # Crude version: might discard too much pixels
            rows = min(scaledPrevTemplate.shape[0], currTemplate.shape[0]) - 1
            cols = min(scaledPrevTemplate.shape[1], currTemplate.shape[1]) - 1

            # Do L2 distance (Euclidean)
            templateMatch = np.sqrt(
                ((currTemplate[:rows, :cols] - scaledPrevTemplate[:rows, :cols]) ** 2 / (s * s)).sum())
            templateMatches.append(templateMatch)

            if templateMatch < templateMatchMin:
                templateMatchMin = templateMatch
                scaleMin = s
                bestCurrTemplate = currTemplate

        comparisonTemplates = np.zeros(
            (max(prevTemplate.shape[0], bestCurrTemplate.shape[0]), prevTemplate.shape[1] + bestCurrTemplate.shape[1]))
        comparisonTemplates[:prevTemplate.shape[0], :prevTemplate.shape[1]] = prevTemplate
        comparisonTemplates[:bestCurrTemplate.shape[0], prevTemplate.shape[1]:] = bestCurrTemplate

        # print(scaleMin, templateMatchMin, 0.9*templateMatches[0])

        # plt.plot(np.arange(1., 2.1, 0.1), templateMatches)
        # plt.show()

        # plt.imshow(comparisonTemplates, cmap='gray')
        # plt.show()

        if scaleMin > 1.2 and templateMatchMin < 0.8 * templateMatches[0]:
            matchesOnObject.append(m)

    return matchesOnObject


def draw(prevFrame, prevKeypoints, currFrame=None, currKeypoints=None, matches=None, method='matches',
         mColor=(0, 255, 0), sColor=(0, 0, 255), flag=4):
    """
    This function draws either the keypoints for 1 frame, or the matching
    keypoints between 2 frames. Flag: 2 for only matches, 4 for rich keypoints.
    Matches will be drawn in green, single points (no match found) in red.
    """

    if method == 'keypoints':

        drawing = cv2.drawKeypoints(prevFrame, prevKeypoints, matchColor, flag)

    elif (method == 'matches') and (currFrame != None) and (currKeypoints != None) and (matches != None):

        drawing = cv2.drawMatches(prevFrame, prevKeypoints, currFrame, currKeypoints, matches, None, mColor, sColor,
                                  None, flag)

    cv2.imshow('Keypoints', drawing)

    return drawing


def lagQuitSave(lag):
    """
    Implements a certain lag between frames to make the video more watchable
    in case processing speed is high. Also gives the opportunity to quit or
    save frame as image.
    """

    # Lag between frames
    k = cv2.waitKey(lag) & 0xff  # to select only the last 8 bits

    # Possibility to quit or save frames
    if k == 27 or k == ord('q'):
        return True

    elif k == ord('s'):
        cv2.imwrite('keypoints.png', drawing)
        cv2.imwrite('frame.png', currFrame_gray)

    return False


if __name__ == '__main__':

    capture = loadCapture(sys.argv[1])

    # Get first frame
    success, prevFrame = capture.read()

    # Convert to grayscale
    prevFrame_gray = cv2.cvtColor(prevFrame, cv2.COLOR_BGR2GRAY)

    while True:

        # Read next frame, skip 2
        success, currFrame = capture.read()
        success, currFrame = capture.read()
        success, currFrame = capture.read()

        # Convert to grayscale
        currFrame_gray = cv2.cvtColor(currFrame, cv2.COLOR_BGR2GRAY)

        # Obtain keypoints with ORB
        detector, prevKeypoints, prevDescriptors, currKeypoints, currDescriptors = getKeypoints(prevFrame_gray,
                                                                                                currFrame_gray)

        # Match between frames, only 10 best matches
        matches = matchKeypoints(prevDescriptors, currDescriptors)

        # Filter matches based on increasing scale
        matches = filterMatches(matches, prevKeypoints, currKeypoints)

        # Create templates from keypoints and match
        matchesOnObject = matchTemplates(matches, prevKeypoints, currKeypoints, prevFrame_gray, currFrame_gray)

        # Draw matches
        drawing = draw(prevFrame_gray, prevKeypoints, currFrame_gray, currKeypoints, matchesOnObject, flag=4)

        # Lag + quit or save
        if lagQuitSave(100):
            break

        # Set current as previous and 'crawl' forward
        prevFrame_gray = currFrame_gray

# Close all
capture.release()
cv2.destroyAllWindows()