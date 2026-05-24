import numpy as np
import matplotlib.pylab as plt

#Recibo los datos
#Euler
xT_e = np.genfromtxt("myout_xT_e.dat")
vxT_e = np.genfromtxt("myout_vxT_e.dat")
yT_e = np.genfromtxt("myout_yT_e.dat")
vyT_e = np.genfromtxt("myout_vyT_e.dat")

xS_e = np.genfromtxt("myout_xS_e.dat")
vxS_e = np.genfromtxt("myout_vxS_e.dat")
yS_e = np.genfromtxt("myout_yS_e.dat")
vyS_e = np.genfromtxt("myout_vyS_e.dat")

#Leap-frog
xT_lf = np.genfromtxt("myout_xT_lf.dat")
vxT_lf = np.genfromtxt("myout_vxT_lf.dat")
yT_lf = np.genfromtxt("myout_yT_lf.dat")
vyT_lf = np.genfromtxt("myout_vyT_lf.dat")

xS_lf = np.genfromtxt("myout_xS_lf.dat")
vxS_lf = np.genfromtxt("myout_vxS_lf.dat")
yS_lf = np.genfromtxt("myout_yS_lf.dat")
vyS_lf = np.genfromtxt("myout_vyS_lf.dat")



#Euler y Leap-Frog
#Posición
fig, ax = plt.subplots()

ax.plot(xT_e, yT_e, color="#0B83F4", label="Tierra_Euler")
ax.plot(xS_e, yS_e, color="#F4A60B", label="Sol_Euler")
ax.plot(xS_lf, yS_lf, color="#F43E0B", label="Sol_Leap-frog")
ax.plot(xT_lf, yT_lf, color="#0BF461", label="Tierra_Leap-frog")
#ax.scatter(0.01671, 0.0, color="red")
ax.set_xlabel('Posición en x')
ax.set_ylabel('Posición en y')
ax.set_title("Movimiento xy de la tierra-sol")
ax.legend()

plt.savefig("motion.pdf")
plt.close()
