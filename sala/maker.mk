fig.png: myout_e.dat myout_rk.dat plot.py
	python plot.py

myout_e.dat: PonceSamuel_S6C1_EDO.cpp
	g++ PonceSamuel_S6C1_EDO.cpp
	./a.out

myout_rk.dat: PonceSamuel_S6C1_EDO.cpp
	g++ PonceSamuel_S6C1_EDO.cpp
	./a.out
