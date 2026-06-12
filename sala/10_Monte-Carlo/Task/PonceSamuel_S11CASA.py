import numpy as np
import matplotlib.pylab as plt



#Ejercicio 1

# Use esta funcion que recibe un valor x y retorna un valor f(x) donde f es la forma funcional que debe seguir su distribucion.
def mifun(x):
	x_0 = 3.0
	a = 0.01
	return np.exp(-(x**2))/((x-x_0)**2 + a**2)

#Intervalo de la función
c = -4.0
d = 4.0

# 1) Dentro de una funcion que reciba como parametros el numero de pasos y el sigma de la distribucion gausiana que va a usar
# para calcular el paso de su caminata, implemente el algortimo de Metropolis-Hastings.

def metro1(n, sigma):
	f = np.zeros(n)
	rng = np.random.default_rng()
	x_old = rng.uniform(c, d)
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
			elif (beta>alpha):
				f[i] = x_old
		else:
			f[i] = x_old
	return f


# 2) Haga un histograma de los valores de x obtenidos y grafique en la misma grafica, la funcion de distribucion de probabilidad fx (Ojo, aca debe normalizar). #

#Creo el array de la función en el intervalo dado
s = np.linspace(c,d,300)
fs = mifun(s)

#Creo mi array dado por metrópolis-hastings
sigma = 0.1
pasos = 500000
array = metro1(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("graph.pdf")


# 3) Cuando haya verificado que su codigo funciona, use los siguientes parametros:
# sigma = 5.0, pasos =100000
sigma = 5.0
pasos = 100000
array = metro1(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("graph1.pdf")

# sigma = 0.2, pasos =100000
sigma = 0.2
pasos = 100000
array = metro1(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("graph2.pdf")

# sigma = 0.01, pasos =100000
sigma = 0.01
pasos = 100000
array = metro1(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("graph3.pdf")

# sigma = 0.1, pasos =1000
sigma = 0.1
pasos = 1000
array = metro1(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("graph4.pdf")

# sigma = 0.1, pasos = 100000
sigma = 0.1
pasos = 100000
array = metro1(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("graph5.pdf")

# OPCIONAL: este puede ser muy demorado dependiendo del computador: sigma = 0.1, pasos =500000
sigma = 0.1
pasos = 500000
array = metro1(pasos, sigma)

fig, ax = plt.subplots()

ax.plot(s, fs/np.trapezoid(fs,s), label="Función")
plt.hist(array, bins="auto", density = "True", label="Metropolis-Hastings")
plt.title(f"Sigma = {sigma}, Pasos = {pasos}")
plt.legend()
#Guardo cómo se ve
plt.savefig("graph6.pdf")

# Al ejecutar el codigo, este debe generar 6 (o 5) graficas, una para cada vez que se llama a la funcion con los parametros antes mencionados.



#Ejercicio 2

# 1) lea los datos de resorte.dat y almacenelos.

# Los datos corresponden a las posiciones en x de un oscilador (masa resorte) en funcion del tiempo.
# La ecuacion de movimiento esta dada por:
# x(t)=a*np.exp(-gamma*t)*np.cos(omega*t)
# Donde a, gamma, y omega son parametros.

# 2) Implemente un algoritmo que le permita, por medio de estimacion bayesiana de parametros,
# encontrar los MEJORES parametros (a, gamma y omega) tales que la ecuacion ajuste los datos. Para esto debe:

# 2a.) definir una funcion que reciba los parametros que se busca estimar y los datos de tiempo y retorne el modelo

# 2b.) Definir una funcion que retorne la funcion de verosimilitud

# 2c.) Caminata

#condiciones iniciales
aini=7.12
gammaini=0.69
omegaini=18.32

#numero de pasos
iteraciones=100000


# 2d.) Seleccione los mejores parametros E IMPRIMA UN MENSAJE QUE DIGA: "LOS MEJORES PARAMETROS SON a=... gamma=... Y omgega=..."

# 2f.) Grafique sus datos originales y su modelo con los mejores parametros. Guarde su grafica sin mostrarla en Resorte.pdf

# 3) SABIENDO QUE omega=np.sqrt(k/m), IMPRIMA UN MENSAJE DONDE EXPLIQUE SI PUEDE O NO DETERMINAR k Y m DE MANERA INDIVIDUAL USANDO EL METODO ANTERIOR. JUSTIFIQUE BIEN SU RESPUESTA (PUEDE ADEMAS HACER PRUEBAS CON EL CODIGO PARA RESPONDER ESTA PREGUNTA).


