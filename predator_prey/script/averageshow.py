# -*- coding: utf8 -*-
import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint

filename = "./data/afteraverage.out"

s = np.loadtxt(filename)

#theory
b = 0.1
d1 = 0.1
d2 = 0.0
p1 = 0.25
p2 = 0.05

def f(y, t):
    f1i = y[0]
    f2i = y[1]
    f1 = 2 *p1 * f1i * f2i - d1 * f1i
    f2 = 2 * b * f2i - 2 * b * f2i**2 - d2 * f2i - 2 * (p1 + p2 + b) * f1i * f2i
    return [f1, f2]

#initial conditions
y0 = [0.5 , 0.5]
t = np.linspace(0, 500,10000)

soln = odeint(f, y0, t)

f1 = soln[:, 0]
f2 = soln[:, 1]

fig, ax = plt.subplots()

line1, = ax.plot(t, f1)
line2, = ax.plot(t, f2)

line3, = ax.plot(s[:,0])
line4, = ax.plot(s[:,1])

l1 = plt.legend([line1, line2, line3, line4],
                ["theory:$f_1$","theory:$f_2$", "simulation:$f_1$", "simulation:$f_2$"]
                )

plt.show()
