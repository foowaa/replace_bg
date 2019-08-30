import cv2
import numpy
import os

image = cv2.imread("../img/img.png", cv2.IMREAD_GRAYSCALE)
_, thresh = cv2.threshold(image, 240, 255, cv2.THRESH_BINARY)
cv2.bitwise_not(thresh, thresh)
alpha = cv2.merge((thresh, thresh, thresh))
cv2.imwrite("../img/alpha-simple.png", alpha)
