//Lado derecho de la ecuación 1 y 2.
//Implementar las condiciones iniciales.
//Inicializo los arrays con mis condiciones iniciales
//Uso un for para llenar ambos arrays

#include <array>
#include <fstream>
#include <iostream>
#include <cmath>
#include <functional>
#include <string>
#include <map>

const int N = 5000;
void doc(std::array<double, N> & data, std::string name);

int main(){


	//initial conditions
	double ti = 0.0;
	double tf = 10.0;//Años
	double x0 = 1.000003;//UA
	double vx0 = 0.0;
	double y0 = 0.0;
	double vy0 = 6.28;//UA/año
	double xS = 0.01671;//Distancia del Sol al centro del sistema solar
	double yS = 0.0;


	std::map<std::string, double> p;//the parameters/constants for modify the system
	p["G"] = 39.41;//Constante en años, UA y MA.
	p["M"] = 1.0;//Masa del Sol

	//Euler
	//elements for euler
	double h = (tf-ti)/(N-1.0);//h for euler
	std::array<double, N> x_e;//saving the points for xposition
	std::array<double, N> vx_e;//saving the points for xvelocity
	std::array<double, N> y_e;//saving the points for yposition
        std::array<double, N> vy_e;//saving the points for yvelocity


	//solving the system with euler
	x_e[0] = x0;
	vx_e[0] = vx0;
	y_e[0] = y0;
	vy_e[0] = vy0;
	double r = 0.0;

	for (int i = 1; i<N; ++i){
		r = std::sqrt(std::pow(x_e[i-1]-xS,2.0)+std::pow(y_e[i-1]-yS,2.0));
		vx_e[i] = vx_e[i-1]+(h*-((x_e[i-1]-xS)*p["G"]*p["M"]/(std::pow(r,3.0))));
                vy_e[i] = vy_e[i-1]+(h*-((y_e[i-1]-yS)*p["G"]*p["M"]/(std::pow(r,3.0))));
		x_e[i] = x_e[i-1]+(h*vx_e[i-1]);
                y_e[i] = y_e[i-1]+(h*vy_e[i-1]);
	}


	//Leap-Frog
	//preparing things for Leap-Frog
	std::array<double, N> x_lf;//saving the points for x-position
	std::array<double, N> vx_lf;//saving the points for x-velocity
	std::array<double, N> y_lf;//saving the points for x-position
        std::array<double, N> vy_lf;//saving the points for x-velocity

	//solving with leap-frog
	x_lf[0] = x0;
	v_lf[0] = v0+(0.5*h*(-p["G"]/p["M"])*x0);

//        for (int i = 1; i<N; ++i){
//                x_lf[i] = x_lf[i-1]+(h*v_lf[i-1]);
//                v_lf[i] = v_lf[i-1]+(h*(-p["k"]/p["m"])*x_lf[i]);
//        }

	//making my data
	doc(vx_e, "myout_vx_e.dat");
	doc(x_e, "myout_x_e.dat");
	doc(vy_e, "myout_vy_e.dat");
	doc(y_e, "myout_y_e.dat");

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
