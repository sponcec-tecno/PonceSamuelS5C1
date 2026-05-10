#include <array>
#include <fstream>
#include <iostream>
#include <math.h>
#include <functional>
#include <string>
#include <map>

using funptr = std::function<double(double)>;

const int N = 200;

double f_S(double people, std::map<std::string, double> & s, std::map<std::string, double> & p);
double f_I(double people, std::map<std::string, double> & s, std::map<std::string, double> & p);
double f_R(double people, std::map<std::string, double> & s, std::map<std::string, double> & p);
double rk4(double h, double people, std::map<std::string, double> & p, std::map<std::string, double>  s, funptr f);
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
	std::array<double, N> sol_S_euler;//saving the points for Susceptible
	std::array<double, N> sol_I_euler;//saving the points for Infected
	std::array<double, N> sol_R_euler;//saving the point for Recovered

	//solving the system with euler
	sol_S_euler[0] = S0;
	sol_I_euler[0] = I0;
	sol_R_euler[0] = R0;

        for (int i = 1; i<N; ++i){
		sol_S_euler[i] = sol_S_euler[i-1]+(h*f_S(people, sol_I_euler[i-1], sol_S_euler[i-1], params));
		sol_I_euler[i] = sol_I_euler[i-1]+(h*f_I(people, sol_I_euler[i-1], sol_S_euler[i-1], params));
		sol_R_euler[i] = sol_R_euler[i-1]+(h*f_R(people, sol_I_euler[i-1], params));
	}

	//elements for rk4(Runge-Kutta 4)
	std::array<double, N> S_rk4;//saving the points for Susceptible
        std::array<double, N> I_rk4;//saving the points for Infected
        std::array<double, N> R_rk4;//saving the point for Recovered

	//calling rk4
	std::map<std::string, double> state;
        for (int i = 1; i<N; ++i){
		p["S"] = S[i-1];
		p["I"] = I[i-1];
		p["R"] = R[i-1];
                S_rk4[i] = rk4(h, people, S_rk4[i-1], I_rk4[i-1], params, state, f_S);
                I_rk4[i] = rk4(h, people, S_rk4[i-1], I_rk4[i-1], params, state, f_I);
                R_rk4[i] = rk4(h, people, S_rk4[i-1], I_rk4[i-1], params, state, f_R);
        }

	//making my data
	doc(sol_S_euler, "myout_S_SIR.dat");
	doc(sol_I_euler, "myout_I_SIR.dat");
	doc(sol_R_euler, "myout_R_SIR.dat");

	return 0;
}

double f_S(double people, std::map<std::string, double> & s, std::map<std::string, double> & p){
	return (-p["B"]*S*I)/people;
}

double f_I(double people, std::map<std::string, double> & s, std::map<std::string, double> & p){
       return ((p["B"]*S*I)/people)-(p["r"]*I);
}

double f_R(double people, std::map<std::string, double> & s, std::map<std::string, double> & p){
	return p["r"]*I;
}

double rk4(double h, double people, std::map<std::string, double> & p, std::map<std::string, double> s, funptr f){

	double k1 {};
	double k2 {};
	double k3 {};
	double k4 {};
	double aux {};

	k1 = h*f(people, s, p);
	s[""]
	k2 = h*f(people, sol[i-1]+(k1/2.0));
	k3 = h*f(sol[i-1]+(k2/2.0));
	k4 = h*f(sol[i-1]+k3);
	aux = k1 + 2.0*k2 +2.0*k3 + k4;
	sol[i] = sol[i-1]+((1.0/6.0)*aux);
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
