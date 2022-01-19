all: Pearson

Pearson: Pearson.c
	gcc -g -Ofast -funroll-loops -finline-functions -ftree-vectorize $< -o $@ -lm -lSDL2 

clean:
	rm -Rf *~ Pearson
