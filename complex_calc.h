#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <strings.h>

typedef struct {
	float r;
	float i;
} complex_t;

complex_t cplx_add(complex_t a, complex_t b);
complex_t cplx_sub(complex_t a, complex_t b);
complex_t cplx_mul(complex_t a, complex_t b);
complex_t cplx_div(complex_t a, complex_t b);

