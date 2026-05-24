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

const int N = 1000;

void doc(std::array<double, N> & data, std::string name);

int main(){


	//initial conditions
	std::map<std::string, double> p;//the parameters/constants for modify the system
        p["k"] = 50;
        p["m"] = 0.2;
        p["b"] = 0.08;

	double ti = 0.0;
	double tf = 3.0;
	double x0 = 0.1;
	double v0 = 0.0;

	double N_double = static_cast<double>(N);
	double h = (tf-ti)/(N_double-1.0);//h for

	//things for Euler
        std::array<double, N> xc_e;//saving the points for position
        std::array<double, N> vc_e;//saving the points for velocity
	//time
	std::array<double, N> t;
	t[0] = ti;
	//solving
	xc_e[0] = x0;
	vc_e[0] = v0;

	for (int i = 1; i<N; ++i){
		xc_e[i] = xc_e[i-1]+(h*vc_e[i-1]);
		vc_e[i] = vc_e[i-1]-(h*p["k"]*xc_e[i-1]/p["m"]+h*p["b"]*vc_e[i-1]);
		t[i] = h*i;
        }

	//RK4
	//things for RK4
	std::array<double, N> xc_rk4;//saving the points for position
        std::array<double, N> vc_rk4;//saving the points for velocity

	//solving
	xc_rk4[0] = x0;
	vc_rk4[0] = v0;
	double k1_x {};
	double k2_x {};
	double k3_x {};
	double k4_x {};
	double k1_v {};
        double k2_v {};
        double k3_v {};
        double k4_v {};

	for (int i = 1; i<N; ++i){
		k1_x = h*vc_rk4[i-1];
		k1_v = h*(-(p["k"]*xc_rk4[i-1]/p["m"]+p["b"]*vc_rk4[i-1]));
		k2_x = h*(vc_rk4[i-1]+k1_v/2.0);
		k2_v = h*(-(p["k"]*(xc_rk4[i-1]+k1_x/2.0)/p["m"]+p["b"]*(vc_rk4[i-1]+k1_v/2.0)));
		k3_x = h*(vc_rk4[i-1]+k2_v/2.0);
		k3_v = h*(-(p["k"]*(xc_rk4[i-1]+k2_x/2.0)/p["m"]+p["b"]*(vc_rk4[i-1]+k2_v/2.0)));
		k4_x = h*(vc_rk4[i-1]+k3_v);
		k4_v = h*(-(p["k"]*(xc_rk4[i-1]+k3_x)/p["m"]+p["b"]*(vc_rk4[i-1]+k3_v)));
		//position
		xc_rk4[i] = xc_rk4[i-1]+(k1_x+2*k2_x+2*k3_x+k4_x)/6.0;
		//velocity
		vc_rk4[i] = vc_rk4[i-1]+(k1_v+2*k2_v+2*k3_v+k4_v)/6.0;
	}

	//data
	doc(vc_e, "myout_vc_e.dat");
        doc(xc_e, "myout_xc_e.dat");
	doc(vc_rk4, "myout_vc_rk4.dat");
        doc(xc_rk4, "myout_xc_rk4.dat");
	doc(t, "tc.dat");

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
