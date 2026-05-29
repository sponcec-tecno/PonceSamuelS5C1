#Plotear el pdf
.PHONY: plot
plot: sol.pdf

%.pdf: PLOTS_SamuelPonce_S9C1_EDP.py t0.dat t1.dat t2.dat t3.dat t4.dat t5.dat t6.dat xh.dat
	python $<

%.dat: PonceSamuel_S9CASA_EDP.cpp
	g++ $< -o a1.out
	./a1.out


#Limpiar datos y archivos
.PHONY: clean
clean:
	rm -f *.dat
	rm -f *.pdf
	rm -f *.out
