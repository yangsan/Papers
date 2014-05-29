# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

filename = "./data/0.out"
filename1 = "./data/1.out"

data = np.loadtxt(filename)
data1 = np.loadtxt(filename1)

t = data[:, 0]
#f1 = data[:, 1]
#f2 = data[:, 2]

#t1 = data1[:, 0]
#f3 = data1[:, 1]

#with open("npsave.txt", "w") as f:
    #np.savetxt(f, data)
t1 = t[200001:]
t2 = t[200000:-1]

print np.average(t1 - t2)
fig, ax = plt.subplots()
his = ax.hist(t1-t2, 100)
#ax.plot(t, f1)

#fig1, ax1 = plt.subplots()
#ax1.plot(t1, f3/3200.)
#ax.plot(f2)
#ax.set_ylim([0.14, 0.26])
#ax.plot(f3)
plt.show()
