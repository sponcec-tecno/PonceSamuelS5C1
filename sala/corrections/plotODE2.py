import numpy as np
import matplotlib.pylab as plt

#Dinámica de la partícula
#Tiempos
t = np.linspace(0.0, 1.0, 200)
#Recibo los datos
s = np.genfromtxt("myout_x_e.dat")
v = np.genfromtxt("myout_v_e.dat")


#Velocidad
fig, ax = plt.subplots()

ax.plot(x, v, color="#F4F00B")
ax.set_xlabel('Tiempo(s)')
ax.set_ylabel('Velocidad(m/s)')
ax.legend()
ax.set_title("Velocidad en función del tiempo")

plt.savefig("v.pdf")
plt.close()


#Posición
fig, ax = plt.subplots()

ax.plot(x, s, color="#F4F00B")
ax.set_xlabel('Tiempo(s)')
ax.set_ylabel('Posición(m)')
ax.legend()
ax.set_title("Posición en función del tiempo")

plt.savefig("x.pdf")
plt.close()
