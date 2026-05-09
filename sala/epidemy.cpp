#include <array>
#include <fstream>
#include <iostream>
#include <math.h>
#include <functional>
#include <string>
#include <map>

const int N = 200;

double f(double x);
void euler(double h, int n, std::array<double, N> & sol, double y_0);
void rk4(double h, int n, std::array<double, N> & sol, double y_0);
void doc(std::array<double, N> & data, std::string name);

int main(){


	//initial conditions
	double ti = 0.0;
	double tf = 60.0;
	double S0 = 9100.0;
	double I0 = 900.0;
	double R0 = 0.0;

	std::map<std::string, double> params;//the constants for modify the system
	params["B"] = -3.0;
	params["r"] = -1.0;


	//elements for euler
	double N_float = static_cast<double>(N);
	double h = (tf-ti)/(N_float-1);//h for euler
	std::array<double, N> sol_S;//saving the points for Susceptible
	std::array<double, N> sol_I;//saving the points for Infected
	std::array<double, N> sol_R;//saving the points for Recovered

	//solving the system with euler

	//elements for rk4(Runge-Kutta 4)
//	std::array<double, N> sol_rk4;

	//calling rk4
//	rk4(h, N, sol_rk4, y_0);


	//making my data
//	doc(sol_e, "myout_euler.dat");
//	doc(sol_rk4, "myout_rk4.dat");

	return 0;
}

double f(double x){
	return -x;
}

void euler(double h, int n, std::array<double, N> & sol, double y_0){
	sol[0] = y_0;
	for (int i = 1; i<n; ++i){
		sol[i] = sol[i-1]+(h*f(sol[i-1]));
	}
}

void rk4(double h, int n, std::array<double, N> & sol, double y_0){
	sol[0] = y_0;
	double k1 = 0.0;
	double k2 = 0.0;
	double k3 = 0.0;
	double k4 = 0.0;
	double aux = 0.0;

        for (int i = 1; i<n; ++i){
		k1 = h*f(sol[i-1]);
		k2 = h*f(sol[i-1]+(k1/2.0));
		k3 = h*f(sol[i-1]+(k2/2.0));
		k4 = h*f(sol[i-1]+k3);
		aux = k1 + 2.0*k2 +2.0*k3 + k4;
		sol[i] = sol[i-1]+((1.0/6.0)*aux);
        }
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
