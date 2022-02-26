#include <iostream>
#include <omp.h>

int main(int argc, char** argv) {

	omp_set_num_threads(4);
    printf("threads number: %d\n", omp_get_num_threads());

#pragma omp parallel for
	for (int i = 0; i < 10; i++) {
		printf("i = %d, I am thread %d\n", i, omp_get_thread_num());
	}

#pragma omp parallel sections
	{
#pragma omp section
		{
			printf("section 1 in therad %d\n", omp_get_thread_num());
		}
#pragma omp section
		{
			printf("section 2 in therad %d\n", omp_get_thread_num());
		}
#pragma omp section
		{
			printf("section 3 in therad %d\n", omp_get_thread_num());
        }
    }

int tid;
int x = 0;
int y = 0;
int z = 0;
#pragma omp parallel private(tid) shared(x, y, z) num_threads(2)
    {
        tid = omp_get_thread_num();
        if(tid == 0) {
            y = 10;
        } else { 
            z = 20;
        }

    #pragma omp barrier

        if(tid == 1) {
            x = y + z;
        }
    }
    printf("x = %d y = %d z = %d\n", x, y, z);

}

