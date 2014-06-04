# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

filename = "timeseries.out"

s = np.loadtxt(filename)

n = s[:, 0]
local = s[:, 1]
guide = np.linspace(-20, 600, 1000)
guide_zeros = np.zeros(len(guide))
#moran = s[:, 2]
#print np.sum(s)

fig, ax = plt.subplots()

#linex, = ax.plot(x)
#liney, = ax.plot(y)
#l = plt.legend([linex, liney],["x", "y"])

ax.scatter(n, local)
ax.plot(guide, guide_zeros)
ax.set_xlim([-10, 510])
ax.set_ylim([-0.001, 0.005])
ax.set_xlabel("N")
ax.set_ylabel("$<\Delta H>N$")
#ax.scatter(n, moran, color="b")

plt.show()
