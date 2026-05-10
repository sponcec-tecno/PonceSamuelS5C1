#Ejercicio 1
.PHONY : data1
data1 : myout_euler_EDO.dat myout_rk4_EDO.dat
%_EDO.dat : PonceSamuel_S6CASA_EDO.cpp
	g++ $< -o a1.out
	./a1.out

.PHONY : plot1
plot1 : all_EDO.pdf euler_EDO.pdf rk4_EDO.pdf

%_EDO.pdf: PLOTS_PonceSamuel_S6CASA_EDO.py myout_euler_EDO.dat myout_rk4_EDO.dat
	python $<

#Ejercicio SIR
.PHONY : data2_e
data2_e : myout_Se_SIR.dat myout_Ie_SIR.dat myout_Re_SIR.dat

.PHONY : data2_rk4
data2_rk4 : myout_Srk4_SIR.dat myout_Irk4_SIR.dat myout_Rrk4_SIR.dat

%_SIR.dat : PonceSamuel_S6CASA_EDO_SIR.cpp
	g++ $< -o a2.out
	./a2.out

.PHONY : plot2_e
plot2_e : e_SIR.pdf e_SIR.pdf

.PHONY : plot2_rk4
plot2_rk4 : rk4_SIR.pdf rk4_SIR.pdf

%_SIR.pdf: PLOTS_PonceSamuel_S6CASA_EDO_SIR.py myout_S%_SIR.dat myout_I%_SIR.dat myout_R%_SIR.dat
	python $<

.PHONY : clean
clean :
	rm -f *.dat
	rm -f *.pdf
