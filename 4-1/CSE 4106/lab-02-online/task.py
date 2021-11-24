# imports
import matplotlib.image as mpig
import matplotlib.pyplot as plt
import numpy as np

# read the image
img = mpig.imread('gray-husky.jpeg')
# print(img.shape)
L = int(input('L: '))
image = img[:,:,0]
# place the imput image
plt.subplot(1,2,1)
plt.imshow(image)
plt.title('Input image in one channel')
output_img = np.zeros(image.shape)

# digital negative
# output_img = L-image

# contrast stretching
# a = float(input('a: '))
# b = float(input('b: '))
# alpha = float(input('alpha: '))
# beta = float(input('beta: '))
# gama = float(input('gama: '))
# ya = float(input('ya: '))
# yb = float(input('yb: '))
# for i in range(image.shape[0]):
#     for j in range(image.shape[1]):
#         x = image[i][j]
#         if x < a:
#             output_img[i][j] = alpha*x
#         elif x < b:
#             output_img[i][j] = beta*(x-a)+ya
#         else:
#             output_img[i][j] = gama*(x-b)+yb

# Clipping
# a = float(input('a: '))
# b = float(input('b: '))
# beta = float(input('beta: '))
# for i in range(image.shape[0]):
#     for j in range(image.shape[1]):
#         x = image[i][j]
#         if x < a:
#             output_img[i][j] = 0
#         elif x < b:
#             output_img[i][j] = beta*(x-a)
#         else:
#             output_img[i][j] = beta*(b-a)

# Range Compression
c = float(input('c: '))
for i in range(image.shape[0]):
    for j in range(image.shape[1]):
        output_img[i][j] = c*np.log10(1+image[i][j])

# place the output image
plt.subplot(1,2,2)
plt.imshow(output_img)
plt.title('Output image')
plt.show()
# print(output_img==image)
