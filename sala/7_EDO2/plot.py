import numpy as np
import matplotlib.pylab as plt

#Recibo los datos
x_e = np.genfromtxt("myout_x_e.dat")
vx_e = np.genfromtxt("myout_vx_e.dat")
y_e = np.genfromtxt("myout_y_e.dat")
vy_e = np.genfromtxt("myout_vy_e.dat")


#Euler
#Posición
fig, ax = plt.subplots()
p = 80
ax.plot(x_e, y_e, color="#F4A20B", label="Euler")
ax.set_xlabel('Posición en x')
ax.set_ylabel('Posición en y')
ax.set_title("Movimiento xy de la tierra")
ax.legend()

plt.savefig("motion.pdf")
plt.close()
