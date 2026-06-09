# Ejercicio 1

import numpy as np
import matplotlib.pylab as plt


# Use esta funcion que recibe un valor x y retorna un valor f(x) donde f es la forma funcional que debe seguir su distribucion.
def mifun(x):
	x_0 = 3.0
	a = 0.01
	return np.exp(-(x**2))/((x-x_0)**2 + a**2)

#Extremos del intervalo
a = -4.0
b = 4.0

#Revisaré primero la función
s = np.linspace(a,b, 400)
fs = mifun(s)

#Para guardarla por si la quiere ver
#fig, ax = plt.subplots()

#ax.plot(s, fs)
#plt.title("Forma funcional")
#Guardo cómo se ve
#plt.savefig("funcion.pdf")

# Dentro de una funcion que reciba como parametros el numero de pasos y el sigma de la distribucion gausiana que va a usar para calcular el paso de su caminata, implemente el algortimo de Metropolis-Hastings. Finalmente, haga un histograma de los datos obtenidos y grafique en la misma grafica, la funcion de distribucion de probabilidad fx (Ojo, aca debe normalizar). Guarde la grafica sin mostrarla en un pdf. Use plt.savefig("histograma_"+str(sigma)+"_"+str(pasos)+".pdf"), donde sigma y pasos son los parametros que recibe la funcion.

#Función de Metropolis-Hastings
def metro(n, sigma):
	f = np.zeros(n)
	rng = np.random.default_rng()
	x_old = rng.uniform(a, b)
	for i in range(n):
		x_new = rng.normal(x_old, sigma)
		alpha = mifun(x_new)/mifun(x_old)
		beta = rng.uniform()
		if (alpha > 1.0):
			f[i] = x_new
			x_old = x_new
		elif (alpha < 1.0):
			if  (beta<alpha):
				f[i] = x_new
				x_old = x_new
			elif(beta>alpha):
				f[i] = x_old
		else:
			f[i] = x_old
	return f

# Cuando haya verificado que su codigo funciona, use los siguientes parametros:
# sigma = 5, pasos =100000
sigma = 5
pasos = 100000
array = metro(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("funcion1.pdf")

# sigma = 0.2, pasos =100000
sigma = 0.2
pasos = 100000
array = metro(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("funcion2.pdf")

# sigma = 0.01, pasos =100000
sigma = 0.01
pasos = 100000
array = metro(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("funcion3.pdf")

# sigma = 0.1, pasos =1000
sigma = 0.1
pasos = 1000
array = metro(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("funcion4.pdf")

# sigma = 0.1, pasos =100000
sigma = 0.1
pasos = 100000
array = metro(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("funcion5.pdf")

# este puede ser muy demorado dependiendo del computador: sigma = 0.1, pasos =500000
sigma = 0.1
pasos = 500000
array = metro(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("funcion6.pdf")

# Al ejecutar el codigo, este debe generar 6 (o 5) graficas .pdf una para cada vez que se llama a la funcion.
