# -*- coding: utf8 -*-

import numpy as np
import os

data_file_list =  os.listdir(os.getcwd()+"/data/average/")

data = np.zeros([30000, 2])

for filename in data_file_list:
    s = np.loadtxt("./data/average/" + filename)
    data += s[:, 1:]/3200.


with open("./data/afteraverage.out", "w") as f:
    np.savetxt(f, data/float(len(data_file_list)))


