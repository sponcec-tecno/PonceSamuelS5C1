all.pdf: PLOTS_PonceSamuel_S6CASA_EDO.py myout_rk.dat myout_e.dat
	python $<

rk4.pdf: PLOTS_PonceSamuel_S6CASA_EDO.py myout_rk.dat
	python $<

euler.pdf: PLOTS_PonceSamuel_S6CASA_EDO.py myout_e.dat
	python $<

myout_rk.dat: PonceSamuel_S6C1_EDO.cpp
	g++ $<
	./a.out

myout_e.dat: PonceSamuel_S6C1_EDO.cpp
	g++ $<
	./a.out
