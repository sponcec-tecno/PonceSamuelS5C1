#include <array>
#include <fstream>
#include <iostream>
#include <cmath>
#include <functional>
#include <string>
#include <map>

const int N = 5500;
void doc(std::array<double, N> & data, std::string name);

int main(){


	//initial conditions

	std::map<std::string, double> p;//the parameters/constants for modify the system
        p["G"] = 39.41;//Constante en años, UA y MA.
        p["M"] = 1.0;//Masa del Sol/MA
        p["m"] = 0.000003;

	double ti = 0.0;
	double tf = 11.0;//Años
	double xT0 = 1.000003;//UA
	double vxT0 = 0.0;
	double yT0 = 0.0;
	double vyT0 = 6.28;//UA/año
	double xS0 = -0.01671;
	double vxS0 = 0.0;
	double yS0 = 0.0;
	double vyS0 = -p["m"]*vyT0;//Por conservación del momento
//	double vyS0 = -0.00002;//Esta la usé, pero el Sol era arrastrado hacia abajo
	double h = (tf-ti)/(N-1.0);//h for euler

	//Euler
	//elements for euler
	//Earth
	std::array<double, N> xT_e;//saving the points for xposition
	std::array<double, N> vxT_e;//saving the points for xvelocity
	std::array<double, N> yT_e;//saving the points for yposition
	std::array<double, N> vyT_e;//saving the points for yvelocity
	//Sun
	std::array<double, N> xS_e;//saving the points for xposition
        std::array<double, N> vxS_e;//saving the points for xvelocity
        std::array<double, N> yS_e;//saving the points for yposition
        std::array<double, N> vyS_e;//saving the points for yvelocity


	//solving the system with euler
	xT_e[0] = xT0;
	vxT_e[0] = vxT0;
	yT_e[0] = yT0;
	vyT_e[0] = vyT0;

	xS_e[0] = xS0;
        vxS_e[0] = vxS0;
        yS_e[0] = yS0;
        vyS_e[0] = vyS0;
	double r = 0.0;

	for (int i = 1; i<N; ++i){
		r = std::sqrt(std::pow(xT_e[i-1]-xS_e[i-1],2.0)+std::pow(yT_e[i-1]-yS_e[i-1],2.0));
		//Earth
		vxT_e[i] = vxT_e[i-1]+(h*-((xT_e[i-1]-xS_e[i-1])*p["G"]*p["M"]/(std::pow(r,3.0))));
		vyT_e[i] = vyT_e[i-1]+(h*-((yT_e[i-1]-yS_e[i-1])*p["G"]*p["M"]/(std::pow(r,3.0))));
		xT_e[i] = xT_e[i-1]+(h*vxT_e[i-1]);
		yT_e[i] = yT_e[i-1]+(h*vyT_e[i-1]);
		//Sun
		vxS_e[i] = vxS_e[i-1]+(h*((xT_e[i-1]-xS_e[i-1])*p["G"]*p["m"]/(std::pow(r,3.0))));
                vyS_e[i] = vyS_e[i-1]+(h*((yT_e[i-1]-yS_e[i-1])*p["G"]*p["m"]/(std::pow(r,3.0))));
                xS_e[i] = xS_e[i-1]+(h*vxS_e[i-1]);
                yS_e[i] = yS_e[i-1]+(h*vyS_e[i-1]);
	}


	//Leap-Frog
	//preparing things for Leap-Frog
        //Earth
        std::array<double, N> xT_lf;//saving the points for xposition
        std::array<double, N> vxT_lf;//saving the points for xvelocity
        std::array<double, N> yT_lf;//saving the points for yposition
        std::array<double, N> vyT_lf;//saving the points for yvelocity
        //Sun
        std::array<double, N> xS_lf;//saving the points for xposition
        std::array<double, N> vxS_lf;//saving the points for xvelocity
        std::array<double, N> yS_lf;//saving the points for yposition
        std::array<double, N> vyS_lf;//saving the points for yvelocity


	//solving with leap-frog
	xT_lf[0] = xT0;
	yT_lf[0] = yT0;
        xS_lf[0] = xS0;
        yS_lf[0] = yS0;
	r = std::sqrt(std::pow(xT_lf[0]-xS_lf[0],2.0)+std::pow(yT_lf[0]-yS_lf[0],2.0));
	vxT_lf[0] = vxT0+(0.5*h*-((xT_lf[0]-xS_lf[0])*p["G"]*p["M"]/(std::pow(r,3.0))));
	vyT_lf[0] = vyT0+(0.5*h*-((yT_lf[0]-yS_lf[0])*p["G"]*p["M"]/(std::pow(r,3.0))));
        vxS_lf[0] = vxS0+(0.5*h*((xT_lf[0]-xS_lf[0])*p["G"]*p["m"]/(std::pow(r,3.0))));
        vyS_lf[0] = vyS0+(0.5*h*((yT_lf[0]-yS_lf[0])*p["G"]*p["m"]/(std::pow(r,3.0))));


        for (int i = 1; i<N; ++i){
		//firt position for both
                xT_lf[i] = xT_lf[i-1]+(h*vxT_lf[i-1]);
		yT_lf[i] = yT_lf[i-1]+(h*vyT_lf[i-1]);
		xS_lf[i] = xS_lf[i-1]+(h*vxS_lf[i-1]);
                yS_lf[i] = yS_lf[i-1]+(h*vyS_lf[i-1]);
		r = std::sqrt(std::pow(xT_lf[i]-xS_lf[i],2.0)+std::pow(yT_lf[i]-yS_lf[i],2.0));
		//then velocity for both
		vxT_lf[i] = vxT_lf[i-1]+(h*-((xT_lf[i]-xS_lf[i])*p["G"]*p["M"]/(std::pow(r,3.0))));
		vyT_lf[i] = vyT_lf[i-1]+(h*-((yT_lf[i]-yS_lf[i])*p["G"]*p["M"]/(std::pow(r,3.0))));
		vxS_lf[i] = vxS_lf[i-1]+(h*((xT_lf[i]-xS_lf[i])*p["G"]*p["m"]/(std::pow(r,3.0))));
                vyS_lf[i] = vyS_lf[i-1]+(h*((yT_lf[i]-yS_lf[i])*p["G"]*p["m"]/(std::pow(r,3.0))));
	}

	//making my data
	//Euler
	//Earth
	doc(vxT_e, "vxT_e.dat");
	doc(xT_e, "xT_e.dat");
	doc(vyT_e, "vyT_e.dat");
	doc(yT_e, "yT_e.dat");
	//Sun
	doc(vxS_e, "vxS_e.dat");
	doc(xS_e, "xS_e.dat");
	doc(vyS_e, "vyS_e.dat");
	doc(yS_e, "yS_e.dat");

	//Leap-frog
	//Earth
        doc(vxT_lf, "vxT_lf.dat");
        doc(xT_lf, "xT_lf.dat");
        doc(vyT_lf, "vyT_lf.dat");
        doc(yT_lf, "yT_lf.dat");
        //Sun
        doc(vxS_lf, "vxS_lf.dat");
        doc(xS_lf, "xS_lf.dat");
        doc(vyS_lf, "vyS_lf.dat");
        doc(yS_lf, "yS_lf.dat");
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
