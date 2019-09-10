all: teste

teste: main.o tad.o
	gcc -o teste main.o tad.o

main.o: main.c tad.h
	gcc -c main.c

tad.o: tad.c tad.h
	gcc -c tad.c

clean:
	rm -rf *.o *~ printy