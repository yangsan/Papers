# -*- coding: utf8 -*-

import numpy as np
import matplotlib.pyplot as plt
from scipy.fftpack import fft, fftfreq

N = 5

sp = np.zeros(200000)

for i in xrange(N):
    print i
    filename = "./data/%d.out" % (i)
    data = np.loadtxt(filename)
    f1 = data[100000:, 1]

    sp += np.abs(fft(f1 - np.average(f1))/float(f1.size))**2

freq = fftfreq(f1.size, 0.00163324104747)

plt.plot(freq, sp/5.)
plt.xlim(0, 0.2)

plt.show()
