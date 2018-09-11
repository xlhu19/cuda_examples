# coding=utf-8
import docx
import random
import xlrd
import os

DIR = "test"
def list_file(target_dir):
    ret = []
    for rt, dirs, files in os.walk(target_dir):
        for f in files:
            print(os.path.join(rt,f))
            ret.append(os.path.join(rt,f))
    return ret


doclist = list_file(DIR)
# Open the first docx as the final new docx to keep 
docNew = docx.Document(doclist[0])
for i in doclist[1:]:
    doc = docx.Document(i)
    for element in doc.element.body:
        docNew.element.body.append(element)

docNew.save("new.docx")

