# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

N = 100
b = 1.
c = 0.5
w = 0.9


# theory prediction of moran process
def moran(x):
    return c * x * (1 - x) / ((1-w)/w - b * x + b + c * x)

# numeric result of moran process
moran_data = [0.1]
x = 0.1
for i in xrange(21):
    x += moran(x)
    moran_data.append(x)

# deal the data from simulation
scale = np.linspace(0, 20, 4000)
moran_simulation_data = np.zeros([4000])
for i in range(N):
    filename = "./data/prisoner_moran/%d.out" % (i)
    moran_simulation_data += np.loadtxt(filename)


# theory prediction of local rule
def local(x):
    return w * c / (b + c) * x * (1 - x)

# numeric result of local rule
local_data = [0.1]
x = 0.1
for i in xrange(21):
    x += local(x)
    local_data.append(x)

# deal the data from simulation
scale = np.linspace(0, 20, 4000)
local_simulation_data = np.zeros([4000])
for i in range(N):
    filename = "./data/prisoner_local/%d.out" % (i)
    local_simulation_data += np.loadtxt(filename)


# plot all the result
fig, ax = plt.subplots()

moran_theory, = ax.plot(np.asarray(moran_data))
moran_simu, = ax.plot(scale, moran_simulation_data/float(N))

local_theory, = ax.plot(np.asarray(local_data))
local_simu, = ax.plot(scale, local_simulation_data/float(N))


l = plt.legend([moran_theory, moran_simu, local_theory, local_simu],
                ["moran-theory", "moran-simulation",
                 "local-theory", "local-simulation"], loc = "lower right")

ax.set_xlim([0, 20])
ax.set_ylim([0, 1.1])
plt.show()
