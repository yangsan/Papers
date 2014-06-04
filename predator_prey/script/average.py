# -*- coding: utf8 -*-

import numpy as np
#import matplotlib.pyplot as plt

N = 500

data = np.zeros([300000, 2])

for i in xrange(N):
    print i
    filename = "./data/%d.out" % (i)
    s = np.loadtxt(filename)
    data += s[:, 1:]/3200.

with open("average.txt", "w") as f:
    np.savetxt(f, data/float(N))
