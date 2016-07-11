CC=gcc
CFLAGS=-g -Wall

#complex_calc: cplx_main.o libcplx_add.so libcplx_sub.so libcplx_mul.so libcplx_div.so 
#	gcc -ldl -o $@ cplx_main.o -L. -lcplx_add -lcplx_sub -lcplx_mul -lcplx_div -Wl,-rpath,.

all: complex_calc libcplx

complex_calc: cplx_main.o 
	gcc -ldl -o $@ cplx_main.o 

libcplx: libcplx_add.so libcplx_sub.so libcplx_mul.so libcplx_div.so

cplx_main.o: cplx_main.c  
	gcc -c cplx_main.c  

libcplx_add.so: cplx_add.o
	gcc -shared -o libcplx_add.so $^

libcplx_sub.so: cplx_sub.o
	gcc -shared -o libcplx_sub.so $^

libcplx_mul.so: cplx_mul.o
	gcc -shared -o libcplx_mul.so $^

libcplx_div.so: cplx_div.o
	gcc -shared -o libcplx_div.so $^

cplx_add.o: cplx_add.c 
	gcc -c -fPIC cplx_add.c 

cplx_sub.o: cplx_sub.c
	gcc -c -fPIC cplx_sub.c 

cplx_mul.o: cplx_mul.c 
	gcc -c -fPIC cplx_mul.c 

cplx_div.o: cplx_div.c 
	gcc -c -fPIC cplx_div.c 

clear:
	rm -rf *.o *.so complex_calc
