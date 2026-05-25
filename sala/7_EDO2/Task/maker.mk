#Ejercicio resorte
#Hago las gráficas
.PHONY : plot_r
plot_r : v_spring.pdf x_spring.pdf x_spring.pdf xvc_spring.pdf

%_spring.pdf: PLOTS_SamuelPonce_S7CASA_EDO2.py x_e_spring.dat v_e_spring.dat x_lf_spring.dat v_lf_spring.dat t_spring.dat xc_e_spring.dat vc_e_spring.dat xc_rk4_spring.dat xc_rk4_spring.dat
	python $<

%_spring.dat: PonceSamuel_S7CASA_EDO2ordenRESORTE.cpp
	g++ $< -o a1.out
	./a1.out

#Ejercicio 2
#Genero los datos
#.PHONY : data2
#data2 : myout_S_SIR.dat myout_I_SIR.dat myout_R_SIR.dat
#%_SIR.dat : PonceSamuel_S6CASA_EDO_SIR.cpp
#	g++ $< -o a2.out
#	./a2.out
#Hago las gráficas
#.PHONY : plot2
#plot2 : euler_SIR.pdf

#%_SIR.pdf: PLOTS_PonceSamuel_S6CASA_EDO_SIR.py myout_S_SIR.dat myout_I_SIR.dat myout_R_SIR.dat
#	python $<

#Si quieres limpiar los datos .dat y .pdf
.PHONY : clean
clean :
	rm -f *.dat
	rm -f *.pdf
	rm -f *.out
