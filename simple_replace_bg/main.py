import cv2
import numpy
import os

threshold = 240
image = cv2.imread("../img/img.png", cv2.IMREAD_GRAYSCALE)
_, mask = cv2.threshold(image, threshold, 255, cv2.THRESH_BINARY)
kernel_white_hole = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5))
mask_open = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel_white_hole)
cv2.bitwise_not(mask_open, mask_open)
# https://blog.csdn.net/CJ_035/article/details/81939999
kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (10, 10))
mask_close = cv2.morphologyEx(mask_open, cv2.MORPH_CLOSE, kernel)
kernel_1 = np.ones((5, 5), np.uint8)
mask_erode = cv2.erode(mask_close, kernel_1)
mask_erode = cv2.flip(mask_erode, 1, dst=None)
mask_erode = cv2.erode(mask_erode, kernel_1)
mask_erode = cv2.flip(mask_erode, 1, dst=None)
mask_blur = cv2.GaussianBlur(mask_erode, (5, 5), 0)
mask_blur = cv2.GaussianBlur(mask_blur, (5, 5), 0)
mask_blur = cv2.medianBlur(mask_blur, 15)
alpha = cv2.merge((mask_blur, mask_blur, mask_blur))
foreground = cv2.imread("../img/img.png")
background = bg
# Convert uint8 to float
foreground = foreground.astype(float)
background = background.astype(float)
# Normalize the alpha mask to keep intensity between 0 and 1
alpha = alpha.astype(float) / 255
# Multiply the foreground with the alpha matte
foreground = cv2.multiply(alpha, foreground)
# Multiply the background with ( 1 - alpha )
background = cv2.multiply(1.0 - alpha, background)
# Add the masked foreground and background.
outImage = cv2.add(foreground, background)
# 锐化
kernel = np.array([[0, -1, 0], [-1, 5, -1], [0, -1, 0]], np.float32)
outImage = cv2.filter2D(outImage, -1, kernel=kernel)
cv2.imwrite("../img/alpha-simple.png", outImage)
