//Construir el array de posición
//Construir condición inicial: llenar un arreglo de 100 puntos para x
//Construir el primer paso de tiempo u¹
//Construir las soluciones para amplitud
//En el tiempo total debo sacar seis soluciones "arrays"

#include <iostream>
#include <map>
#include <array>
#include <fstream>
#include <cmath>

const int N = 101;
void doc(std::array<double, N> & data, std::string name);

int main(){

	//constantes
	std::map <std::string, double> p;
	p["c"] = 300;
	p["L"] = 2;//metros

	//condiciones iniciales
	double v0 = 0.0;
	double tf = 0.1;
	double ti = 0.0;

	//condiciones de frontera
	double xi = 0.0;
	double xf = 0.0;

	//array de x0
	std::array<double, N> x0;
	x0[0] = xi;
	x0[N-1] = xf;
	double h = p["L"]/(N-1);//para calcular los x
	for (int i = 1; i<(N-1)/2; ++i){//de pa'rriba
		x0[i] = 0.1*i*h;
	}
	x0[(N-1)/2] = 0.1;
	for (int i = ((N-1)/2)+1; i<N-1; ++i){//de pa'bajo
                x0[i] = (-0.1*i*h)+0.2;
        }

	//doc(x0, "x.dat");

	double dx = x0[1]-x0[0];
	double dt = 0.5*dx/p["c"];

	//array de x1
	std::array<double, N> x1;
	x1[0] = 0.0;
	x1[N-1] = 0.0;
	for (int i = 1; i < N-1; ++i){
		x1[i] = x0[i]+0.5*std::pow(p["c"]*dt/dx,2)*(x0[i+1]-2*x0[i]+x0[i-1]);
	}

	//Opening the file
	std::ofstream outfile;
	outfile.open("x.dat");
	//Fill it with the array
	for (double n : x1){
		outfile << n << "\n";
	}
	//I close it
	outfile.close();

	return 0;
}

void doc(std::array<double, N> & data, std::string name){
    //Opening the file
    std::ofstream outfile;
    outfile.open(name);
    //Fill it with the array
    for (double n : data){
        outfile << n << "\n";
    }
    //I close it
    outfile.close();
}
