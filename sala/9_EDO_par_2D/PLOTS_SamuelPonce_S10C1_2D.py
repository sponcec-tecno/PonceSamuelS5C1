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

ax1.matshow(T0)
ax1.set_title("0 seg")
ax2.matshow(T1)
ax2.set_title("100 seg")
ax3.matshow(T2)
ax3.set_title("1000 seg")
ax4.matshow(T3)
ax4.set_title("2500 seg")

#Barra de color
cax = plt.axes([0.85, 0.1, 0.075, 0.8])
norm = col.Normalize(vmin=50.0, vmax=100.0)
map = cm.ScalarMappable(norm=norm, cmap="summer")

plt.colorbar(mappable=map, cax=cax)

#Organizo
gs1.tight_layout(fig, rect=[0, 0, 0.9, 0.95])

fig.suptitle("Placa en cuatro momentos")
plt.savefig("sol_difussion.pdf")
plt.close()
