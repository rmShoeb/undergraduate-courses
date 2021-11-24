import matplotlib.image as mpimg
import matplotlib.pyplot as plt
from PIL import Image #pillow

#img = mpimg.imread('../images/ruet_logo.png')
img = Image.open('../images/ruet_logo.png')
lum_img = img[:,:,0]

#plt.imshow(img)
#plt.imshow(img, cmap='hot')

#plt.imshow(lum_img, cmap='hot')
#imgplot = plt.imshow(lum_img)
imgplot = plt.imshow(lum_img, clim=(0.0, 0.7))
#imgplot.set_cmap('nipy_spectral')
#plt.hist(lum_img.ravel(), bins=256, range=(0.0, 1.0), fc='k', ec='k')

#plt.hist(lum_img.ravel())
plt.colorbar()
plt.show()

