# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

filename = "./data/timeseries/0.out"

data = np.loadtxt(filename)

t = data[:, 0]
f1 = data[:, 1]
f2 = data[:, 2]

fig, ax = plt.subplots()
ax.plot(t, f1)
ax.plot(t, f2)

plt.show()
