# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

filename = "./data/afteraverage.out"

s = np.loadtxt(filename)

fig, ax = plt.subplots()

ax.plot(s[:,0])
ax.plot(s[:,1])


plt.show()
