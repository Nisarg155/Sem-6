#include<stdio.h>
#include<stdlib.h>
#include "omp.h"

int main(){
    int sum = 1, fact = 1;
    omp_set_num_threads(4);
    #pragma omp parallel private(fact) reduction(*:sum)
    {
        fact = 1;
        int id = omp_get_thread_num();
        int nthrds = omp_get_num_threads();
        for(int i = 1+id; i <= 6; i+=nthrds){
            fact *=  i;
        }
        printf("ID = %d, fact = %d\n",id,fact);
        sum *= fact;
    }
    printf("Sum = %d\n",sum);
}