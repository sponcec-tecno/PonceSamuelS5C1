import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec


#Recibo los datos
T0 = np.genfromtxt("T0.dat")
T1 = np.genfromtxt("T1.dat")
T2 = np.genfromtxt("T2.dat")
T3 = np.genfromtxt("T3.dat")


fig = plt.figure()
#Preparo el espacio en donde estará cada gráfica
gs1 = gridspec.GridSpec(2, 2)
ax1 = fig.add_subplot(gs1[0])
ax2 = fig.add_subplot(gs1[1])
ax3 = fig.add_subplot(gs1[2])
ax4 = fig.add_subplot(gs1[3])


#Mi paleta de colores
color = "rainbow"


#Ploteo las placas
im1 = ax1.matshow(T0, cmap=color)
plt.colorbar(im1, label="T(°C)", format="{x:.6g}")
ax1.set_title("0 seg")
ax1.set_xlabel("x(m)")
ax1.set_ylabel("y(m)")

im2 = ax2.matshow(T1, cmap=color)
plt.colorbar(im2, label="T(°C)", format="{x:.6g}")
ax2.set_title("100 seg")
ax2.set_xlabel("x(m)")
ax2.set_ylabel("y(m)")

im3 = ax3.matshow(T2, cmap=color)
plt.colorbar(im3, label="T(°C)", format="{x:.6g}")
ax3.set_title("1000 seg")
ax3.set_xlabel("x(m)")
ax3.set_ylabel("y(m)")

im4 = ax4.matshow(T3, cmap=color)
plt.colorbar(im4, label="T(°C)", format="{x:.6g}")
ax4.set_title("2500 seg")
ax4.set_xlabel("x(m)")
ax4.set_ylabel("y(m)")


#Organizo
gs1.tight_layout(fig, rect=[0, 0, 1.0, 0.95])

#Pongo título y guardo en el documento
fig.suptitle("Placa en cuatro momentos")
plt.savefig("sol_difussion.pdf")
plt.close()
