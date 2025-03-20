#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 100;
#define NUM_THREADS 4


int main()
{
    int arr[num_steps], sum = 0, nthrds;

    for (int i = 0; i < num_steps; i++)
    {
        arr[i] = i + 1;
    }

    omp_set_num_threads(NUM_THREADS);

    double start = omp_get_wtime();

#pragma omp parallel
    {
        int i = 0, id, nthreads,partial_sum =0;
        id = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        if (id == 0)
        {
            nthrds = nthreads;
            printf("threads: %d\n", nthreads);
        }
        for (i = id; i < num_steps; i += nthreads)
        {
            partial_sum += arr[i];
        }

        #pragma omp critical
        sum += partial_sum;
    }
    

    double end = omp_get_wtime();
    printf("Critical Sum: %d\n",sum);
    printf("Time taken: %.15f seconds\n", end - start);
}