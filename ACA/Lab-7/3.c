#include <stdio.h>
#include "omp.h"

#define NUM_THREADS 4
#define num_steps 100

int main()
{
    long int prod = 0;
    int nthrds;
    int arr[num_steps], arr2[num_steps];

    for (int i = 0; i < num_steps; i++)
    {
        arr[i] = i + 1;
        arr2[i] = i + 1;
    }

    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();

#pragma omp parallel
    {
        int partial_mul = 0;
        int id ;
        id = omp_get_thread_num();
        if(id == 0)
        {
            printf("Threads %d\n",omp_get_num_threads());
        }
#pragma omp for reduction(+ : prod)
        for (int i = 0; i < num_steps; i++)
        {
            partial_mul = arr[i] * arr2[i];
            prod += partial_mul;
        }
    }

    double end = omp_get_wtime();

    printf("Time Taken %.16f\n", end - start);
    printf("Dot Product %ld\n", prod);
}