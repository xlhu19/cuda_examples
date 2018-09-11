#!/usr/bin/python

# for python 2.7, print without CR
# from __future__ import print_function
# print("hello world", end='')

print("hello world")

print("hello world", end='') # without CR
print("")


# ---------------------------
# typecode
# ---------------------------
# %s    - string use str()
# %r    - string use repr()
# %c    - char
# %b    - binary
# %d    - integer
# %i    - integer
# %o    - octonary
# %x    - hex
# %e    - e
# %E    - E
# %f    - float
# %F    - float
# %g    - e
# %G    - E
# %%    - %

# %[(name)][flags][width].[precision]typecode
# flags     - '+' '-' '0' ' '
# width     - width to show
# precision -

str_1 = "strong yourself forever"
print("str_1 is %s" % str_1)

print("%+10x" % 10)
print("%04d" % 5)
print("%6.3f" % 2.3)

# width and precision can be replaced by *
print("%.*f" % (4, 1.2))
print("%*.*f" % (8, 4, 1.2))


# print("\033[FORMAT;word_color;background_colorm......\033[0m")
# \033 is ASCII ESC
# FORMAT
# 0           |     default
# 1           |     highlight
# 4           |     underline
# 5           |     blinking
# 7           |     reverse video
# 8           |     invisible
# word_color| background_color|
# 30        |        40       |       black
# 31        |        41       |       red
# 32        |        42       |       green
# 33        |        43       |       yellow
# 34        |        44       |       blue
# 35        |        45       |       prunosus
# 36        |        46       |       ultramarine
# 37        |        47       |       white
print("\033[0;31;40m string \033[0m")


