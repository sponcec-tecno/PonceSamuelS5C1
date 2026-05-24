import numpy as np
import matplotlib.pylab as plt

#Dinámica de la partícula
#Tiempos
#Ahora con amortiguamiento
xc_e = np.genfromtxt("myout_xc_e.dat")
vc_e = np.genfromtxt("myout_vc_e.dat")
xc_rk4 = np.genfromtxt("myout_xc_rk4.dat")
vc_rk4 = np.genfromtxt("myout_vc_rk4.dat")
t_c = np.genfromtxt("tc.dat")

#Grafico posición y velocidad
#fig, ((ax1, ax2)) = plt.subplots(2,1, layout="constrained")

#ax1.plot(t_c,xc_e, color="#F4A20B", label="Euler")
#ax1.set_xlabel('Tiempo(s)')
#ax1.set_ylabel('Posición')
#ax1.set_title("Posición del resorte con amortiguamiento")

#ax2.plot(t_c,vc_e, color="#F4A20B", label="Euler")
#ax2.set_xlabel('Tiempo(s)')
#ax2.set_ylabel('Velocidad')
#ax2.set_title("Velocidad del resorte con amortiguamiento")
fig, ax = plt.subplots()
ax.plot(t_c,xc_e, color = "#F4A20B", linewidth=0.5)
ax.plot(t_c,xc_rk4, color = "red", linewidth=0.5)

plt.savefig("xv_c.pdf")
plt.close()
