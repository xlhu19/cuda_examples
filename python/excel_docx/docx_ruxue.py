# coding=utf-8
import docx
import random
import xlrd
from xlrd import xldate_as_datetime
from datetime import datetime

def read_names():
    data = xlrd.open_workbook("学生姓名1.1.xlsx")
    table = data.sheets()[0]
    ret = []
    for i in range(table.nrows):
        ret.append((
            table.col_values(0)[i],
            table.col_values(1)[i],
            table.col_values(2)[i],
            table.col_values(3)[i],
            table.col_values(4)[i],
            table.col_values(5)[i],
            table.col_values(6)[i]
        ))
    return ret

data = read_names()
print(xldate_as_datetime(data[0][2], 0).strftime("%Y-%m-%d"))

docNew = xlrd.open_workbook("ruxue.xlsx")

docNew.save("ruxue1.1.xlsx")
