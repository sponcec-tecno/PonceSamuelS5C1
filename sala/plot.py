import numpy as np
import matplotlib.pylab as plt

def fun(a):
  return np.exp(-a)

#Con n = 200 se tiene la siguiente solución
euler=np.genfromtxt("myout_e.dat")
rk=np.genfromtxt("myout_rk.dat")

x = np.linspace(0.0, 2.0, 200)
f = fun(x)

fig, ax = plt.subplots()
ax.plot(x, f, label="Analítico")
ax.plot(x, euler, label="Euler", linestyle='--')
ax.plot(x, rk, label="Runge-Kutta 4", linestyle='-.')
ax.set_xlabel('t')
ax.set_ylabel('f(t)')
ax.legend()
plt.title("Comparación soluciones")
plt.savefig("fig.png")
plt.close()
