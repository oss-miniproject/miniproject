gmp : main.c GMP.o
	gcc -o gmp main.c GMP.o

GMP.o : GMP.c GMP.h
	gcc -c GMP.c -o GMP.o

clean :
	rm *.o gmp