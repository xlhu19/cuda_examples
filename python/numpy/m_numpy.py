import numpy as np

if __name__ == "__main__":

    x = np.array([[1,2,3],
                  [9,8,7],
                  [6,5,4]])
    print(type(x)) # numpy.ndarray

    # start is 0.0, step is 0.01, [0.0, 2.0), return type is numpy.ndarray
    t = np.arange(0.0, 2.0, 0.01)
    s = 1 + np.sin(2 * np.pi * t)
    print(type(s)) # numpy.ndarray

    x1 = np.linspace(1.0, 50.0) # numpy.linspace(start, stop, num=50, endpoint=True, retstep=False, dtype=None)
    print(type(x1))

