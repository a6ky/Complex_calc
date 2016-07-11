#include "complex_calc.h"

complex_t cplx_div(complex_t a, complex_t b) {
	complex_t res;
	res.r = (a.r * b.r + a.i * b.i) / ((b.r*b.r) + (b.i*b.i));
	res.i = (a.i * b.r - a.r * b.i) / ((b.r*b.r) + (b.i*b.i));
	return res;
}
