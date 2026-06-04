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
	p["v"] = 0.0001;
	p["L"] = 1.0;//longitud de la placa en m

	//condiciones iniciales
	double tf = 2500.0;
	double ti = 0.0;
	double T0C = 50.0;//para casi toda la placa
	double T0c = 100.0;//para el cuadrado
	std::array<double, N*N> Tpr;

	//condiciones de frontera
	double Tf = 50.0;

	//llamo función para mantener la frontera fija
	fix(Tpr, Tf);
//	doc(Tpr, "Tf.dat");

	//lleno xpr con las condiciones iniciales
	for (int j=1; j<N-1; ++j){//Primero lleno todo con T0
		for (int i=0; i<N-1; ++i){
			Tpr[N*j+i] = T0C;
		}
	}

	//luego pongo el cuadrado
	int l = 20;//longitud del cuadrado pequeño en cm
	int up = (N/2)-(l/2);
        int down = (N/2)+(l/2);
	int cx = 20;//distancia del cuadrado al lado izquierdo

	for (int j=up; j<down; ++j){
		for (int i=cx; i<l+cx; ++i){
			Tpr[N*j+i] = T0c;
		}
	}

//	doc(Tpr, "Tf.dat");

	//construyo el dt
	double dx = 0.01;
	double dy = 0.01;
//	double lim = 0.5*dx*dx/p["v"];//el límite del dt (siguiendo la misma ecuación de la ppt)
	double lim = 0.25*(dx*dx+dy*dy)/p["v"];
	double dt = lim*0.5;

	//soluciono
	std::array<double, N*N> Tfu;
	fix(Tfu, Tf);

	int t = 1;
	int c = 1;
	double x = p["v"]*dt/(dx*dx);
	double y = p["v"]*dt/(dy*dy);

//	std::cout << dt;

	//estado inicial
	doc(Tpr, "T0.dat");

	for (double i = dt; i <= (tf-ti) ; i += dt){
		for (int k = 1; k < N-1; ++k){//soluciono para el tiempo futuro
			for (int j = 1; j < N-1; ++j){
				Tfu[k*N+j] = Tpr[k*N+j]+x*(Tpr[k*N+j+1]-2*Tpr[k*N+j]+Tpr[k*N+j-1])+
							y*(Tpr[(k+1)*N+j]-2*Tpr[k*N+j]+Tpr[(k-1)*N+j]);
			}
		}

//		if(f){//para que se actualice el borde forzado
//                      xfu[N-1] = p["A"]*std::sin(p["w"]*(i+2.0*dt));
//              }

		for (int k = 0; k < N; ++k){//actualizo el tiempo
			for (int j = 0; j < N; ++j){//soluciono para el tiempo futuro
				Tpr[k*N+j] = Tfu[k*N+j];
			}
		}

		if ((t == 4*100) || (t == 4*1000)){//envío al doc cuando sean 100s/1000s
			std::string name = "T" + std::to_string(c) + ".dat";
			doc(Tpr, name);
			++c;
		}

//		if(f){//para que se actualice el borde forzado
//			xfu[N-1] = p["A"]*std::sin(p["w"]*(i+2.0*dt));
//		}

		++t;
	}

	doc(Tpr, "T"+ std::to_string(c) +".dat");

	//los puntos horizontales
//	std::array<double, N> xh;
//	for (int i = 0; i < N; ++i){
//		xh[i] = i*h;
//	}

//	doc(xh, "xh.dat");

	return 0;
}

void doc(std::array<double, N*N> & data, std::string name){
    //Opening the file
    std::ofstream outfile;
    outfile.open(name);
    //Fill it with the array
    for (int j=0; j<N; ++j){//Primero lleno todo con T0
                for (int i=0; i<N-1; ++i){
                        outfile << data[N*j+i] << "\t";
                }
	outfile << "\n";
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
