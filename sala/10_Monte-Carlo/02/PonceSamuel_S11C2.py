#Ejercicio 1 Terminar lo que hizo en clase + dos preguntas adicionales (en mayusculas en el texto)

import numpy as np
import matplotlib.pylab as plt


# 1) lea los datos de resorte.dat y almacenelos.
x,y = np.genfromtxt("resorte.dat", unpack="True") #usecols= (0,1))

#Por si los quieres ver
#plt.scatter(x, y)
#plt.savefig("experiment.pdf")
#plt.close()

# Los datos corresponden a las posiciones en x de un oscilador (masa resorte) en funcion del tiempo. La ecuacion de movimiento esta dada por
# xt=a*np.exp(-gamma*t)*np.cos(omega*t)
# Donde a, gamma, y omega son parametros.

# 2) Implemente un algoritmo que le permita, por medio de estimacion bayesiana de parametros, encontrar los parametros correspondientes a los datos d. Para esto debe:
# 2a.) definir una funcion que reciba los parametros que se busca estimar y los datos de tiempo y retorne el modelo  

#Recibe el tiempo, y un array p(parámetros) de [a, gamma, omega]
def mod(t, p):
	return p[0]*np.exp(-p[1]*t)*np.cos(p[2]*t)


# 2b.) Definir una funcion que retorne la funcion de verosimilitud

def vero(y_mod, y_exp, n):
	aux = (y_mod-y_exp)*(y_mod-y_exp)
	chi = np.sum(aux)/n
#	print(chi/n)
	return np.exp(-0.5*chi)

# 2c.) Caminata

#condiciones iniciales
aini=7.12
gammaini=0.69
omegaini=18.32

#numero de pasos
iteraciones=100000


params_old = np.zeros((iteraciones, 3))
params_new = np.zeros((iteraciones, 3))
params_save = np.zeros((iteraciones, 3)) #Aquí es en donde guardaré los que van siendo elegidos

#Lleno en primer lugar params_old con los iniciales
params_old[0,0] = aini
params_old[0,1] = gammaini
params_old[0,2] = omegaini


for i in range(iteraciones):
	rng = np.random.default_rng()
	#Doy un paso
	#Para a
	a_new = rng.normal(loc = params_old[i,0], scale = 1.0)
	#Para omega
	omega_new = rng.normal(loc = params_old[i,1], scale = 0.33)
	#Para gamma
	gamma_new = rng.normal(loc = params_old[i,2], scale = 0.2)

	#Los guardo en params_new
	params_new[i,0] = a_new
	params_new[i,1] = gamma_new
	params_new[i,2] = omega_new

	#Calculo el modelo viejo y nuevo
	mod_old = mod(x, params_old[i,:])
	mod_new = mod(x, params_new[i,:])

	#Calculo los L
	L_old = vero(mod_old, y, iteraciones)
	L_new = vero(mod_new, y, iteraciones)

	#Comparo y guardo el mejor
	alpha = L_new/L_old
	beta = rng.uniform(0.0, 1.0)

	if alpha > 1.0:
		params_save[i,:] = params_new[i,:]
		params_old[i+1,:] = params_new[i]
	elif


print(params_old[0,:])
# 2d.) Seleccione los mejores parametros E IMPRIMA UN MENSAJE QUE DIGA: "LOS MEJORES PARAMETROS SON a=... gamma=... Y omgega=..."

# 2f.) Grafique sus datos originales y su modelo con los mejores parametros. Guarde su grafica sin mostrarla en Resorte.pdf

# 3) SABIENDO QUE omega=np.sqrt(k/m), IMPRIMA UN MENSAJE DONDE EXPLIQUE SI PUEDE O NO DETERMINAR k Y m DE MANERA INDIVIDUAL USANDO EL METODO ANTERIOR. JUSTIFIQUE BIEN SU RESPUESTA (PUEDE ADEMAS HACER PRUEBAS CON EL CODIGO PARA RESPONDER ESTA PREGUNTA).

