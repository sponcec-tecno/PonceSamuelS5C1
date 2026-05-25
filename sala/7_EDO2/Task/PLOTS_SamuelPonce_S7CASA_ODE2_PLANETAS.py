import numpy as np
import matplotlib.pylab as plt

#Sol fijo
#Recibo los datos
#Euler
x_e = np.genfromtxt("x_e.dat")
vx_e = np.genfromtxt("vx_e.dat")
y_e = np.genfromtxt("y_e.dat")
vy_e = np.genfromtxt("vy_e.dat")
#Leap-frog
x_lf = np.genfromtxt("x_lf.dat")
vx_lf = np.genfromtxt("vx_lf.dat")
y_lf = np.genfromtxt("y_lf.dat")
vy_lf = np.genfromtxt("vy_lf.dat")

#Euler y Leap-Frog
#Posición
fig, ax = plt.subplots()
ax.plot(x_e, y_e, color="#F4A20B", label="Euler")
ax.plot(x_lf, y_lf, color="#0BF480", label="Leap-frog")
ax.scatter(0.01671, 0.0, color="#F4FC03", label="Sol")
ax.set_xlabel('Posición en x')
ax.set_ylabel('Posición en y')
ax.set_title("Movimiento xy de la tierra")
ax.legend(loc="upper left")

plt.savefig("system_sunfix.pdf")
plt.close()


#Sol móvil
#Euler
xT_e = np.genfromtxt("xT_e.dat")
vxT_e = np.genfromtxt("vxT_e.dat")
yT_e = np.genfromtxt("yT_e.dat")
vyT_e = np.genfromtxt("vyT_e.dat")

xS_e = np.genfromtxt("xS_e.dat")
vxS_e = np.genfromtxt("vxS_e.dat")
yS_e = np.genfromtxt("yS_e.dat")
vyS_e = np.genfromtxt("vyS_e.dat")

#Leap-frog
xT_lf = np.genfromtxt("xT_lf.dat")
vxT_lf = np.genfromtxt("vxT_lf.dat")
yT_lf = np.genfromtxt("yT_lf.dat")
vyT_lf = np.genfromtxt("vyT_lf.dat")

xS_lf = np.genfromtxt("xS_lf.dat")
vxS_lf = np.genfromtxt("vxS_lf.dat")
yS_lf = np.genfromtxt("yS_lf.dat")
vyS_lf = np.genfromtxt("vyS_lf.dat")

#Euler y Leap-Frog
#Tierra y sol separados
fig, ((ax1,ax2)) = plt.subplots(2,1, layout="constrained")

ax1.plot(xS_e, yS_e, color="#F4A60B", label="Sol_Euler")
ax1.plot(xS_lf, yS_lf, color="#F43E0B", label="Sol_Leap-frog")
ax1.set_xlabel('Posición en x')
ax1.set_ylabel('Posición en y')
ax1.set_title("Movimiento xy del Sol")
ax1.legend(loc="upper left")

ax2.plot(xT_e, yT_e, color="#0B83F4", label="Tierra_Euler")
ax2.plot(xT_lf, yT_lf, color="#0BF461", label="Tierra_Leap-frog")
ax2.set_xlabel('Posición en x')
ax2.set_ylabel('Posición en y')
ax2.set_title("Movimiento xy de la Tierra")
ax2.legend(loc="upper left")

plt.savefig("motion_sunmv.pdf")
plt.close()

#Todo el sistema
fig, ax = plt.subplots()

ax.plot(xT_e, yT_e, color="#0B83F4", label="Tierra_Euler")
ax.plot(xS_e, yS_e, color="#F4A60B", label="Sol_Euler")
ax.plot(xS_lf, yS_lf, color="#F43E0B", label="Sol_Leap-frog")
ax.plot(xT_lf, yT_lf, color="#0BF461", label="Tierra_Leap-frog")
ax.set_xlabel('Posición en x')
ax.set_ylabel('Posición en y')
ax.set_title("Movimiento xy de la tierra-sol")
ax.legend(loc="upper left")

plt.savefig("system_sunmv.pdf")
plt.close()
