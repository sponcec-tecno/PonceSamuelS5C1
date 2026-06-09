#include <iostream>
#include <map>
#include <array>
#include <fstream>
#include <cmath>
#include <string>



const int N = 100;//Es decir que los arrays serán de 100*100, así cada dato representa un cuadrado de un centímetro
void doc(std::array<double, N*N> & data, std::string name);
void fix(std::array<double, N*N> & s, double f, bool op, bool per);



int main(){


	//-condiciones de frontera/si ambos están en 0 serán fijas
	bool open = 0;//si lo pones en 1, quieres condiciones abiertas
	bool periodic = 1;//si lo pones en 1, asegúrate de poner en 0 open
	double Tf = 50.0;//para frontera fija


	//-constantes
	std::map <std::string, double> p;
	p["v"] = 0.0001;//m^2/s
	p["L"] = 1.0;//longitud de la placa en m


	//-condiciones iniciales
	//tiempo
	double tf = 2500.0;
	double ti = 0.0;
	//Temperatura
	double T0C = 50.0;//para casi toda la placa
	double T0c = 100.0;//para el cuadrado

	//lleno Tpresente con las condiciones iniciales
	std::array<double, N*N> Tpr;
	for (int j=1; j<N-1; ++j){//Primero lleno todo con T0
		for (int i=0; i<N-1; ++i){
			Tpr[N*j+i] = T0C;
		}
	}
	//luego pongo el cuadrado
	int l = 20;//longitud del cuadrado pequeño en cm, para manejarlo en los índices
	int up = (N/2)-(l/2);//Borde de arriba
        int down = (N/2)+(l/2);//Borde de abajo
	int cx = 20;//distancia del cuadrado al lado izquierdo(cm)

	for (int j=up; j<down; ++j){
		for (int i=cx; i<l+cx; ++i){
			Tpr[N*j+i] = T0c;
		}
	}


	//-condiciones de frontera iniciales
	fix(Tpr, Tf, open, periodic);//Mi función recibe el array, y la variable respectiva de cada condición de frontera


	//-construcción del dt
	double dx = 0.01;
	double dy = 0.01;
	double h {};

	if (dx < dy){//evalúo cuál de los dos es menor para escogerlo y tener una buena resolución :)
		h = dx;
	} else{
		h = dy;
	}

	double lim = 0.5*(h*h)/p["v"];//el valor límite que rige a dt
	double dt = lim*0.5;//dt tiene que ser menor que el límite lim/2 < lim


	//-soluciono
	std::array<double, N*N> Tfu;//Array de la temperatura futura
	fix(Tfu, Tf, open, periodic);//lleno la frontera

	//parte de la solución (constante) para no calcularla dentro del for cada vez que repite
	double x = p["v"]*dt/(dx*dx);
	double y = p["v"]*dt/(dy*dy);

	//guardo estado inicial
	doc(Tpr, "T0.dat");
	int c = 1;//empiezo a contar los archivos a imprimir
	int t = 1;//contador de los pasos en el tiempo para los documentos

	for (double i = dt; i <= (tf-ti) ; i += dt){//voy en pasos de tiempo de longitud dt hasta llegar al tiempo final
		for (int k = 1; k < N-1; ++k){//soluciono para el tiempo futuro
			for (int j = 1; j < N-1; ++j){
				Tfu[k*N+j] = Tpr[k*N+j]+x*(Tpr[k*N+j+1]-2*Tpr[k*N+j]+Tpr[k*N+j-1])+
							y*(Tpr[(k+1)*N+j]-2*Tpr[k*N+j]+Tpr[(k-1)*N+j]);//x corresponde a columnas, y a filas
			}
		}

		if(open || periodic){//para que se actualice la frontera (sólo si no es fija, si lo es note que nunca modifica esos datos)
			fix(Tfu, Tf, open, periodic);
		}

		for (int k = 0; k < N; ++k){//actualizo el tiempo
			for (int j = 0; j < N; ++j){
				Tpr[k*N+j] = Tfu[k*N+j];
			}
		}

		if ((t == (100/dt)) || (t == (1000/dt))){//envío al doc cuando sean 100s/1000s
			std::string name = "T" + std::to_string(c) + ".dat";
			doc(Tpr, name);
			++c;
		}

		++t;
	}

	//guardo el estado final
	doc(Tpr, "T"+ std::to_string(c) +".dat");


	return 0;
}



void doc(std::array<double, N*N> & data, std::string name){//recibe el array y su nombre


    //Abro el archivo "name"
    std::ofstream outfile;
    outfile.open(name);
    //Lo lleno con el contenido del array
    for (int j=0; j<N; ++j){
                for (int i=0; i<N-1; ++i){
                        outfile << data[N*j+i] << "\t";//separados por tab
                }
	outfile << "\n";//cuando salgo de una fila hago un salto de línea
        }
    //Lo cierro
    outfile.close();


}



void fix(std::array<double, N*N> & s, double f, bool op, bool per){//recibe array, el valor de la frontera fija, si es abierta y si es periódica


	if(op){//frontera abierta
		for (int i=0; i<N; ++i){//arriba de la placa
                        s[i] = s[N+i];
                }

                for (int j=0; j<N; ++j){//bordes
                                s[N*j] = s[N*j+1];//izquierdos
                                s[N*(j+1)-1] = s[N*(j+1)-2];//derechos
                }

                for (int i=N*(N-1); i <N*N; ++i){//abajo de la placa
                        s[i] = s[i-N];
                }
	}else if(per){//frontera periódica
		for (int i=0; i<N; ++i){//arriba de la placa
			s[i] = s[(N*(N-2))+i];
		}

		for (int j=0; j<N; ++j){//bordes
				s[N*j] = s[N*(j+1)-2];//izquierdos
				s[N*(j+1)-1] = s[N*j+1];//derechos
		}

		for (int i=N*(N-1); i <N*N; ++i){//abajo de la placa
			s[i] = s[i+N*(2-N)];
		}
	}
	else{//frontera fija
		for (int i=0; i<N; ++i){//arriba de la placa
        	        s[i] = f;
		}

		for (int j=0; j<N; ++j){//bordes
                	        s[N*j] = f;//izquierdos
				s[N*(j+1)-1] = f;//derechos
        	}

		for (int i=N*(N-1); i <N*N; ++i){//abajo de la placa
			s[i] = f;
		}
	}
}
