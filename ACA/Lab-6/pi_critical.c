#include<stdlib.h>
#include<stdio.h>
#include "omp.h"

static long num_steps = 10000000;
double step;

#define NUM_THREADS 4


int main()
{
    int i ,nthrds;
    double pi ;
    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();

    #pragma omp parallel 
    {
        int i,id , nthreads;
        double x,sum;
        id = omp_get_thread_num();
        nthreads = omp_get_num_threads();

        if(id == 0 ){ nthrds = nthreads;
        printf("threads: %d\n", nthreads);}
        for(i = id , sum =0.0 ; i<num_steps;i = i+nthreads)
        {
            x = (i+0.5)*step;
            sum += 4.0/(1.0+x*x);
        }

        #pragma omp critical
            pi += step * sum;
    }
    double end = omp_get_wtime();
 
    printf("Pi with OpenMP: %.15f\n",pi);
    printf("Time taken: %.15f seconds\n", end - start);
}