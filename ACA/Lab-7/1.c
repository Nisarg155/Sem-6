#include <stdio.h>
#include "omp.h"

static long num_steps = 10000000;
double step;

#define NUM_THREADS 1

int main()
{
    int i, nthrds;
    double pi, sum[NUM_THREADS] = {0.0};
    step = 1.0 / (double)num_steps;
    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();

#pragma omp parallel
    {
        int  id, nthreads;
        double x;
        id = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        if (id == 0)
        {
            nthrds = nthreads;
        }
        
        #pragma omp for 
        for (i = 0; i < num_steps; i++)
        {
            x = (i + 0.5) * step;
            sum[id] += 4.0 / (1.0 + x * x);
        }
    }
    double end = omp_get_wtime();
    printf("nthreads: %d\n", nthrds);
    for (i = 0, pi = 0.0; i < nthrds; i++)
    {
        pi += step * sum[i];
    }
    printf("Pi with OpenMP: %.15f\n", pi);
    printf("Time taken: %.15f seconds\n", end - start);
}


