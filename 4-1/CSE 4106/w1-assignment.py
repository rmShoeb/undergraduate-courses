from PIL import Image
from matplotlib import pyplot as plt
import numpy as np


# read image
img = Image.open('cse_logo.png')

# show the image
# img.show()

# image summary
print(img.size)
print(img.format)
print(img.mode)


# resize
# out = img.resize((100, 100))
# out = img.resize((100, 100), resample=0)
# pass a 4-member tuple as box to select portion of the main image to resize
# out.show()
# resample
# Image.NEAREST
# Image.BOX
# Image.BILINEAR
# Image.HAMMING
# Image.BICUBIC
# Image.LANCZOS

# saving image
# out.save('resized-output.png')

# https://pythonexamples.org/python-pillow-rotate-image-90-180-270-degrees/

# convert to numpy array
# print(np.asfarray(img))
data = np.array(img)
print(data.shape)

# create Pillow image
image2 = Image.fromarray(data)
print(type(image2))

# converting image to greyscale
im = np.array(Image.open('cse_logo.png').convert('L')) #you can pass multiple arguments in single line
print(type(im))
gr_im= Image.fromarray(im).save('gr.png')

# trimming image
im = np.array(Image.open('cse_logo.png'))
print("Before trimming:",im.shape)
im_trim = im[128:384, 128:384]
print("After trimming:",im_trim.shape)
Image.fromarray(im_trim).save('trim.jpeg')

