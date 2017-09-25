import signal as signal
import numpy as np
import matplotlib.pyplot as plt

w = np.linspace(1E-5, 0.5, 10000)
f = w * (3.072E6/2)

# R is the decimation ratio, N is the filter order, M is a free number usually 1 or 2
R = 32
N = 4
M = 1

H = np.abs((np.sin(R*M*np.pi*w) / (R*M * np.sin(np.pi * w))))**N
Hdb = 10 * np.log(H)
kstr = 'R={0}, M={1}, N = {2}'.format(R, M, N)
plt.plot(f, Hdb, label=kstr)

plt.legend()
plt.grid()
plt.ylim([-200, 0])
plt.xlabel('Sampling Rate [Hz]')
plt.ylabel('Attenuation [dB]')
plt.show()