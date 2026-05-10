.PHONY : data
data : myout_euler.dat myout_rk4.dat myout_I.dat myout_R.dat myout_S.dat
%.dat : PonceSamuel_S6C1_EDO.cpp PonceSamuel_S6CASA_EDO_SIR.cpp
	g++ $<
	./a.out
	g++ PonceSamuel_S6CASA_EDO_SIR.cpp
	./a.out

.PHONY : plots
plots : all.pdf euler.pdf rk4.pdf SIR.pdf

%.pdf: PLOTS_PonceSamuel_S6CASA_EDO.py PLOTS_PonceSamuel_S6CASA_EDO_SIR.py myout_euler.dat myout_rk4.dat myout_S.dat myout_I.dat myout_R.dat
	python $<
	python PLOTS_PonceSamuel_S6CASA_EDO_SIR.py

.PHONY : clean
clean :
	rm -f *.dat
	rm -f *.pdf
