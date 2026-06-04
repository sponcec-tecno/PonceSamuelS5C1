.PHONY: plot
plot: sol_difussion.pdf

%.pdf: PLOTS_SamuelPonce_S10C2_dif_EDP.py T0.dat T1.dat T2.dat T3.dat
	python $<

%.dat: PonceSamuel_S10C2_dif_EDP.cpp
	g++ $< -o a1.out
	./a1.out

.PHONY: clean
clean:
	rm -f *.dat
	rm -f *.pdf
	rm -f *.out
