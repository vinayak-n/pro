import numpy as np
import matplotlib.pyplot as plt


C=np.array([2,-3])
D=np.array([3,1])

E=np.vstack((C,D))
x=np.linalg.inv(E)@[0,8]

print(x)
r=(4*(x[0])**2+2*(x[1])**2)**0.5

#Plotting the ellipse f
phi = np.linspace(0.0,2*np.pi,100)

alpha = r/2
beta  = r/np.sqrt(2)
x_line = alpha*np.cos(phi)
y_line = beta*np.sin(phi)

plt.plot(x_line,y_line,'b',label='$f(\mathbf{x})=4x_1^2 + 2x_2^2 = r^2$')

#Plotting g1
x1 = np.linspace(-5,5,100)
x2 = 8*np.ones(100)  - 3*x1 
plt.plot(x1,x2,'g',label='$g_1(\mathbf{x})=3x_1 + x_2 = 8$')
plt.axis('equal')
plt.grid()
plt.xlabel('$x_1$')
plt.ylabel('$x_2$')
plt.legend(loc=3,prop={'size':12})

plt.xlim(-5, 5)
plt.ylim(-5, 5)

A=x[0]
B=x[1]

plt.plot(A,B,'o')


plt.show()

