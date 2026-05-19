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
void rk4(double h, int n, std::array<double, N> & sol, double y_0);
void doc(std::array<double, N> & data, std::string name);

int main(){
	//initial conditions
	double y_0 = 1.0;//First step
	double ti = 0.0;//First time
	double N_float = static_cast<double>(N);

	//elements for euler
	double h = (tf-ti)/(N_float-1.0);//h for euler
	std::array<double, N> sol_e;//where I'll save all the points for the solution

	//calling euler
	euler(h, N, sol_e, y_0);

	//elements for rk4(Runge-Kutta 4)
	std::array<double, N> sol_rk4;

	//calling rk4
	rk4(h, N, sol_rk4, y_0);


	//making my data
	doc(sol_e, "myout_euler_EDO.dat");
	doc(sol_rk4, "myout_rk4_EDO.dat");

	//now, for two values of h
	//N=100
	const int n1 = 100.0;
	double n1_float = static_cast<double>(n1);
	double h1 = (tf-ti)/(n1_float-1.0);//h for euler
        std::array<double, n1> sol_eh1;//where I'll save all the points for the solution

        //solving with euler
        sol_eh1[0] = y_0;
        for (int i = 1; i<n1; ++i){
                sol_eh1[i] = sol_eh1[i-1]+(h1*f(sol_eh1[i-1]));
        }

        //elements for rk4(Runge-Kutta 4)
	std::array<double, n1> sol_rk4h1;

        //solving with rk4
	sol_rk4h1[0] = y_0;
        double k1 = 0.0;
        double k2 = 0.0;
        double k3 = 0.0;
        double k4 = 0.0;
        double aux = 0.0;

        for (int i = 1; i<n1; ++i){
                k1 = h1*f(sol_rk4h1[i-1]);
                k2 = h1*f(sol_rk4h1[i-1]+(k1/2.0));
                k3 = h1*f(sol_rk4h1[i-1]+(k2/2.0));
                k4 = h1*f(sol_rk4h1[i-1]+k3);
                aux = k1 + 2.0*k2 +2.0*k3 + k4;
                sol_rk4h1[i] = sol_rk4h1[i-1]+((1.0/6.0)*aux);
        }
        //making my data
	// Abro el archivo en modo escritura
	std::ofstream outfile1;
	outfile1.open("myout_eulerh1_EDO.dat");
	for (double n : sol_eh1){
		outfile1 << n << "\n";
	}
	//Cierro el archivo
	outfile1.close();

	// Abro el archivo en modo escritura
        std::ofstream outfile2;
        outfile2.open("myout_rk4h1_EDO.dat");
        for (double n : sol_rk4h1){
                outfile2 << n << "\n";
        }
        //Cierro el archivo
        outfile2.close();

	//N=10000
        const int n2 = 10000.0;
        double n2_float = static_cast<double>(n2);
        double h2 = (tf-ti)/(n2_float-1.0);//h for euler
        std::array<double, n2> sol_eh2;//where I'll save all the points for the solution
	//solving with euler
        sol_eh2[0] = y_0;
        for (int i = 1; i<n2; ++i){
                sol_eh2[i] = sol_eh2[i-1]+(h2*f(sol_eh2[i-1]));
        }

        //elements for rk4(Runge-Kutta 4)
        std::array<double, n2> sol_rk4h2;

        //solving with rk4
        sol_rk4h2[0] = y_0;
        k1 = 0.0;
        k2 = 0.0;
        k3 = 0.0;
        k4 = 0.0;
        aux = 0.0;

        for (int i = 1; i<n2; ++i){
                k1 = h2*f(sol_rk4h2[i-1]);
                k2 = h2*f(sol_rk4h2[i-1]+(k1/2.0));
                k3 = h2*f(sol_rk4h2[i-1]+(k2/2.0));
                k4 = h2*f(sol_rk4h2[i-1]+k3);
                aux = k1 + 2.0*k2 +2.0*k3 + k4;
                sol_rk4h2[i] = sol_rk4h2[i-1]+((1.0/6.0)*aux);
        }
        //making my data
	//making my data
        // Abro el archivo en modo escritura
        std::ofstream outfile3;
        outfile3.open("myout_eulerh2_EDO.dat");
        for (double n : sol_eh2){
                outfile3 << n << "\n";
        }
        //Cierro el archivo
        outfile3.close();

        // Abro el archivo en modo escritura
        std::ofstream outfile4;
        outfile4.open("myout_rk4h2_EDO.dat");
        for (double n : sol_rk4h2){
                outfile4 << n << "\n";
        }
        //Cierro el archivo
        outfile4.close();

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

void rk4(double h, int n, std::array<double, N> & sol, double y_0){
	sol[0] = y_0;
	double k1 = 0.0;
	double k2 = 0.0;
	double k3 = 0.0;
	double k4 = 0.0;
	double aux = 0.0;

        for (int i = 1; i<n; ++i){
		k1 = h*f(sol[i-1]);
		k2 = h*f(sol[i-1]+(k1/2.0));
		k3 = h*f(sol[i-1]+(k2/2.0));
		k4 = h*f(sol[i-1]+k3);
		aux = k1 + 2.0*k2 +2.0*k3 + k4;
		sol[i] = sol[i-1]+((1.0/6.0)*aux);
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
