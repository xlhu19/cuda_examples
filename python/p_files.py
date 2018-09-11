import os
import struct
import sys

"""
    Version: 0.1
    Date: 2017-03-28
"""

"""
r   Read mode, the default mode.
    The file must exist.
    Read only.
r+  Read and write mode
    The file must exist.
    Read and Write.
w   Write mode.
    If file exists, flush file and then write.
    If file does not exist, create new file and then write.
    Write only.
w+  Read and write mode
    If file exists, flush file and then write.
    If file does not exist, create new file and then write.
a   Append write mode
    If file exists, seek to the end.
    If file does not exist, create new file.
    Write only.
a+  Append read and write mode, seek to the end.
    If file exists, seek to the end.
    If file does not exist, create new file.
b   Open with binary mode, useful for Windows and DOS file.

Difference bewteen 'r' 'w' and 'rb' 'wb'
1. 'r' will end with '0x1A'. 'rb' will read end of file.
2. 'w' will auto write '0x0A' with '0X0D', '0X0A'
   'wr' will write the real binary.
   'r' will treat '0X0D', '0X0A' with '0x0A'
   'rb' will treat it the real binary.
"""

def write_string():
    f = open('test.txt', 'w')
    f.write('abcdefghijklmnopqrstuvwxyz')
    f.close()

def write_binary():
    data = struct.pack('b', 0x23);
    f = open('test.txt', 'w')
    f.write(data)
    f.close()

def write_lines():
    f = open('test.txt', 'w')
    f.writelines(["1\n", "2\n", "3\n"])
    f.close()

def read_all():
    f = open('test.txt', 'r')
    # type of c is string
    c = f.read()
    print(c)
    for ii in c:
        data = struct.unpack('b', ii);
        # print hex byte
        print(data[0])
    f.close()

def read_line():
    f = open('test.txt', 'r')
    line = f.readline() # Read one line only
    f.close()

def read_lines():
    f = open('test.txt', 'r')
    lines = f.readlines()
    # lines is a list
    for line in lines:
        print(line)
    f.close()

def read_binary():
    f = open('test.txt', 'rb')
    data = f.read()
    out = struct.unpack(str(len(data))+'b', data)
    for b in out:
        print(b)
    f.close()

def encrypt():
    f = open('test.txt', 'rb')
    f_n = open('test.txt.new', 'wb')
    data = f.read()
    out = struct.unpack(str(len(data))+'b', data)
    for ii in out:
        b = struct.pack('b', ii + 1);
        f_n.write(b)
    f.close()
    f_n.close()


fileList = []
def _list_dir(path):
    fileNames = os.listdir(path);
    for fn in fileNames:
        if os.path.isdir(os.path.join(path, fn)):
            print('dir: ' + fn)
            _list_dir(os.path.join(path, fn))
        else:
            print('file: ' + fn)
            if path.endswith('/0'):
                print('    my file: ' + fn)
                fileList.append(fn)

def _rename(path, old, new):
    fileNames = os.listdir(path);
    for fn in fileNames:
        if os.path.isdir(os.path.join(path, fn)):
            _rename(os.path.join(path, fn), old, new)
        else:
            if fn.find(old):
                print('file: ' + path + fn)
                fn_new = fn.replace(old, new)
                os.rename(os.path.join(path, fn), os.path.join(path, fn_new))

def file_list_dir(target_dir):
    for rt, dirs, files in os.walk(target_dir):
        for f in files:
            print(os.path.join(rt,f))

def _list_dir_files(path):
    for rt, dirs, files in os.walk(path):
        for f in files:
            pf = os.path.join(rt, f)
            print(pf)
            print(os.path.getctime(pf)
            print(os.path.getatime(pf)
            print(os.path.getmtime(pf)

def read_big_file():
    with open() as f:
        for line in f:
            print(line)

if __name__ == "__main__":
    # write_string()
    # read_all()
    # read_lines()
    # read_binary()
    # encrypt()
    file_list_dir('./')
