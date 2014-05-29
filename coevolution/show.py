# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

filename = "./data/prisoner.out"

data = np.loadtxt(filename)

t = data


fig, ax = plt.subplots()
ax.plot(t)

ax.set_xlim([0, 4000])
plt.show()
