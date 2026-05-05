#include <array>
#include <fstream>
#include <iostream>
#include <math.h>
#include <functional>
#include <string>

//#include <stdio.h>

const int N = 200; //numero de puntos
double tf = 2.0; //tiempo final

double f(double x);
void euler(double h, int n, std::array<double, N> & sol, double y_0);
void rk4(double h, int n, std::array<double, N> & sol, double y_0);
void doc(std::array<double, N> & data, std::string name);

int main(){
	//initial conditions
	double y_0 = 1.0;//First step
	double ti = 0.0;//First time

	//elements for euler
	double h = (tf-ti)/N;//h for euler
	std::array<double, N> sol_e;//where I'll save all the points for the solution

	//calling euler
	euler(h, N, sol_e, y_0);

	//elements for rk4(Runge-Kutta 4)
	std::array<double, N> sol_rk4;

	//calling rk4
	rk4(h, N, sol_rk4, y_0);

	std::cout << sol_rk4[78] << "\n";

	//making my data
	doc(sol_e, "myout_e.dat");
	doc(sol_rk4, "myout_rk.dat");

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
		k1 = f(sol[i-1]);
		k2 = f(sol[i-1]+(k1/2));
		k3 = f(sol[i-1]+(k2/2));
		k4 = f(sol[i-1]+k3);
		aux = k1 + (2*(k2+k3)) + k4;
		sol[i] = sol[i-1]+(h*(1.0/6.0)*aux);
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
