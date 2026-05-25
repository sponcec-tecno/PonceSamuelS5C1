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
	double ti = 0.0;
	double tf = 3.0;
	double x0 = 0.1;
	double v0 = 0.0;

	std::map<std::string, double> p;//the parameters/constants for modify the system
	p["k"] = 50;
	p["m"] = 0.2;

	double h = (tf-ti)/(N-1.0);//h

	//Euler
	//elements for euler
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
                v_lf[i] = v_lf[i-1]+(h*(-p["k"]/p["m"])*x_lf[i]);
        }

	//making my data
	doc(v_e, "v_e_spring.dat");
	doc(x_e, "x_e_spring.dat");
	doc(v_lf, "v_lf_spring.dat");
	doc(x_lf, "x_lf_spring.dat");


	//Solution for the system with cushioning
	//new parameter
	p["b"] = 0.08;

	//things for Euler
        std::array<double, N> xc_e;//saving the points for position
        std::array<double, N> vc_e;//saving the points for velocity

        //solving
        xc_e[0] = x0;
        vc_e[0] = v0;

        for (int i = 1; i<N; ++i){
                xc_e[i] = xc_e[i-1]+(h*vc_e[i-1]);
                vc_e[i] = vc_e[i-1]-(h*p["k"]*xc_e[i-1]/p["m"]+h*p["b"]*vc_e[i-1]);
        }

	//RK4
        //things for RK4
        std::array<double, N> xc_rk4;//saving the points for position
        std::array<double, N> vc_rk4;//saving the points for velocity
	double k1_x {};
        double k2_x {};
        double k3_x {};
        double k4_x {};
        double k1_v {};
        double k2_v {};
        double k3_v {};
        double k4_v {};

        //solving
        xc_rk4[0] = x0;
        vc_rk4[0] = v0;

	for (int i = 1; i<N; ++i){
		//k's
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
        doc(vc_e, "vc_e_spring.dat");
        doc(xc_e, "xc_e_spring.dat");
        doc(vc_rk4, "vc_rk4_spring.dat");
        doc(xc_rk4, "xc_rk4_spring.dat");


	//time
	std::array<double, N> t;
	for(int i = 0; i<N; ++i){
		t[i] = h*i;
	}
	//saving it
	doc(t, "t_spring.dat");

	return 0;
}



void doc(std::array<double, N> & data, std::string name){
    //Opening the file
    std::ofstream outfile;
    outfile.open(name);
    //Fill it with the array
    for (double n : data){
        outfile << n << "\n";
    }
    //I close it
    outfile.close();
}
