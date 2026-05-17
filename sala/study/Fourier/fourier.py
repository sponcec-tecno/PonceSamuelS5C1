#Recupere la imagen original a partir de la fase y la amplitud de la transformada de fourier (archivos amplitude.dat y phase.dat).
#Recuerde que la transformada de fourier tiene una parte real y una imaginaria
#y recuerde tambien que un numero complejo se puede escribir a partir de la fase y la magnitud que son los datos que usted tiene
#(http://webpages.ursinus.edu/lriley/ref/complex/node1.html)
import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import ifft2

#1)Descargue los datos de fase y magnitud
magnitude = np.genfromtxt('magnitude.dat')
phase = np.genfromtxt('phase.dat')

#2) construya la transformada de fourier
m = len(magnitude)
n = len(magnitude[0])
fft = np.zeros((m,n), dtype=complex)

for i in range(m):
	for h in range(n):
		fft[i,h] = (magnitude[i,h]*np.cos(phase[i,h]))+(magnitude[i,h]*np.sin(phase[i,h]))*1j

#3) Obtenga la imagen haciendo la transformada inversa
ifft = ifft2(fft)

fig, ax = plt.subplots()
ax.imshow(ifft.real)
plt.title("Imagen recuperada")
plt.savefig("image.jpg")
plt.close()
