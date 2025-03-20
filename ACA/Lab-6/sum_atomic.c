#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 100;
#define NUM_THREADS 4

int main()
{
    int arr[num_steps], sum = 0;

    for (int i = 0; i < num_steps; i++)
    {
        arr[i] = i + 1;
    }

    omp_set_num_threads(NUM_THREADS);

    double start = omp_get_wtime();

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();

        if (id == 0)
        {
            printf("threads: %d\n", nthreads);
        }

        for (int i = id; i < num_steps; i += nthreads)
        {
#pragma omp atomic
            sum += arr[i]; // Atomic addition
        }
    }

    double end = omp_get_wtime();
    printf("Atomic Sum: %d\n", sum);
    printf("Time taken: %.15f seconds\n", end - start);

    return 0;
}
