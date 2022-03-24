import sys
import numpy as np
import argparse
import cv2

cap = cv2.VideoCapture('001.MOV')

while 1:
    ret, frame = cap.read()
    gray_vid = cv2.cvtColor(frame, cv2.IMREAD_GRAYSCALE)
    cv2.imshow('Original', frame)
    edged_frame = cv2.Canny(frame, 100, 200)
    cv2.imshow('Edges', edged_frame)

    k = cv2.waitKey(50) & 0xff
    if k == 27:
        break

cap.release()
cv2.destroyAllWindows()