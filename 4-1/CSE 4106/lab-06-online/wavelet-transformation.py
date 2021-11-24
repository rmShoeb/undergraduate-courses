#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import matplotlib.pyplot as plt
from scipy import signal


# In[2]:


t, dt   = np.linspace(0,1,200, retstep=True)
fs      = 1/dt
w       = 6


# In[18]:


input_signal    = np.cos(2*np.pi*(50+10*t)*t) + np.sin(40*np.pi*t)
freq            = np.linspace(1, fs/2, 100)
widths          = w*fs / (2*freq*np.pi)
cwt_morlet      = signal.cwt(input_signal, signal.morlet2, widths, w=w)
cwt_mexican_hat = signal.cwt(input_signal, signal.ricker, widths)


# In[19]:


plt.figure(figsize=(20,16), tight_layout=True)

plt.subplot(3,2,1)
plt.plot(input_signal)
plt.title('Input Signal')
plt.axis('off')

plt.subplot(3,2,3)
plt.plot(abs(signal.morlet2(M=100, s=4, w=2)))
plt.title('Morlet Wavelet')
plt.axis('off')

plt.subplot(3,2,4)
plt.plot(cwt_morlet)
plt.title('Coefficient plot generated using Morlet Wavelet')
plt.axis('off')

plt.subplot(3,2,5)
plt.plot(signal.ricker(points=100, a=4))
plt.title('Maxican Hat Wavelet')
plt.axis('off')

plt.subplot(3,2,6)
plt.plot(cwt_mexican_hat)
plt.title('Coefficient plot generated using Maxican Hat Wavelet')
plt.axis('off')

plt.savefig('plt.jpg')
