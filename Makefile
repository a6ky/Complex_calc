CC = gcc
CFLAGS = -g -Wall -ansi
LDFLAGS = -shared

TARGET_LIB = libcplx_add.so libcplx_sub.so libcplx_mul.so libcplx_div.so

EXECUTABLE = complex_calc

all: $(EXECUTABLE) $(TARGET_LIB) make_dir

$(EXECUTABLE): cplx_main.o 
	$(CC) $(CFLAGS) -o $@ cplx_main.o -ldl

cplx_main.o: cplx_main.c  
	$(CC) $(CFLAGS) -c cplx_main.c  

libcplx_add.so: cplx_add.o
	$(CC) $(LDFLAGS) -o $@ $^

libcplx_sub.so: cplx_sub.o
	$(CC) $(LDFLAGS) -o $@ $^

libcplx_mul.so: cplx_mul.o
	$(CC) $(LDFLAGS) -o $@ $^

libcplx_div.so: cplx_div.o
	$(CC) $(LDFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -fPIC $^  

make_dir: 
	mkdir -p ./lib && mv $(TARGET_LIB) ./lib

clean:
	rm -rf *.o $(TARGET_LIB) $(EXECUTABLE) ./lib