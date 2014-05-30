# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

filename = "timeseries.out"

s = np.loadtxt(filename)

n = s[:, 0]
local = s[:, 1]
moran = s[:, 2]
#print np.sum(s)

fig, ax = plt.subplots()

#linex, = ax.plot(x)
#liney, = ax.plot(y)
#l = plt.legend([linex, liney],["x", "y"])

ax.scatter(n, local)
ax.scatter(n, moran, color="b")

plt.show()
