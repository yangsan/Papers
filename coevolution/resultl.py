# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt

N = 100
b = 1.
c = 0.5
w = 0.9


def local(x):
    return w * c /(b + c) * x * (1 - x)

local_data = [0.1]
x = 0.1
for i in xrange(21):
    x += local(x)
    local_data.append(x)

scale = np.linspace(0, 20, 4000)
local_simulation_data = np.zeros([4000])
for i in range(N):
    filename = "./data/prisoner_local/%d.out" % (i)
    local_simulation_data += np.loadtxt(filename)


fig, ax = plt.subplots()
local_theory, = ax.plot(np.asarray(local_data))
local_simu, = ax.plot(scale, local_simulation_data/float(N))

l1 = plt.legend([local_theory, local_simu],
                ["local-theory", "local-simulation"])

ax.set_xlim([0, 20])
plt.show()
