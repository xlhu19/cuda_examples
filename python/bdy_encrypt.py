#!/usr/bin/env python

import getopt
import os
import re
import sys
import time
import struct
import base64
import types

VERSION = 0.1

def printUsage():
    print('Usage: ')

def printVersion():
    print('Version is ' + str(VERSION))

def encrypt_file(f):
    fileHandle = open(f, 'a+')
    fileHandle.write('yinyin520')
    fileHandle.close()

def decrypt_file(f):
    fileHandle = open(f, 'a+')
    fileHandle.write('yinyin520')
    fileHandle.close()

def encrypt_file_2(f):
    fileHandle = open(f, 'rb')
    data1 = fileHandle.read()
    fileHandle.close()

    len = os.path.getsize(f)
    out1 = struct.unpack(str(len)+'b', data1)
    o2=[]
    for i in out1:
        o2.append(i+1)
    data2 = bytes(o2)
    # print(data2)

    # out2 = struct.unpack(str(len)+'b', data2)
    # o1=[]
    # for i in out2:
        # o1.append(i-1)
    # data1 = bytes(o1)
    # print(data1)

    fileHandle = open(f+'.encrypt', 'wb')
    fileHandle.write(data2)
    fileHandle.close()
    

def decrypt_file_2(f):
    fileHandle = open(f, 'rb')
    data1 = fileHandle.read()
    fileHandle.close()

    len = os.path.getsize(f)
    out1 = struct.unpack(str(len)+'b', data1)
    o2=[]
    for i in out1:
        o2.append(i-1)
    data2 = bytes(o2)

    fileHandle = open(f+'.decrypt', 'wb')
    fileHandle.write(data2)
    fileHandle.close()

def main(argv):
    opts, args = getopt.getopt(argv[1:], 'e:d:hv',
                               ['encrypt=',
                                'decrypt=',
                                'help',
                                'version'])
    for opt, val in opts:
        if opt in ('-e', '--encrypt'):
            encrypt_file(val)
        elif opt in ('-d', '--decrypt'):
            decrypt_file(val)
        elif opt in ('-h', '--help') and argLen == 1:
            printUsage()
            sys.exit(0)
        elif opt in ('-v', '--version') and argLen == 1:
            printVersion()
            sys.exit(0)
        else:
            print('ERROR: Unsupported option .' + str(opts))
            printUsage()
            sys.exit(2)

if __name__ == "__main__":
    main(sys.argv)