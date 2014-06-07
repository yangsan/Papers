# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

filename = "./data/timeseries/0.out"

data = np.loadtxt(filename)

t = data[:, 0]
f1 = data[:, 1]
f2 = data[:, 2]


#with open("npsave.txt", "w") as f:
    #np.savetxt(f, data)
#t1 = t[200001:]
#t2 = t[200000:-1]

#print np.average(t1 - t2)
fig, ax = plt.subplots()
#his = ax.hist(t1-t2, 100)
ax.plot(t, f1)
ax.plot(t, f2)
#ax.plot(t)

#fig1, ax1 = plt.subplots()
#ax1.plot(t1, f3/3200.)
#ax.plot(f2)
#ax.set_ylim([0.14, 0.26])
#ax.plot(f3)
plt.show()
