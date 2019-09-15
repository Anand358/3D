import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')

a = np.genfromtxt("meshX.dat")
b = np.genfromtxt("meshY.dat")
c = np.genfromtxt("meshz1.dat")
d = np.genfromtxt("meshz2.dat")
e = np.genfromtxt("meshz3.dat")
f = np.genfromtxt("meshz4.dat")
g = np.genfromtxt("meshz5.dat")

ax.plot_surface(a, b, c, color='r',alpha=0.2)
ax.plot_surface(a, b, d, color='g',alpha=0.2)
ax.plot_surface(a, b, e, color='b',alpha=0.5)
ax.plot_surface(a, b, f, color='b',alpha=0.2)
ax.plot_surface(a, b, g, color='b',alpha=1)

plt.grid()
plt.show()
plt.xlabel('$x$')
plt.ylabel('$y$')
