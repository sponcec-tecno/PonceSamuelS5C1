#include <array>
#include <fstream>
#include <iostream>
#include <math.h>
#include <functional>
#include <string>
#include <map>

using map = std::map<std::string, double>;
using funptr = std::function<double(double, map&, map&)>;

const int N = 200;

double f_S(double people, map & s, map & p);
double f_I(double people, map & s, map & p);
double f_R(double people, map & s, map & p);
double rk4(double h, double people, map s, map & p, funptr f, double y_0);
void doc(std::array<double, N> & data, std::string name);

int main(){

	//initial conditions
	double ti = 0.0;
	double tf = 60.0;
	double S0 = 9100.0;
	double I0 = 900.0;
	double R0 = 0.0;
	double people = 1.0;

	map params;//the parameters/constants for modify the system
	params["B"] = 0.001;
	params["r"] = 0.1;


	//elements for euler
	double N_double = static_cast<double>(N);
	double h = (tf-ti)/(N_double-1.0);//h for euler
	std::array<double, N> S_euler;//saving the points for Susceptible
	std::array<double, N> I_euler;//saving the points for Infected
	std::array<double, N> R_euler;//saving the point for Recovered

	//solving the system with euler
	S_euler[0] = S0;
	I_euler[0] = I0;
	R_euler[0] = R0;
	map state_e;

        for (int i = 1; i<N; ++i){
		state_e["S"] = S_euler[i-1];
                state_e["I"] = I_euler[i-1];
                state_e["R"] = R_euler[i-1];
		S_euler[i] = S_euler[i-1]+(h*f_S(people, state_e, params));
		I_euler[i] = I_euler[i-1]+(h*f_I(people, state_e, params));
		R_euler[i] = R_euler[i-1]+(h*f_R(people, state_e, params));
	}

	//elements for rk4(Runge-Kutta 4)
	std::array<double, N> S_rk4;//saving the points for Susceptible
        std::array<double, N> I_rk4;//saving the points for Infected
        std::array<double, N> R_rk4;//saving the point for Recovered
	S_rk4[0] = S0;
	I_rk4[0] = I0;
	R_rk4[0] = R0;

	//calling rk4
	map state_rk;
//        for (int i = 1; i<N; ++i){
//		state_rk["S"] = S_rk4[i-1];
//		state_rk["I"] = I_rk4[i-1];
//		state_rk["R"] = R_rk4[i-1];
//              S_rk4[i] = rk4(h, people, state_rk, params, f_S, S_rk4[i-1]);
//              I_rk4[i] = rk4(h, people, state_rk, params, f_I, I_rk4[i-1]);
//              R_rk4[i] = rk4(h, people, state_rk, params, f_R, R_rk4[i-1]);
//        }


	//making my data
	doc(S_euler, "myout_Se_SIR.dat");
	doc(I_euler, "myout_Ie_SIR.dat");
	doc(R_euler, "myout_Re_SIR.dat");
//      doc(S_rk4, "myout_Srk4_SIR.dat");
//      doc(I_rk4, "myout_Irk4_SIR.dat");
//      doc(R_rk4, "myout_Rrk4_SIR.dat");

	return 0;
}

double f_S(double people, map & s, map & p){
	std::cout << s["S"] << s["I"] << people << "\n";
	return (-p["B"]*s["S"]*s["I"])/people;
}

double f_I(double people, map & s, map & p){
       return ((p["B"]*s["S"]*s["I"])/people)-(p["r"]*s["I"]);
}

double f_R(double people, map & s, map & p){
	return p["r"]*s["I"]/people;
}

double rk4(double h, double people, map s, map & p, funptr f, double y_0){

	double k1 {};
	double k2 {};
	double k3 {};
	double k4 {};
	double aux {};
	double S = s["S"];
	double I = s["I"];

	k1 = h*f(people, s, p);
	s["S"] = S+(k1/2.0);
	s["I"] = I+(k1/2.0);
	k2 = h*f(people, s, p);
	s["S"] = S+(k2/2.0);
	s["I"] = I+(k2/2.0);
	k3 = h*f(people, s, p);
        s["S"] = S+k3;
        s["I"] = I+k3;
	k4 = h*f(people, s, p);
	aux = k1 + 2.0*k2 +2.0*k3 + k4;
	return y_0+((1.0/6.0)*aux);
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
