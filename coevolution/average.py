# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

N = 100

data = np.zeros([4000])
for i in range(N):
    filename = "./data/%d.out" % (i)
    data += np.loadtxt(filename)



fig, ax = plt.subplots()
ax.plot(data/float(N))

ax.set_xlim([0, 4000])
plt.show()
