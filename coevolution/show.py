# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

filename = "./data/prisoner.out"

data = np.loadtxt(filename)

t = data
#f1 = data[:, 1]
#f2 = data[:, 2]

#t1 = data1[:, 0]
#f3 = data1[:, 1]

#with open("npsave.txt", "w") as f:
    #np.savetxt(f, data)

fig, ax = plt.subplots()
ax.plot(t)

#fig1, ax1 = plt.subplots()
#ax1.plot(t1, f3/3200.)
#ax.plot(f2)
#ax.set_ylim([0.14, 0.26])
ax.set_xlim([0, 4000])
#ax.plot(f3)
plt.show()
