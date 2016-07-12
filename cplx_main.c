#include "complex_calc.h"

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

	DIR *dir;
	struct dirent *entry;

	int n_dir;

	dir = opendir("./lib");
	if (!dir) {
		perror("diropen");
		exit(1);
	}
	
	for (n_dir = 0; (entry = readdir(dir)) != NULL; n_dir++)
		;
    	
	closedir(dir);  

	char **arr_dir = (char **) calloc(n_dir, sizeof(char**));
	if (!arr_dir) {
		printf("Ошибка при распределении памяти\n");	
		exit(1);
	}

	printf("\n");	

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
	
		dir = opendir("./lib");

		int c = 0;

		printf("\nВыберите библиотеку:\n");

		while ((entry = readdir(dir)) != NULL) {
			if (strcmp(".", entry->d_name) && strcmp("..", entry->d_name)) {
				printf("%d) %s\n", c+1, entry->d_name);
				arr_dir[c] = (char *) calloc(200, sizeof(char));
				strcpy(arr_dir[c], entry->d_name);
				c++;
			}
		}	
			
		printf("> ");	
		scanf("%d", &op);

		char tmp_path[strlen(arr_dir[op-1]) + 6];
		bzero(tmp_path, sizeof(tmp_path));		
		strcat(tmp_path, "./lib/");
		strcat(tmp_path, arr_dir[op-1]);

		printf("%s\n", arr_dir[op-1]);		
		lib = load_lib(tmp_path);
		complex_t (*cplx_op_ptr) (complex_t a, complex_t b);

		/* Вырезаем lib и .so (libcplx_add.so -> cplx_add)*/ 
		for (c = 3; arr_dir[op-1][c] != '.'; c++)
			tmp_path[c-3] = arr_dir[op-1][c];
		tmp_path[c-3] = '\0';		
		
		cplx_op_ptr = dlsym(lib, tmp_path);
		res = (*cplx_op_ptr)(a, b);
				
		cplx_out(res);
		dlclose(lib);
	}
	
	int i;
	for (i = 0; i < n_dir; i++)
		free(arr_dir[i]);
	free(arr_dir);

	return 0;
}

	
