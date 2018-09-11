import os
import struct
import sys


if __name__ == "__main__":

    f = open('1.dump', 'rb')
    data = f.read(40)
    header = struct.unpack('IIIIIIQQ', data)

