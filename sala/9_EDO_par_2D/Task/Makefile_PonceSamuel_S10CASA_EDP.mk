#Para imprimir el ejercicio
.PHONY: plot
plot: sol_difussion.pdf

%.pdf: PLOTS_SamuelPonce_S10CASA_EDP.py T0.dat T1.dat T2.dat T3.dat
	python $<

%.dat: PonceSamuel_S10CASA_EDP.cpp
	g++ $< -o a1.out
	./a1.out

#Para limpiar los archivos generados
.PHONY: clean
clean:
	rm -f *.dat
	rm -f *.pdf
	rm -f *.out
