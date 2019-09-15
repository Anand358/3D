from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

#creating x,y for 3D plotting
len = 10
xx, yy = np.meshgrid(range(len), range(len))
#setting up plot
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')

#Equation of Plane is : n.T * x = c

#defining planes
n= np.array([1,1,1]).reshape((3,1))
c1 = 1
c2=1
c3=0

#corresponding z for planes
z1 = ((c1-n[0]*xx-n[1]*yy)*1.0)/(n[2])
z2 = ((c2-n[0]*xx-n[1]*yy)*1.0)/(n[2])
z3 = ((c3-n[0]*xx-n[1]*yy)*1.0)/(n[2])
ax.plot_surface(xx,yy,z1,color='r')
ax.plot_surface(xx,yy,z2,color='g')
ax.plot_surface(xx,yy,z3,color='b')

print(z1)

plt.show()
plt.xlabel('$x$')
plt.ylabel('$y$')
