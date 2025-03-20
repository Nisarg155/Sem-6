#include<stdio.h>
#include<stdlib.h>
#include "omp.h"

static long num_steps = 100;

int main(){
    int arr[num_steps]  , sum = 0;

    for(int i = 0; i < num_steps; i++)
    {
        arr[i] = i+1;
    }

    double start = omp_get_wtime();

    for(int i =0; i<num_steps; i++)
    {
        sum += arr[i];
    }

    double end = omp_get_wtime();
    printf("Serial Sum: %d\n", sum);
    printf("Time taken: %.15f seconds\n", end - start);
}