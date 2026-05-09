#include <array>
#include <fstream>
#include <iostream>
#include <math.h>
#include <functional>
#include <string>
#include <map>

const int N = 200;

double f(double people, double I, double S, std::string fun, std::map<std::string, double> & p);
void rk4(double h, int n, std::array<double, N> & sol, double y_0);
void doc(std::array<double, N> & data, std::string name);

int main(){


	//initial conditions
	double ti = 0.0;
	double tf = 60.0;
	double S0 = 9100.0;
	double I0 = 900.0;
	double R0 = 0.0;
	double people = S0+I0+R0;

	std::map<std::string, double> params;//the parameters/constants for modify the system
	params["B"] = 3.0;
	params["r"] = 1.0;


	//elements for euler
	double N_double = static_cast<double>(N);
	double h = (tf-ti)/(N_double-1.0);//h for euler
	std::array<double, N> sol_S;//saving the points for Susceptible
	std::array<double, N> sol_I;//saving the points for Infected
	std::array<double, N> sol_R;//saving the point for Recovered


	//solving the system with euler
	sol_S[0] = S0;
	sol_I[0] = I0;
	sol_R[0] = R0;
	std::cout << sol_S[0] << "\t" << h << "\n";

        for (int i = 1; i<N; ++i){
		sol_S[i] = sol_S[i-1]+(h*f(people, sol_I[i-1], sol_S[i-1], "S", params));
		sol_I[i] = sol_I[i-1]+(h*f(people, sol_I[i-1], sol_S[i-1], "I", params));
		sol_R[i] = sol_R[i-1]+(h*f(people, sol_I[i-1], sol_S[i-1], "R", params));
	}

	//elements for rk4(Runge-Kutta 4)
//	std::array<double, N> sol_rk4;

	//calling rk4
//	rk4(h, N, sol_rk4, y_0);
	std::cout << sol_S[100] << "\n";

	//making my data
	doc(sol_S, "myout_S.dat");
	doc(sol_I, "myout_I.dat");
	doc(sol_R, "myout_R.dat");

	return 0;
}

double f(double people, double I, double S, std::string fun, std::map<std::string, double> & p){

	double x{};
	if(fun=="S"){
		x = (-p["B"]*S*I)/people;
	}
	else if(fun=="I"){
		x = ((p["B"]*S*I)/people)-(p["r"]*I);
	}
	else if(fun=="R"){
		x = p["r"]*I;
	}

	return x;
}

void rk4(double h, int n, std::array<double, N> & sol, double y_0){
	sol[0] = y_0;
	double k1 = 0.0;
	double k2 = 0.0;
	double k3 = 0.0;
	double k4 = 0.0;
	double aux = 0.0;

        for (int i = 1; i<n; ++i){
//		k1 = h*f(sol[i-1]);
//		k2 = h*f(sol[i-1]+(k1/2.0));
//		k3 = h*f(sol[i-1]+(k2/2.0));
//		k4 = h*f(sol[i-1]+k3);
//		aux = k1 + 2.0*k2 +2.0*k3 + k4;
//		sol[i] = sol[i-1]+((1.0/6.0)*aux);
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
