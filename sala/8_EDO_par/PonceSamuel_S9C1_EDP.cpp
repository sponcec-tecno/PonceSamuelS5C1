#include <iostream>
#include <map>
#include <array>
#include <fstream>
#include <cmath>
#include <string>

const int N = 101;
void doc(std::array<double, N> & data, std::string name);

int main(){

	//forzado?
	bool f = 0;//si lo pones en 1, descomenta una de las frecuencias w

	//constantes
	std::map <std::string, double> p;
	p["c"] = 300.0;
	p["L"] = 2.0;//metros
//	p["w"] = 1413.7;//dos nodos
//	p["w"] = 1885.0;//tres nodos
//	p["w"] = 2356.2;//cuatro nodos
//	p["w"] = 2827.4;//cinco nodos
	p["A"] = 0.1;

	//condiciones iniciales
	double v0 = 0.0;
	double tf = 0.1;
	double ti = 0.0;

	//condiciones de frontera
	double xi = 0.0;
	double xf = 0.0;

	//array de xp
	std::array<double, N> xp;
	double h = p["L"]/(N-1.0);//para calcular los x

	if (f){//forzado
		for(int i = 0; i<N; ++i){
			xp[i] = 0.0;
		}
	}else{//no forzado
		xp[0] = xi;
		xp[N-1] = xf;

		for (int i = 1; i<(N-1)/2; ++i){//de pa'rriba
			xp[i] = 0.1*i*h;
		}
		xp[(N-1)/2] = 0.1;
		for (int i = ((N-1)/2)+1; i<N-1; ++i){//de pa'bajo
        	        xp[i] = (-0.1*i*h)+0.2;
	        }
	}


	//construyo el dt
	double dt = 0.5*h/p["c"];

	//array de xpr
	std::array<double, N> xpr;
	xpr[0] = xi;
	double r = p["c"]*p["c"]*dt*dt/(h*h);
	if (f){//forzado
		xpr[N-1] = p["A"]*std::sin(p["w"]*dt);
	}else{//no-forzado
		xpr[N-1] = xf;
	}

	for (int i = 1; i < N-1; ++i){
		xpr[i] = xp[i]+(0.5*r*(xp[i+1]-2.0*xp[i]+xp[i-1]));
	}


	//soluciono
	std::array<double, N> xfu;
	xfu[0] = xi;

	if (f){//forzado
                xfu[N-1] = p["A"]*std::sin(p["w"]*dt*2.0);
        }else{//no-forzado
		xfu[N-1] = xf;
        }

	int t = 1;
	int c = 1;

	//estado inicial
	doc(xp, "t0.dat");

	for (double i = dt; i <= (tf-ti) ;i += dt){
		for (int j = 1; j < N-1; ++j){//soluciono para el tiempo futuro
			xfu[j] = 2.0*xpr[j]-xp[j]+(r*(xpr[j+1]-2.0*xpr[j]+xpr[j-1]));
		}

		if(f){//para que se actualice el borde forzado
                        xfu[N-1] = p["A"]*std::sin(p["w"]*(i+2.0*dt));
                }

		for (int k = 0; k<N; ++k){//actualizo el tiempo
			xp[k] = xpr[k];
			xpr[k] = xfu[k];
		}

		if (t%432 == 0){//envío al doc cada  pasos
			std::string name = "t" + std::to_string(c) + ".dat";
			doc(xpr, name);
			++c;
		}

		if(f){//para que se actualice el borde forzado
			xfu[N-1] = p["A"]*std::sin(p["w"]*(i+2.0*dt));
		}

		++t;
	}

	//los puntos horizontales
	std::array<double, N> xh;
	for (int i = 0; i < N; ++i){
		xh[i] = i*h;
	}

	doc(xh, "xh.dat");

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
