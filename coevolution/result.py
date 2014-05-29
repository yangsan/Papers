# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

N = 100
b = 1.
c = 0.5
w = 0.9


def moran(x):
    return c * x * (1 - x) / ((1-w)/w - b * x + b + c * x)

moran_data = [0.1]
x = 0.1
for i in xrange(21):
    x += moran(x)
    moran_data.append(x)


scale = np.linspace(0, 20, 4000)
moran_simulation_data = np.zeros([4000])
for i in range(N):
    filename = "./data/%d.out" % (i)
    moran_simulation_data += np.loadtxt(filename)


fig, ax = plt.subplots()
ax.plot(np.asarray(moran_data))
ax.scatter(scale, moran_simulation_data/float(N))

ax.set_xlim([0, 20])
plt.show()
