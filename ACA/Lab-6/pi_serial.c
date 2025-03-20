#include<stdio.h>
#include<stdlib.h>
#include "omp.h"

static long num_steps = 10000000;
double step;
int main(){
    int i ;
    double x  , pi , sum = 0.0;

    step = 1.0/(double)num_steps;
    double start = omp_get_wtime();

    for(i =0; i<num_steps; i++)
    {
        x = (i+0.5)*step;
        sum += 4.0/(1.0+x*x);
    }
    pi = step * sum;
    double end = omp_get_wtime();
    printf("Pi with OpenMP: %.15f\n",pi);
    printf("Time taken: %.15f seconds\n", end - start);
}