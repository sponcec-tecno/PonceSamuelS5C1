import numpy as np
import matplotlib.pylab as plt

#Recibo los datos
#Euler
x_e = np.genfromtxt("myout_x_e.dat")
vx_e = np.genfromtxt("myout_vx_e.dat")
y_e = np.genfromtxt("myout_y_e.dat")
vy_e = np.genfromtxt("myout_vy_e.dat")
#Leap-frog
x_lf = np.genfromtxt("myout_x_lf.dat")
vx_lf = np.genfromtxt("myout_vx_lf.dat")
y_lf = np.genfromtxt("myout_y_lf.dat")
vy_lf = np.genfromtxt("myout_vy_lf.dat")


#Euler y Leap-Frog
#Posición
fig, ax = plt.subplots()
ax.plot(x_e, y_e, color="#F4A20B", label="Euler")
ax.plot(x_lf, y_lf, color="#0BF480", label="Leap-frog")
ax.scatter(0.01671, 0.0, color="red")
ax.set_xlabel('Posición en x')
ax.set_ylabel('Posición en y')
ax.set_title("Movimiento xy de la tierra")
ax.legend()

plt.savefig("motion.pdf")
plt.close()
