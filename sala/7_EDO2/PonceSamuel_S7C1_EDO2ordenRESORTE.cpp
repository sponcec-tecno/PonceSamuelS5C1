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


	//Euler
	//elements for euler
	double N_double = static_cast<double>(N);
	double h = (tf-ti)/(N_double-1.0);//h for euler
	std::array<double, N> x_e;//saving the points for position
	std::array<double, N> v_e;//saving the points for velocity

	//solving the system with euler
	x_e[0] = x0;
	v_e[0] = v0;

        for (int i = 1; i<N; ++i){
		x_e[i] = x_e[i-1]+(h*v_e[i-1]);
		v_e[i] = v_e[i-1]+(h*(-p["k"]/p["m"])*x_e[i-1]);
	}


	//Leap-Frog
	//preparing things for Leap-Frog
	std::array<double, N> x_lf;//saving the points for position
	std::array<double, N> v_lf;//saving the points for velocity

	//solving with leap-frog
	x_lf[0] = x0;
	v_lf[0] = v0+(0.5*h*(-p["k"]/p["m"])*x0);

        for (int i = 1; i<N; ++i){
                x_lf[i] = x_lf[i-1]+(h*v_lf[i-1]);
                v_lf[i] = v_lf[i-1]+(h*(-p["k"]/p["m"])*x_lf[i-1]);
        }

	//making my data
	doc(v_e, "myout_v_e.dat");
	doc(x_e, "myout_x_e.dat");
	doc(v_lf, "myout_v_lf.dat");
	doc(x_lf, "myout_x_lf.dat");

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
