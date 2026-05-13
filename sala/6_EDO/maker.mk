#Ejercicio 1
#Genero los datos
.PHONY : data1
data1 : myout_euler_EDO.dat myout_rk4_EDO.dat
%_EDO.dat : PonceSamuel_S6CASA_EDO.cpp
	g++ $< -o a1.out
	./a1.out
#Hago las gráficas
.PHONY : plot1
plot1 : all_EDO.pdf euler_EDO.pdf rk4_EDO.pdf

%_EDO.pdf: PLOTS_PonceSamuel_S6CASA_EDO.py myout_euler_EDO.dat myout_rk4_EDO.dat
	python $<

#Ejercicio 2
#Genero los datos
.PHONY : data2
data2 : myout_S_SIR.dat myout_I_SIR.dat myout_R_SIR.dat
%_SIR.dat : PonceSamuel_S6CASA_EDO_SIR.cpp
	g++ $< -o a2.out
	./a2.out
#Hago las gráficas
.PHONY : plot2
plot2 : euler_SIR.pdf

%_SIR.pdf: PLOTS_PonceSamuel_S6CASA_EDO_SIR.py myout_S_SIR.dat myout_I_SIR.dat myout_R_SIR.dat
	python $<

#Si quieres limpiar los datos .dat y .pdf
.PHONY : clean
clean :
	rm -f *.dat
	rm -f *.pdf
	rm -f *.out
