#include <array>
#include <fstream>
#include <iostream>
#include <math.h>
#include <functional>
#include <string>

//#include <stdio.h>

const int N = 200; //numero de puntos
double tf = 2.0; //tiempo final

double f(double x);
void euler(double h, int n, std::array<double, N> & sol, double y_0);
void doc(std::array<double, N> & data, std::string name);

int main(){
	//initial conditions
	double y_0 = 1.0;//First step
	double ti = 0.0;//First time

	//elements for euler
	double h = (tf-ti)/N;//h for euler
	std::array<double, N> sol;//where I'll save all the points for the solution

	//calling euler
	euler(h, N, sol, y_0);

	//making my data
	doc(sol, "myout.dat");
	return 0;
}

double f(double x){
	return -x;
}

void euler(double h, int n, std::array<double, N> & sol, double y_0){
	sol[0] = y_0;
	for (int i = 1; i<n; ++i){
		sol[i] = sol[i-1]+(h*f(sol[i-1]));
	}
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


//Crear un array que guarde los valores que la función va calculando
//Crear la ecuación que determina mi punto siguiente
//Llenar el array hasta que se cumpla cierto tiempo o número de pasos
