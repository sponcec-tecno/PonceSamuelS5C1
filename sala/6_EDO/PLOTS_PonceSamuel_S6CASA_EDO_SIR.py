import numpy as np
import matplotlib.pylab as plt


#Creo mi array con el tiempo
S=np.genfromtxt("myout_S_SIR.dat")
I=np.genfromtxt("myout_I_SIR.dat")
R=np.genfromtxt("myout_R_SIR.dat")
N = S + I + R

x = np.linspace(0.0, 60.0, 200)


#Plots
fig, ((ax1, ax2)) = plt.subplots(2, 1, layout="constrained")

ax1.plot(x, S, label="Susceptible", color="#F4F00B")
ax1.plot(x, I, label="Infected", color="#C82909")
ax1.plot(x, R, label="Recovered", color="#0BF41B")
ax1.set_xlabel('Tiempo(s)')
ax1.set_ylabel('Número de personas')
ax1.legend()
ax1.set_title("Evolución de la población")

ax2.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
ax2.plot(x, N, color="#27E4F5")
ax2.set_xlabel('Tiempo(s)')
ax2.set_ylabel('Número de personas')
ax2.set_title("Población en el sistema")

plt.savefig("euler_SIR.pdf")
plt.close()
