# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

filename = "timeseries.out"

s = np.loadtxt(filename)

x = s[:, 0]
y = s[:, 1]
#print np.sum(s)

fig, ax = plt.subplots()

linex, = ax.plot(x)
liney, = ax.plot(y)
l = plt.legend([linex, liney],["x", "y"])

#ax.plot(s)

plt.show()
