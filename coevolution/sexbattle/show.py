# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

filename = "timeseries.out"

s = np.loadtxt(filename)

guide = np.linspace(-20, 600, 1000)
guide_zeros = np.zeros(len(guide))

n = s[:, 0]
moran = s[:, 1]
local = s[:, 2]

fig, ax = plt.subplots()

ax.set_xlim([-10, 510])
ax.set_ylim([-0.002, 0.005])
ax.set_xlabel("N")
ax.set_ylabel("$<\Delta H>N$")

scatter_moran = ax.scatter(n, moran, color='blue')
scatter_local = ax.scatter(n, local, color='red')
l = plt.legend([scatter_moran, scatter_local], ["moran", "local"])
ax.plot(guide, guide_zeros, color='black')
#ax.plot(s)

plt.show()
