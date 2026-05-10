import numpy as np
import matplotlib.pylab as plt


#Creo mi array con el tiempo
x = np.linspace(0.0, 60.0, 200)

#Datos
#euler
S_e=np.genfromtxt("myout_Se_SIR.dat")
I_e=np.genfromtxt("myout_Ie_SIR.dat")
R_e=np.genfromtxt("myout_Re_SIR.dat")
N_e = S_e + I_e + R_e

#rk4
S_rk4=np.genfromtxt("myout_Srk4_SIR.dat")
I_rk4=np.genfromtxt("myout_Irk4_SIR.dat")
R_rk4=np.genfromtxt("myout_Rrk4_SIR.dat")
N_rk4 = S_rk4 + I_rk4 + R_rk4

#Plots
#euler
fig, ((ax1, ax2)) = plt.subplots(2, 1, layout="constrained")

ax1.plot(x, S_e, label="Susceptible", color="#F4F00B")
ax1.plot(x, I_e, label="Infected", color="#C82909")
ax1.plot(x, R_e, label="Recovered", color="#0BF41B")
ax1.set_xlabel('Tiempo(s)')
ax1.set_ylabel('Número de personas')
ax1.legend()
ax1.set_title("Evolución de la población")

ax2.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
ax2.plot(x, N_e, color="#27E4F5")
ax2.set_xlabel('Tiempo(s)')
ax2.set_ylabel('Número de personas')
ax2.set_title("Población en el sistema")

plt.savefig("e_SIR.pdf")
plt.close()

#rk4
fig, ((ax1, ax2)) = plt.subplots(2, 1, layout="constrained")

ax1.plot(x, S_rk4, label="Susceptible", color="#F4F00B")
ax1.plot(x, I_rk4, label="Infected", color="#C82909")
ax1.plot(x, R_rk4, label="Recovered", color="#0BF41B")
ax1.set_xlabel('Tiempo(s)')
ax1.set_ylabel('Número de personas')
ax1.legend()
ax1.set_title("Evolución de la población")

ax2.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
ax2.plot(x, N_rk4, color="#27E4F5")
ax2.set_xlabel('Tiempo(s)')
ax2.set_ylabel('Número de personas')
ax2.set_title("Población en el sistema")

plt.savefig("rk4_SIR.pdf")
plt.close()
