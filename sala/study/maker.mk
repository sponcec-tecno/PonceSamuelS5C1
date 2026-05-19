.PHONY: plot
plot: PLOTS_PonceSamuel_S6CASA_EDO.py all_EDO.pdf rk4_EDO.pdf euler_EDO.pdf
	python $<

.PHONY: data
data: PonceSamuel_S6CASA_EDO.cpp myout_euler_EDO.dat myout_eulerh1_EDO.dat myout_eulerh2_EDO.dat myout_rk4_EDO.dat myout_rk4h1_EDO.dat myout_rk4h2_EDO.dat
	g++ $<
	./a.out

.PHONY: clean
clean:
	rm -f *.dat
	rm -f *.out
	rm -f *.pdf
