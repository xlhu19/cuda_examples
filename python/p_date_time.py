#!/usr/bin/python
# -*- coding: UTF-8 -*-

import time

localtime = time.localtime(time.time())
print(localtime.tm_hour)
print(localtime)
localtime = time.localtime(1516323365)
print(localtime.tm_hour)
print(localtime)

time.sleep(1)

