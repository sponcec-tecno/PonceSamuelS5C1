//Lado derecho de la ecuación 1 y 2.
//Implementar las condiciones iniciales.
//Inicializo los arrays con mis condiciones iniciales
//Uso un for para llenar ambos arrays

#include <array>
#include <fstream>
#include <iostream>
#include <math.h>
#include <functional>
#include <string>
#include <map>

const int N = 200;

//double f();
void rk4(double h, int n, std::array<double, N> & sol, double y_0);
void doc(std::array<double, N> & data, std::string name);

int main(){


	//initial conditions
	double ti = 0.0;
	double tf = 1.0;
	double x0 = 0.1;
	double v0 = 0.0;

	std::map<std::string, double> p;//the parameters/constants for modify the system
	p["k"] = 50;
	p["m"] = 0.2;


	//elements for euler
	double N_double = static_cast<double>(N);
	double h = (tf-ti)/(N_double-1.0);//h for euler
	std::array<double, N> x;//saving the points for position
	std::array<double, N> v;//saving the points for velocity

	//solving the system with euler
	x[0] = x0;
	v[0] = v0;

        for (int i = 1; i<N; ++i){
		x[i] = x[i-1]+(h*v[i-1]);
		v[i] = v[i-1]+(h*(-p["k"]/p["m"])*x[i-1]);
	}

	


	//making my data
	doc(v, "myout_v_e.dat");
	doc(x, "myout_x_e.dat");

	return 0;
}



void doc(std::array<double, N> & data, std::string name){
    // Abro el archivo en modo escritura
    std::ofstream outfile;
    outfile.open(name);
    for (double n : data){
        outfile << n << "\n";
    }
    //Cierro el archivo
    outfile.close();
}
