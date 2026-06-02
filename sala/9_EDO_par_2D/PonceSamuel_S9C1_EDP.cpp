#include <iostream>
#include <map>
#include <array>
#include <fstream>
#include <cmath>
#include <string>

const int N = 100;
void doc(std::array<double, N*N> & data, std::string name);
void fix(std::array<double, N*N> & s, double f);

int main(){

	//forzado?
//	bool f = 0;//si lo pones en 1, descomenta una de las frecuencias w

	//constantes
	std::map <std::string, double> p;
	p["v"] = 300.0;
	p["L"] = 1.0;//longitud de la placa en cm

	//condiciones iniciales
	double tf = 0.0;
	double ti = 2500.0;
	double T0 = 50.0;
	std::array<double, N*N> Tpr;

	//condiciones de frontera
	double Tf = 50.0;

	//llamo función para mantener la frontera fija
	fix(Tpr, Tf);
//	doc(Tpr, "Tf.dat");

	//lleno xpr con las condiciones iniciales
	int l = 20;//longitud del cuadrado pequeño
	for (int j=1; j<N-1; ++j){
		for (int i=0; i<N-1; ++i){
			Tpr[N*j+i] = T0;
//			if(j==((N/2)-(20)))
		}
	}

//	doc(Tpr, "T0.dat");

	//construyo el dt
	double dx = 0.01;
	double dy = 0.01;
	double lim = 0.5*dx*dx/p["v"];//el límite del dt
	double dt = lim*0.5;

	//soluciono
	std::array<double, N*N> Tfu;
	fix(Tfu, Tf);

	int t = 1;
	int c = 1;

	//estado inicial
//	doc(xp, "t0.dat");

//	for (double i = dt; i <= (tf-ti) ;i += dt){
//		for (int j = 1; j < N-1; ++j){//soluciono para el tiempo futuro
//			xfu[j] = 2.0*xpr[j]-xp[j]+(r*(xpr[j+1]-2.0*xpr[j]+xpr[j-1]));
//		}

//		if(f){//para que se actualice el borde forzado
//                      xfu[N-1] = p["A"]*std::sin(p["w"]*(i+2.0*dt));
//              }

//		for (int k = 0; k<N; ++k){//actualizo el tiempo
//			xp[k] = xpr[k];
//			xpr[k] = xfu[k];
//		}

//		if (t%432 == 0){//envío al doc cada  pasos
//			std::string name = "t" + std::to_string(c) + ".dat";
//			doc(xpr, name);
//			++c;
//		}

//		if(f){//para que se actualice el borde forzado
//			xfu[N-1] = p["A"]*std::sin(p["w"]*(i+2.0*dt));
//		}

//		++t;
//	}

	//los puntos horizontales
//	std::array<double, N> xh;
//	for (int i = 0; i < N; ++i){
//		xh[i] = i*h;
//	}

//	doc(xh, "xh.dat");

	return 0;
}

void doc(std::array<double, N*N> & data, std::string name){
    //Opening the fil
    std::ofstream outfile;
    outfile.open(name);
    //Fill it with the array
    for (double n : data){
        outfile << n << "\n";
    }
    //I close it
    outfile.close();
}

void fix(std::array<double, N*N> & s, double f){

	for (int i=0; i<N; ++i){//arriba de la placa
                s[i] = f;
	}

	for (int j=0; j<N; ++j){
                        s[N*j] = f;
			s[N*(j+1)-1] = f;
        }

	for (int i=N*(N-1); i <N*N; ++i){//abajo de la placa
		s[i] = f;
	}
}
