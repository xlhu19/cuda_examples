import cPickle
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

def unpickle(file):
    fo = open(file, 'rb')
    dict = cPickle.load(fo)
    fo.close()
    return dict

#plt.rcParams['figure.figsize'] = (4, 4)        # large images
#plt.rcParams['image.interpolation'] = 'nearest'  # don't interpolate: show square pixels
#plt.rcParams['image.cmap'] = 'gray'  # use grayscale output rather than a (potentially misleading) color heatmap

data = unpickle('./data_batch_1')
image_data = data.get('data')
print(image_data)
print(image_data.ndim)
print(image_data.shape)
print("\n")

image_data = image_data[0]
print(image_data)
print(image_data.ndim)
print(image_data.shape)
print("\n")

image_data = image_data.reshape(3, 1024)
print(image_data)
print(image_data.ndim)
print(image_data.shape)
print("\n")

image_data = image_data.T
print(image_data)
print(image_data.ndim)
print(image_data.shape)
print("\n")

image_data = image_data.reshape(32,32,3)
print(image_data)
print(image_data.ndim)
print(image_data.shape)
print("\n")

plt.imshow(image_data)
plt.show()

#image = mpimg.imread("./cat.jpg")
#plt.imshow(image)
#plt.show()
