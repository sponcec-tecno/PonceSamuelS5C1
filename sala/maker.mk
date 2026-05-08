.PHONY : data
data : myout_euler.dat myout_rk4.dat
%.dat : PonceSamuel_S6C1_EDO.cpp
	g++ $<
	./a.out

.PHONY : plots
plots : all.pdf euler.pdf rk4.pdf

%.pdf: PLOTS_PonceSamuel_S6CASA_EDO.py myout_euler.dat myout_rk4.dat
	python $<

.PHONY : clean
clean :
	rm -f *.dat
	rm -f *.pdf
