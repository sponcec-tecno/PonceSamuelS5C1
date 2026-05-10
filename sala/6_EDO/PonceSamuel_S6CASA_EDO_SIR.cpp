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

double rk4(double h, double people, std::array<double,3> & s, map & p, funptr f, double y_0);
void doc(std::array<double, N> & data, std::string name);
std::array<double, 3> f(double people, std::array <double, 3> & s, map & p);

int main(){

	//initial conditions
	double ti = 0.0;
	double tf = 60.0;
	double S0 = 9100.0;
	double I0 = 900.0;
	double R0 = 0.0;
	double people = S0+I0+R0;

	map params;//the parameters/constants for modify the system
	params["B"] = 3.0;
	params["r"] = 1.0;


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
	std::array<double,3> state_rk = [S0, I0, R0];
        for (int i = 1; i<N; ++i){
		state_rk["S"] = S_rk4[i-1];
		state_rk["I"] = I_rk4[i-1];
		state_rk["R"] = R_rk4[i-1];
//		std::cout << state_rk["S"];
                S_rk4[i] = rk4(h, people, state_rk, params, f_S, S_rk4[i-1]);
                I_rk4[i] = rk4(h, people, state_rk, params, f_I, I_rk4[i-1]);
                R_rk4[i] = rk4(h, people, state_rk, params, f_R, R_rk4[i-1]);
        }


	//making my data
	doc(S_euler, "myout_Se_SIR.dat");
	doc(I_euler, "myout_Ie_SIR.dat");
	doc(R_euler, "myout_Re_SIR.dat");
        doc(S_rk4, "myout_Srk4_SIR.dat");
        doc(I_rk4, "myout_Irk4_SIR.dat");
        doc(R_rk4, "myout_Rrk4_SIR.dat");

	return 0;

std::array<double, 3> f(double people, std::array<double, 3> & s, map & p) {

	double dS = (-p["B"]*s["S"]*s["I"])/people;
	double dI = ((p["B"]*s["S"]*s["I"])/people)-(p["r"]*s["I"]);
	double dR = p["r"]*s["I"];
}

double rk4(double h, double people, std::array<double, 3> & s, map & p, funptr f, double y_0){

	std::array<double, 4> k {};
	k[0] = h*f(people, s, p);
	k2 = h*f(people, s, p);
	s["S"] = S+(k2/2.0);
	s["I"] = I+(k2/2.0);
	s["R"] = R+(k2/2.0);
	k3 = h*f(people, s, p);
        s["S"] = S+k3;
        s["I"] = I+k3;
	s["R"] = R+k3;
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
