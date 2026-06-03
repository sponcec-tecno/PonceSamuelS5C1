import numpy as np
import matplotlib.pyplot as plt

Tf = np.genfromtxt("Tf.dat")
#print(Tf)
#n = len(Tf)
#N = n/100
#x = np.linspace(0, n, num=n, dtype="int")

#for i in range(N):
#	T = Tf[:]

#b = np.where(Tf=!50)

#print(x)

#fig, ax = plt.subplots()

#ax.plot(x, Tf)

#plt.title("Solución para seis tiempos distintos")
#plt.savefig("sol_difussion.pdf")
#plt.close()

plt.matshow(Tf)
plt.colorbar()
plt.savefig("sol_difussion.pdf")
plt.close()
