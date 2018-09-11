"""
apt-get install python-tk
pip install ipython
pip install matplotlib
pip install ipykernel
"""
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

def show_image(img):
    image = mpimg.imread(img)
    plt.imshow(image)
    plt.show()

def base():
    X = np.linspace(-np.pi, np.pi, 256, endpoint=True)
    C,S = np.cos(X), np.sin(X)

    plt.plot(X, C)
    plt.plot(X, S)
    plt.show()

#plt.rcParams['figure.figsize'] = (10, 10)        # large images
#plt.rcParams['image.interpolation'] = 'nearest'  # don't interpolate: show square pixels
#plt.rcParams['image.cmap'] = 'gray'
Y = np.array([[[0.71,0.62,0.83], [0.29,0.78,0.87], [0.16,0.65,0.74]],
              [[0.21,0.52,0.93], [0.39,0.68,0.97], [0.26,0.55,0.84]],
              [[0.31,0.42,0.03], [0.49,0.58,0.07], [0.36,0.45,0.94]]
             ])
plt.imshow(Y)
plt.show()
