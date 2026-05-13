import numpy as np
import matplotlib.pylab as plt

#Dinámica de la partícula
#Tiempos
t = np.linspace(0.0, 1.0, 200)
#Recibo los datos
x_e = np.genfromtxt("myout_x_e.dat")
v_e = np.genfromtxt("myout_v_e.dat")
x_lf = np.genfromtxt("myout_x_lf.dat")
v_lf = np.genfromtxt("myout_v_lf.dat")


#Euler
#Velocidad
fig, ax = plt.subplots()

ax.plot(t, v_e, color="#F4A20B", label="Euler")
ax.plot(t, v_lf, color="#5DF40B", label="Leap-Frog")
ax.set_xlabel('Tiempo(s)')
ax.set_ylabel('Velocidad(m/s)')
ax.set_title("Velocidad en función del tiempo")
ax.legend()

plt.savefig("v.pdf")
plt.close()


#Posición
fig, ax = plt.subplots()

ax.plot(t, x_e, color="#F4A20B", label="Euler")
ax.plot(t, v_lf, color="#5DF40B", label="Leap-Frog")
ax.set_xlabel('Tiempo(s)')
ax.set_ylabel('Posición(m)')
ax.set_title("Posición en función del tiempo")
ax.legend()

plt.savefig("x.pdf")
plt.close()
