import matplotlib.image as mpimg
import matplotlib.pyplot as plt
from PIL import Image
import numpy as np
import os
from functions import *
 

if __name__ == '__main__':
    image_path = '../images/ducks.dng'

    # while using PIL
    # img = Image.open(image_path)
    # height, width = img.height, img.width
    # img = img.getchannel(0)
    # img.show()
    # img_ndarray = np.asfarray(img)

    # while using matplotlib.image
    img = mpimg.imread(image_path)
    width, height, _ = img.shape
    img = img[:, :, 0]
    plt.imshow(img)
    plt.title('Single Channel Uncompressed Image')
    plt.axis('off')
    plt.show()
    uncompressed_image_size = (os.path.getsize(f'{image_path}')*8)/3

    print(f'Type of the image: {type(img)}')
    print(f'Shape of the image: {width}x{height}')
    print(f'Size of the Image (uncompressed): {uncompressed_image_size} bits')
    print(f'Bits per pixel (uncompressed): {uncompressed_image_size/(width*height)}')
    print(f'Entropy of the image: {calculate_entropy(img)}')
    print(spatial(img))
    print(temporal_sptl2(img, case=2))
    print(loco_i(img))

