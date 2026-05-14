.PHONY : data
data : myout_x_e.dat myout_v_e.dat myout_x_lf.dat myout_v_lf.dat
%.dat : PonceSamuel_S7C1_EDO2ordenRESORTE.cpp
	g++ $< -o a.out
	./a.out

.PHONY : plot
plot : v.pdf x.pdf
%.pdf: PLOTS_PonceSamuel_S7C1_EDO2.py myout_x_e.dat myout_v_e.dat myout_x_lf.dat myout_v_lf.dat
	python $<

.PHONY : clean
clean :
	rm -f *.dat
	rm -f *.pdf
	rm -f *.out

#¿Se puede ingresar el argumento para el commit de git?
