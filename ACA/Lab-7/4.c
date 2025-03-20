#include <stdio.h>
#include "omp.h"

#define NUM_THREADS 4
#define ARR_SZ 1000000
#define CHUNK_SZ 1000

int main()
{
    int arr[ARR_SZ], sum_static = 0, sum_dynamic = 0;
    for (int i = 0; i < ARR_SZ; i++)
    {
        arr[i] = i + 1;
    }

    omp_set_num_threads(NUM_THREADS);
    double start_static = omp_get_wtime();

#pragma omp parallel
    {
        long int partial_sum = 0;

#pragma omp for schedule(static, CHUNK_SZ)
        for (int i = 0; i < ARR_SZ; i++)
        {
            partial_sum += arr[i];
        }

#pragma omp critical
        sum_static += partial_sum;
    }

    double end_static = omp_get_wtime();
    double start_dynamic = omp_get_wtime();

    omp_set_num_threads(NUM_THREADS);

#pragma omp parallel
    {
        long int partial_sum = 0;

#pragma omp for schedule(dynamic, CHUNK_SZ)
        for (int i = 0; i < ARR_SZ; i++)
        {
            partial_sum += arr[i];
        }

#pragma omp critical
        sum_dynamic += partial_sum;
    }

    double end_dynamic = omp_get_wtime();

    printf("Static Scheduling Sum: %ld, Time: %.6f\n", sum_static, end_static - start_static);
    printf("Dynamic Scheduling Sum: %ld, Time: %.6f\n", sum_dynamic, end_dynamic - start_dynamic);
}
