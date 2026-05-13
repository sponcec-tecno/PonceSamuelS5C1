.PHONY : data
data : myout_x_e.dat myout_v_e.dat
%.dat : PonceSamuel_S7C1_EDO2ordenRESORTE.cpp
	g++ $< -o a1.out
	./a1.out

.PHONY : plot
plot : v.pdf x.pdf
%.pdf: PLOTS_PonceSamuel_S7C1_EDO2.py myout_x_e.dat myout_v_e.dat
	python $<

.PHONY : clean
clean :
	rm -f *.dat
	rm -f *.pdf

