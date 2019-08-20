import numpy as np
import matplotlib.pyplot as plt

A=np.array([1,-1])
B=np.array([7,-1])

L=np.array([0,-1])
M=np.array([1,0])

omat=np.vstack((L,M))

C=omat@A
D=omat@B

E=C+D

F=np.array([1,2])

k=2-E[1]/E[0]

W=np.array([0,k])
Y=2*F-W

J=np.vstack(([1,-1],[7,-1]))
K=np.array((2,8))

X=np.linalg.inv(J)@K

N=np.vstack(([1,-1],[7,-1]))
O=np.array([-4,2])

Z=np.linalg.inv(N)@O

plt.plot([W[0],X[0]],[W[1],X[1]],label='$AB$')
plt.plot([X[0],Y[0]],[X[1],Y[1]],label='$BC$')
plt.plot([Y[0],Z[0]],[Y[1],Z[1]],label='$CD$')
plt.plot([Z[0],W[0]],[Z[1],W[1]],label='$DA$')
plt.plot([W[0],Y[0]],[W[1],Y[1]],label='$AC$')
plt.plot([X[0],Z[0]],[X[1],Z[1]],label='$BD$')
plt.plot([-2,0],[0,2])
plt.plot([-3/7,0],[0,3])

plt.plot(W[0],W[1],'o')
plt.text(W[0]*(1+0.1),W[1]*(1-0.1),'A')
plt.plot(X[0],X[1],'o')
plt.text(X[0]*(1+0.1),X[1]*(1-0.1),'B')
plt.plot(Y[0],Y[1],'o')
plt.text(Y[0]*(1+0.1),Y[1]*(1-0.1),'C')
plt.plot(Z[0],Z[1],'o')
plt.text(Z[0]*(1+0.1),Z[1]*(1-0.1),'D')
plt.plot(F[0],F[1],'o')
plt.text(F[0]*(1+0.1),F[1]*(1-0.1),'P')
plt.plot(-2,0,'o')
plt.plot(0,2,'o')
plt.plot(0,3,'o')
plt.plot(-3/7,0,'o')

print(X-W)
print(Y-X)
print(Z-Y)
print(W-Z)
plt.grid()
plt.axis('equal')
plt.show()
