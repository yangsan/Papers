# -*- coding: utf8 -*-

import numpy as np
import matplotlib.pyplot as plt
from scipy.fftpack import fft, fftfreq

N = 1000

filename = "timeseries.out"
data = np.loadtxt(filename)
f1 = data[200:, 0]

sp = np.absolute(fft(f1 - np.average(f1))/3200.)**2

freq = fftfreq(f1.size, 0.2)

plt.plot(freq, sp)
plt.xlim(0, 0.2)

plt.show()
