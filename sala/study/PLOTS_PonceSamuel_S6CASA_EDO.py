import numpy as np
import matplotlib.pylab as plt


#Creo mi array con la función analítica
def fun(a):
  return np.exp(-a)

euler=np.genfromtxt("myout_euler_EDO.dat")
rk=np.genfromtxt("myout_rk4_EDO.dat")
eulerh1 = np.genfromtxt("myout_eulerh1_EDO.dat")
rkh1 = np.genfromtxt("myout_rk4h1_EDO.dat")
eulerh2 = np.genfromtxt("myout_eulerh2_EDO.dat")
rkh2 = np.genfromtxt("myout_rk4h2_EDO.dat")

x = np.linspace(0.0, 2.0, 200)
f = fun(x)

x1 = np.linspace(0.0, 2.0, 100)
f1 = fun(x1)
x2 = np.linspace(0.0, 2.0, 10000)
f2 = fun(x2)

#Errores
#Euler
err_e = (abs(f-euler)/(f))*100
err_eh1 = (abs(f1-eulerh1)/(f1))*100
err_eh2 = (abs(f2-eulerh2)/(f2))*100

#RK4
err_rk4 = (abs(f-rk)/(f))*100
err_rk4h1 = (abs(f1-rkh1)/(f1))*100
err_rk4h2 = (abs(f2-rkh2)/(f2))*100


#Plots
#rk4.pdf
fig, ((ax1, ax2),(ax3, ax4)) = plt.subplots(2, 2, layout="constrained")

ax1.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
ax1.plot(x, err_rk4, color="#C827F5")
ax1.set_xlabel('t')
ax1.set_ylabel('Error(%)')
ax1.set_title("Error del método de Runge-Kutta 4")

ax2.plot(x, f, label= "Analítico", color="#F5A627")
ax2.plot(x, euler, label="Runge-Kutta 4", linestyle='-.', color="#C827F5")
ax2.set_xlabel('t')
ax2.set_ylabel('f(t)')
ax2.legend()
ax2.set_title("Solución con Runge-Kutta 4")

ax3.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
ax3.plot(x1, err_rk4h1, color="#C827F5")
ax3.set_xlabel('t')
ax3.set_ylabel('Error(%)')
ax3.set_title("Error con N=100")

ax4.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
ax4.plot(x2, err_rk4h2, color="#C827F5")
ax4.set_xlabel('t')
ax4.set_ylabel('Error(%)')
ax4.set_title("Error con N=10000")

plt.savefig("rk4_EDO.pdf")
plt.close()

#euler.pdf
fig, ((ax1, ax2),(ax3,ax4)) = plt.subplots(2, 2, layout="constrained")

ax1.plot(x, err_e, color="#54F527")
ax1.set_xlabel('t')
ax1.set_ylabel('Error(%)')
ax1.set_title("Error del método de Euler")

ax2.plot(x, f, label= "Analítico", color="#F5A627")
ax2.plot(x, euler, label="Euler", linestyle='--', color="#54F527")
ax2.set_xlabel('t')
ax2.set_ylabel('f(t)')
ax2.legend()
ax2.set_title("Solución con Euler")

ax3.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
ax3.plot(x1, err_eh1, color="#54F527")
ax3.set_xlabel('t')
ax3.set_ylabel('Error(%)')
ax3.set_title("Error con N=100")

ax4.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
ax4.plot(x2, err_eh2, color="#54F527")
ax4.set_xlabel('t')
ax4.set_ylabel('Error(%)')
ax4.set_title("Error con N=10000")


plt.savefig("euler_EDO.pdf")
plt.close()

#all.pdf
fig, ((ax1, ax2)) = plt.subplots(1, 2, layout="constrained")

ax1.plot(x, err_e, label="Euler", linestyle='--', color="#54F527")
ax1.plot(x, err_rk4, label="Runge-Kutta 4", linestyle='-.', color="#C827F5")
ax1.set_xlabel('t')
ax1.set_ylabel('Error(%)')
ax1.legend()
ax1.set_title("Errores ambos métodos")

ax2.plot(x, f, label= "Analítico", color="#F5A627")
ax2.plot(x, euler, label="Euler", linestyle='--', color="#54F527")
ax2.plot(x, rk, label="Runge-Kutta 4", linestyle='-.', color="#C827F5")
ax2.set_xlabel('t')
ax2.set_ylabel('f(t)')
ax2.legend()
ax2.set_title("Soluciones ambos métodos")

plt.savefig("all_EDO.pdf")
plt.close()

