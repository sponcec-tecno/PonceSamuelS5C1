import numpy as np
import matplotlib.pylab as plt

#Creo mi array con la función analítica
def fun(a):
  return np.exp(-a)

euler=np.genfromtxt("myout_e.dat")
rk=np.genfromtxt("myout_rk.dat")

x = np.linspace(0.0, 2.0, 200)
f = fun(x)

#Errores
#Euler
err_e = (abs(f-euler)/(f))*100

#RK4
err_rk4 = (abs(f-rk)/(f))*100

#Plot
#All
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

plt.savefig("all.pdf")
plt.close()
