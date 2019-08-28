from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

A=np.array([2,3,5])
B=np.array([-1,3,2])
C=np.array([7,5,10])
D=(B+C)/2

#setting up plot
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')

plt.plot([A[0],B[0]],[A[1],B[1]],[A[2],B[2]],label='$AB$')
plt.plot([B[0],C[0]],[B[1],C[1]],[B[2],C[2]],label='$BC$')
plt.plot([C[0],A[0]],[C[1],A[1]],[C[2],A[2]],label='$CA$')
plt.plot([A[0],D[0]],[A[1],D[1]],[A[2],D[2]],label='$AD$')

ax.scatter(A[0],A[1],A[2],'o',label="Point A")
ax.scatter(B[0],B[1],B[2],'o',label="Point B")
ax.scatter(C[0],C[1],C[2],'o',label="Point C")
ax.scatter(D[0],D[1],D[2],'o',label="Point D")

#show plot
plt.xlabel('$x$');plt.ylabel('$y$')
plt.legend(loc='best')

plt.grid()
plt.grid()
plt.show()
