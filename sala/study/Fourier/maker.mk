.PHONY: create
create: image.jpg

image.jpg: fourier.py magnitude.dat phase.dat
	python $<

.PHONY: clean
clean:
	rm -f *.jpg
