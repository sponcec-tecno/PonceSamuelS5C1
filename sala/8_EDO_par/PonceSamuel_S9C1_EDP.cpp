//En el tiempo total debo sacar seis soluciones "arrays"

#include <iostream>
#include <map>
#include <array>
#include <fstream>
#include <cmath>

const int N = 101;
void doc(std::array<double, N> & data, std::string name);

int main(){

	//constantes
	std::map <std::string, double> p;
	p["c"] = 300.0;
	p["L"] = 2.0;//metros

	//condiciones iniciales
	double v0 = 0.0;
	double tf = 0.1;
	double ti = 0.0;

	//condiciones de frontera
	double xi = 0.0;
	double xf = 0.0;

	//array de x0
	std::array<double, N> xp;
	xp[0] = xi;
	xp[N-1] = xf;
	double h = p["L"]/(N-1);//para calcular los x
	for (int i = 1; i<(N-1)/2; ++i){//de pa'rriba
		xp[i] = 0.1*i*h;
	}
	xp[(N-1)/2] = 0.1;
	for (int i = ((N-1)/2)+1; i<N-1; ++i){//de pa'bajo
                xp[i] = (-0.1*i*h)+0.2;
        }

	//doc(x0, "x.dat");

	double dx = xp[1]-xp[0];
	double dt = 0.5*dx/p["c"];

	//array de x1
	std::array<double, N> xpr;
	xpr[0] = xi;
	xpr[N-1] = xf;
	for (int i = 1; i < N-1; ++i){
		xpr[i] = xp[i]+0.5*std::pow(p["c"]*dt/dx,2)*(xp[i+1]-2*xp[i]+xp[i-1]);
	}

	//doc(x1, "x.dat");

	//soluciono
	std::array<double, N> xfu;
	xfu[0] = xi;
	xfu[N-1] = xf;
	double n = (tf-ti)/dt;
	for (double i = dt; i <= (tf-ti) ;i += dt){
		for (int j = 1; j < N-1; ++j){
			xfu[j] = 2*xpr[j]-xp[j]+std::pow(p["c"]*dt/dx,2)*(xpr[j+1]-2*xpr[j]+xpr[j-1]);
		}
	}

	

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
