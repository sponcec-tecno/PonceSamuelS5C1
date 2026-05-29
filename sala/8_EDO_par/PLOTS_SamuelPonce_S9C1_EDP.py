import numpy as np
import matplotlib.pylab as plt

t0 = np.genfromtxt("t0.dat")
t1 = np.genfromtxt("t1.dat")
t2 = np.genfromtxt("t2.dat")
t3 = np.genfromtxt("t3.dat")
t4 = np.genfromtxt("t4.dat")
t5 = np.genfromtxt("t5.dat")
t6 = np.genfromtxt("t6.dat")

xh = np.genfromtxt("xh.dat")

fig, ax = plt.subplots()

ax.plot(xh, t0, label="t0", color = "#F54927")
ax.plot(xh, t1, label="t1"color = "#F5BB27")
ax.plot(xh, t2, label="t2", color = "#CCF527")
ax.plot(xh, t3, label="t3", color = "#27F549")
ax.plot(xh, t4, label="t4", color = "#27DAF5")
ax.plot(xh, t5, label="t5", color = "#7D27F5")
ax.plot(xh, t6, label="t6", color = "#F527EB")

ax.set_xlabel("Longitud")
ax.set_ylabel("Amplitud")
plt.title("Solución para seis tiempos distintos")
plt.savefig("sol_string.pdf")
plt.close()

