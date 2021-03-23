CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -shared

EXEC = complex_calc

OBJ_CATALOG = obj
LIB_CATALOG = lib
LIB_PREFIX = lib

LIB_LIST = cplx_add.o cplx_sub.o cplx_mul.o cplx_div.o
SOURCE = $(wildcard *.c)
MAIN_SRC = cplx_main.c

OBJ = $(patsubst %.c, $(OBJ_CATALOG)/%.o, $(SOURCE))
LIB = $(patsubst %.o, $(LIB_CATALOG)/%.so, $(addprefix lib, $(LIB_LIST)))

all: $(EXEC) $(OBJ) $(LIB)

$(EXEC): $(OBJ) 
	$(CC) $(MAIN_SRC) -o $@ -ldl
	
$(OBJ_CATALOG)/%.o: %.c
	$(CC) -fPIC -c $< -o $@

$(LIB_CATALOG)/$(LIB_PREFIX)%.so: $(OBJ_CATALOG)/%.o
	$(CC) $(LDFLAGS) -o $@ $<

$(shell mkdir -p $(OBJ_CATALOG) $(LIB_CATALOG))

clean:
	rm -rf $(EXEC) $(OBJ_CATALOG) $(LIB_CATALOG)