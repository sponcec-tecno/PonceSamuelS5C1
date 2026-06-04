import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import matplotlib.colors as col
import matplotlib.gridspec as gridspec

T0 = np.genfromtxt("T0.dat")
T1 = np.genfromtxt("T1.dat")
T2 = np.genfromtxt("T2.dat")
T3 = np.genfromtxt("T3.dat")


fig = plt.figure()

gs1 = gridspec.GridSpec(2, 2)
ax1 = fig.add_subplot(gs1[0])
ax2 = fig.add_subplot(gs1[1])
ax3 = fig.add_subplot(gs1[2])
ax4 = fig.add_subplot(gs1[3])

#Donde varian mis datos
#norm = col.Normalize(vmin=50.0, vmax=100.0)

#Mi paleta de colores
color = "rainbow"

#Ploteo las placas
im1 = ax1.matshow(T0, cmap=color)
plt.colorbar(im1)
ax1.set_title("0 seg")

im2 = ax2.matshow(T1, cmap=color)
plt.colorbar(im2)
ax2.set_title("100 seg")

im3 = ax3.matshow(T2, cmap=color)
plt.colorbar(im3)
ax3.set_title("1000 seg")

im4 = ax4.matshow(T3, cmap=color)
plt.colorbar(im4)
ax4.set_title("2500 seg")

#Barra de color
#cax = plt.axes([0.85, 0.1, 0.075, 0.8])
#map = cm.ScalarMappable(norm=norm, cmap=color)

#plt.colorbar(mappable=map, cax=cax)

#Organizo
gs1.tight_layout(fig, rect=[0, 0, 1.0, 0.95])

fig.suptitle("Placa en cuatro momentos")
plt.savefig("sol_difussion.pdf")
plt.close()

fig, ax = plt.subplots()

ax.plot(T3[50, :], color="red")
#ax.plot(T0[50, :])
plt.savefig("zoom.pdf")
plt.close()
