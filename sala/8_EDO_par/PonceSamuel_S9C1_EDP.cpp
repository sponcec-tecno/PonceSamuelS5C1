//Construir el array de posición
//Construir condición inicial: llenar un arreglo de 100 puntos para x
//Construir el primer paso de tiempo u¹
//Construir las soluciones para amplitud
//En el tiempo total debo sacar seis soluciones "arrays"

#include <iostream>
#include <map>
#include <array>
#include <fstream>

const int N = 100;
void doc(std::array<double, N> & data, std::string name);

int main(){

	//constantes
	std::map <std::string, double> p;
	p["c"] = 300;
	p["L"] = 2;//metros

	//condiciones iniciales
	double v0 = 0.0;
	double tf = 0.1;
	double ti = 0.0;

	//condiciones de frontera
	double xi = 0.0;
	double xf = 0.0;

	//array de x0
	std::array<double, N> x0;
	x0[0] = xi;
	x0[N-1] = xf;
	double h = p["L"]/N;//para calcular los x
	for (int i = 1; i<=N/2; ++i){//de pa'rriba
		x0[i] = 0.1*i*h;
	}
	for (int i = (N/2)+1; i<N-1; ++i){//de pa'bajo
                x0[i] = (-0.1*i*h)+0.2;
        }
	//El x se ve raro al inicio, y se come un valor al final
	doc(x0, "x.dat");

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
