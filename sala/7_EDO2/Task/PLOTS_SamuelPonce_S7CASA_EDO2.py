import numpy as np
import matplotlib.pylab as plt


#Sin amortiguamiento
#Datos
x_e = np.genfromtxt("x_e_spring.dat")
v_e = np.genfromtxt("v_e_spring.dat")
x_lf = np.genfromtxt("x_lf_spring.dat")
v_lf = np.genfromtxt("v_lf_spring.dat")
t = np.genfromtxt("t_spring.dat")
#Teórico
A = 0.1
k = 50
m = 0.2
w = np.sqrt(k/m)

x_teo = A*np.cos(w*t)
v_teo = -w*A*np.sin(w*t)

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

plt.savefig("v_spring.pdf")
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

plt.savefig("x_spring.pdf")
plt.close()

#Errores
err_e = x_teo-x_e
err_lf = x_teo-x_lf
#Los grafico
fig, ((ax1, ax2)) = plt.subplots(2, 1, layout="constrained")

ax1.plot(t, err_e, color="#F4A20B", label="Euler")
ax1.set_xlabel('Tiempo(s)')
ax1.set_ylabel('Error(%)')
ax1.set_title("Erorr de euler en función del tiempo")

ax2.plot(t, err_lf, color="#5DF40B", label="Leap-Frog")
ax2.set_xlabel('Tiempo(s)')
ax2.set_ylabel('Error(%)')
ax2.set_title("Erorr de Leap-frog  en función del tiempo")

plt.savefig("err_spring.pdf")
plt.close()


#Ahora con amortiguamiento
xc_e = np.genfromtxt("xc_e_spring.dat")
vc_e = np.genfromtxt("vc_e_spring.dat")
xc_rk4 = np.genfromtxt("xc_rk4_spring.dat")
vc_rk4 = np.genfromtxt("vc_rk4_spring.dat")

#Grafico posición y velocidad
fig, ((ax1, ax2)) = plt.subplots(2,1, layout="constrained")

ax1.plot(t,xc_e, color="#F4A20B", label="Euler")
ax1.plot(t,xc_rk4, color="#0B55F4", label="RK4")
ax1.axhline(y=xc_e[0], color='r', linestyle='--', linewidth=0.5)
ax1.axhline(y=-xc_e[0], color='r', linestyle='--', linewidth=0.5)
ax1.set_xlabel('Tiempo(s)')
ax1.set_ylabel('Posición(m)')
ax1.legend()
ax1.set_title("Posición del resorte")

ax2.plot(t,vc_e, color="#F4A20B", label="Euler")
ax2.plot(t,vc_rk4, color="#0B55F4", label="RK4")
ax2.set_xlabel('Tiempo(s)')
ax2.set_ylabel('Velocidad(m/s)')
ax2.legend()
ax2.set_title("Velocidad del resorte")

plt.savefig("xvc_spring.pdf")
plt.close()
