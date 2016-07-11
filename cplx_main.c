#include "complex_calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void* load_lib(char *lib_name) {
	void *lib;
	lib = dlopen(lib_name, RTLD_NOW);
	if (!lib) {
		printf("dlopen() error: %s\n", dlerror());
		exit(1);
	}
	return lib;	
}

void cplx_out(complex_t r) {
	printf("\nРезультат: ");
	printf("res.re = %f ", r.r);
	printf("res.im = %f\n\n", r.i);
}
	
int main()
{
	complex_t a, b, res;
	int op;
	void *lib;
	
	while(1) {
		printf("Введите два числа:\n");
        	printf("a.re: ");
        	scanf("%f", &a.r);
        	printf("a.im: ");
        	scanf("%f", &a.i);
        	printf("b.re: ");
        	scanf("%f", &b.r);
        	printf("b.im: ");
        	scanf("%f", &b.i);	       
	
		printf("\nВыберите один из пунктов: \n\n");

		printf("1. Сложение\n");	
        	printf("2. Вычитание\n");
        	printf("3. Умножение\n");
        	printf("4. Деление\n");
        	printf("5. Выход\n\n");
		printf("> ");
		scanf("%d", &op);

		switch(op) {	
			case 1: {
				lib = load_lib("./libcplx_add.so");
				complex_t (*cplx_add_ptr) (complex_t a, complex_t b);
				cplx_add_ptr = dlsym(lib, "cplx_add");
				res = (*cplx_add_ptr)(a, b);

				//res = cplx_add(a, b);
				cplx_out(res);
				dlclose(lib);
				break;
			}
			case 2: {
				lib = load_lib("./libcplx_sub.so");
				complex_t (*cplx_sub_ptr) (complex_t a, complex_t b);
				cplx_sub_ptr = dlsym(lib, "cplx_sub");
				res = cplx_sub_ptr(a, b);

				//res = cplx_sub(a, b);
				cplx_out(res);
				dlclose(lib);
				break;
			}	
			case 3: {
				lib = load_lib("./libcplx_mul.so");
				complex_t (*cplx_mul_ptr) (complex_t a, complex_t b);
				cplx_mul_ptr = dlsym(lib, "cplx_mul");
				res = cplx_mul_ptr(a, b);				

				//res = cplx_mul(a, b);
				cplx_out(res);
				dlclose(lib);
			}
			case 4: {				
				lib = load_lib("./libcplx_div.so");
				complex_t (*cplx_div_ptr) (complex_t a, complex_t b);
				cplx_div_ptr = dlsym(lib, "cplx_div");
				cplx_div_ptr(a, b);

				//res = cplx_div(a, b);
				cplx_out(res);
				dlclose(lib);
				break;
			}
			case 5: 
				exit(0);	
			default:
				printf("Некорректный ввод.\n");
		}	
	}
	return 0;
}

	
