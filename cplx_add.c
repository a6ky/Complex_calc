#include "complex_calc.h"

complex_t cplx_add(complex_t a, complex_t b) {
	complex_t res;
	res.r = a.r + b.r;
	res.i = a.i + b.i;
	return res;
}
