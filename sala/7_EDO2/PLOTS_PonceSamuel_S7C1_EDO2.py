import numpy as np
import matplotlib.pylab as plt

#Dinámica de la partícula
#Tiempos
t = np.linspace(0.0, 0.3, 200)
#Teórico
A = 0.1
k = 50
m = 0.2
w = np.sqrt(k/m)

x_teo = A*np.cos(w*t)
v_teo = -w*A*np.sin(w*t)
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
ax.plot(t, v_teo, label="Teórico")#Comparé con el teórico, eso sí, teniendo en cuenta que están desfasados
ax.set_xlabel('Tiempo(s)')
ax.set_ylabel('Velocidad(m/s)')
ax.set_title("Velocidad en función del tiempo")
ax.legend()

plt.savefig("v.pdf")
plt.close()


#Posición
fig, ax = plt.subplots()

ax.plot(t, x_e, color="#F4A20B", label="Euler")
ax.plot(t, x_lf, color="#5DF40B", label="Leap-Frog")
ax.plot(t, x_teo, label="Teórico")#Comparé con el teórico, eso sí, teniendo en cuenta que están desfasados
ax.set_xlabel('Tiempo(s)')
ax.set_ylabel('Posición(m)')
ax.set_title("Posición en función del tiempo")
ax.legend()

plt.savefig("x.pdf")
plt.close()

#Errores
err_e = 100*np.abs(x_teo-x_e)/x_teo
err_lf = 100*np.abs(x_teo-x_lf)/x_teo
#Los grafico
fig, ((ax1, ax2)) = plt.subplots(2, 1, layout="constrained")

ax1.plot(t[:-30], err_e[:-30], color="#F4A20B", label="Euler")
ax1.set_xlabel('Tiempo(s)')
ax1.set_ylabel('Error(%)')
ax1.set_title("Erorr de euler en función del tiempo")

ax2.plot(t[:-30], err_lf[:-30], color="#5DF40B", label="Leap-Frog")
ax2.set_xlabel('Tiempo(s)')
ax2.set_ylabel('Error(%)')
ax2.set_title("Erorr del Leap-frog  en función del tiempo")

plt.savefig("err.pdf")
plt.close()
