import numpy as np
import matplotlib.pyplot as plt

Tf = np.genfromtxt("Tf.dat")
n = len(Tf)
N = n/100
x = np.linspace(0, n, num=n, dtype="int")

for i in range(N):
	T = Tf[:]

b = np.where(Tf=!50)

print(x)

fig, ax = plt.subplots()

for i in range(N*N):
	if(b):
		

ax.plot(x, Tf)

#plt.title("Solución para seis tiempos distintos")
plt.savefig("sol_difussion.pdf")
plt.close()

