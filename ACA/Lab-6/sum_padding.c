#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 100;
#define NUM_THREADS 4
#define PAD 4

int main()
{
    int arr[num_steps], sum[NUM_THREADS][PAD] = {0}, nthrds;

    for (int i = 0; i < num_steps; i++)
    {
        arr[i] = i + 1;
    }

    omp_set_num_threads(NUM_THREADS);

    double start = omp_get_wtime();

#pragma omp parallel
    {
        int i = 0, id, nthreads;
        id = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        if (id == 0)
        {
            nthrds = nthreads;
            printf("threads: %d\n", nthreads);
        }
        for (i = id; i < num_steps; i += nthreads)
        {
            sum[id][0] += arr[i];
        }
    }
    int total_sum = 0;
    for (int i = 0; i < nthrds; i++)
    {
        total_sum += sum[i][0];
    }

    double end = omp_get_wtime();
    printf("Padding Sum: %d\n", total_sum);
    printf("Time taken: %.15f seconds\n", end - start);
}