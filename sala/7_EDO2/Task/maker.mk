#Ejercicio resorte
#Hago las gráficas
.PHONY : plot_resorte
plot_resorte : v_spring.pdf x_spring.pdf x_spring.pdf xvc_spring.pdf

%_spring.pdf: PLOTS_SamuelPonce_S7CASA_EDO2.py x_e_spring.dat v_e_spring.dat x_lf_spring.dat v_lf_spring.dat t_spring.dat xc_e_spring.dat vc_e_spring.dat xc_rk4_spring.dat xc_rk4_spring.dat
	python $<
#Reviso los datos
%_spring.dat: PonceSamuel_S7CASA_EDO2ordenRESORTE.cpp
	g++ $< -o a1.out
	./a1.out


#Ejercicio Sol fijo
#Hago las gráficas
.PHONY : plot_planets
plot_planets : system_sunfix_pl.pdf motion_sunmv_pl.pdf system_sunmv_pl.pdf

%_pl.pdf: PLOTS_SamuelPonce_S7CASA_ODE2_PLANETAS.py x_e_Sf.dat vx_e_Sf.dat y_e_Sf.dat vy_e_Sf.dat x_lf_Sf.dat vx_lf_Sf.dat y_lf_Sf.dat vy_lf_Sf.dat xT_e_Sm.dat vxT_e_Sm.dat yT_e_Sm.dat vyT_e_Sm.dat xS_e_Sm.dat vxS_e_Sm.dat yS_e_Sm.dat vyS_e_Sm.dat xT_lf_Sm.dat vxT_lf_Sm.dat yT_lf_Sm.dat vyT_lf_Sm.dat xS_lf_Sm.dat vxS_lf_Sm.dat yS_lf_Sm.dat vyS_lf_Sm.dat
	python $<

#Reviso los datos para Sol fijo
%_Sf.dat: PonceSamuel_S7CASA_TierraSolFijo.cpp
	g++ $< -o a2.out
	./a2.out

#Reviso los datos para Sol móvil
%_Sm.dat: PonceSamuel_S7CASA_TierraSolLibre.cpp
	g++ $< -o a3.out
	./a3.out


#Si quieres limpiar los datos .dat, .pdf y .out
.PHONY : clean
clean :
	rm -f *.dat
	rm -f *.pdf
	rm -f *.out
