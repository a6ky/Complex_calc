#include "complex_calc.h"

complex_t cplx_mul(complex_t a, complex_t b) {
	complex_t res;
	res.r = a.r * b.r - a.i * b.i;
	res.i = b.r * a.r + a.r * b.i;
	return res;
}
