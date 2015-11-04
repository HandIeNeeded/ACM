# -*- coding: utf-8 -*- 
import sys
import os

for i in xrange(1, 11):
    os.system('unzip -OCP936 标程+数据\(' + str(i) + '\).zip -d标程+数据\(' + str(i) + '\)')
