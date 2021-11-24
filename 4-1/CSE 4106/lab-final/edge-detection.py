#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import matplotlib.image as mpimg
import matplotlib.pyplot as plt


# In[2]:


img = mpimg.imread('me.jpg')
img = img[:,:,0]

plt.imshow(img, cmap='gray')
plt.axis('off')
plt.savefig('monochrome-me.jpg')
plt.show()


# In[3]:


def detect_edge(img, operator, threshold=48):
    rows, columns = img.shape
    new_img = np.zeros((rows, columns))
    padded_img = np.zeros((rows+2, columns+2))
    padded_img[1:-1, 1:-1] = img
    
    for r in range(1, rows):
        for c in range(1, columns):
            temp = padded_img[r-1:r+2, c-1:c+2]*operator
            temp = np.sum(temp)
            new_img[r, c] = 0 if temp<threshold else temp
    
    return new_img


# # Prewitt Operator

# In[4]:


prewitt_vertical_operator = np.array([[-1,0,1],[-1,0,1],[-1,0,1]])
prewitt_horizontal_operator = np.array([[-1,-1,-1],[0,0,0],[1,1,1]])


# ## With threshold

# In[5]:


plt.figure(figsize=(20,16), tight_layout=True)

plt.subplot(2,2,1)
plt.imshow(img, cmap='gray')
plt.title('Original Image')
plt.axis('off')

plt.subplot(2,2,2)
pvo = detect_edge(img, operator=prewitt_vertical_operator)
plt.imshow(pvo, cmap='gray')
plt.title('Vertical Edge Detected Image Using Prewitt Operator')
plt.axis('off')

plt.subplot(2,2,3)
pho = detect_edge(img, operator=prewitt_horizontal_operator)
plt.imshow(pho, cmap='gray')
plt.title('Horizontal Edge Detected Image Using Prewitt Operator')
plt.axis('off')

plt.subplot(2,2,4)
merged = np.sqrt(pvo**2 + pho**2)
plt.imshow(merged, cmap='gray')
plt.title('Merged Image')
plt.axis('off')

plt.savefig('prewitt-operator-with-threshold.jpg')
plt.show()


# ## Without threshold (setting threshold=0)

# In[6]:


plt.figure(figsize=(20,16), tight_layout=True)

plt.subplot(2,2,1)
plt.imshow(img, cmap='gray')
plt.title('Original Image')
plt.axis('off')

plt.subplot(2,2,2)
pvo = detect_edge(img, operator=prewitt_vertical_operator, threshold=0)
plt.imshow(pvo, cmap='gray')
plt.title('Vertical Edge Detected Image Using Prewitt Operator')
plt.axis('off')

plt.subplot(2,2,3)
pho = detect_edge(img, operator=prewitt_horizontal_operator, threshold=0)
plt.imshow(pho, cmap='gray')
plt.title('Horizontal Edge Detected Image Using Prewitt Operator')
plt.axis('off')

plt.subplot(2,2,4)
merged = np.sqrt(pvo**2 + pho**2)
plt.imshow(merged, cmap='gray')
plt.title('Merged Image')
plt.axis('off')

plt.savefig('prewitt-operator-without-threshold.jpg')
plt.show()


# # Sobel Operator

# In[7]:


sobel_vertical_operator = np.array([[-1,0,1],[-2,0,2],[-1,0,1]])
sobel_horizontal_operator = np.array([[-1,-2,-1],[0,0,0],[1,2,1]])


# ## With threshold

# In[8]:


plt.figure(figsize=(20,20), tight_layout=True)

plt.subplot(2,2,1)
plt.imshow(img, cmap='gray')
plt.title('Original Image')
plt.axis('off')

plt.subplot(2,2,2)
svo = detect_edge(img, operator=sobel_vertical_operator)
plt.imshow(svo, cmap='gray')
plt.title('Vertical Edge Detected Image Using Sobel Operator')
plt.axis('off')

plt.subplot(2,2,3)
sho = detect_edge(img, operator=sobel_horizontal_operator)
plt.imshow(sho, cmap='gray')
plt.title('Horizontal Edge Detected Image Using Sobel Operator')
plt.axis('off')

plt.subplot(2,2,4)
merged = np.sqrt(svo**2 + sho**2)
plt.imshow(merged, cmap='gray')
plt.title('Merged Image')
plt.axis('off')

plt.savefig('sobel-operator-with-threshold.jpg')
plt.show()


# ## Without threshold (setting threshold=0)

# In[9]:


plt.figure(figsize=(20,20), tight_layout=True)

plt.subplot(2,2,1)
plt.imshow(img, cmap='gray')
plt.title('Original Image')
plt.axis('off')

plt.subplot(2,2,2)
svo = detect_edge(img, operator=sobel_vertical_operator, threshold=0)
plt.imshow(svo, cmap='gray')
plt.title('Vertical Edge Detected Image Using Sobel Operator')
plt.axis('off')

plt.subplot(2,2,3)
sho = detect_edge(img, operator=sobel_horizontal_operator, threshold=0)
plt.imshow(sho, cmap='gray')
plt.title('Horizontal Edge Detected Image Using Sobel Operator')
plt.axis('off')

plt.subplot(2,2,4)
merged = np.sqrt(svo**2 + sho**2)
plt.imshow(merged, cmap='gray')
plt.title('Merged Image')
plt.axis('off')

plt.savefig('sobel-operator-without-threshold.jpg')
plt.show()

