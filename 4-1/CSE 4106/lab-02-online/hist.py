import matplotlib.image as mpig
import matplotlib.pyplot as plt
import numpy as np

img = mpig.imread('husky.jpeg')

print(img.shape)
plt.imshow(img)
plt.show()

titles = ['red channel', 'histogram for red channel', 'green channel', 'histogram for green channel', 'blue channel', 'histogram for blue channel']
for c in range(3):
    image = img[:,:,c]
    plt.subplot(3,2,c*2+1)
    plt.imshow(image)
    plt.title(titles[c*2])
    plt.subplot(3,2,c*2+2)
    plt.hist(image.flatten(), bins=256)
    plt.title(titles[c*2+1])
    c += 1

plt.show()