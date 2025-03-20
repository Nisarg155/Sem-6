#include<stdio.h>
#include<stdlib.h>
#include"omp.h"

void calc(int id){
    for(int i = 0 ; i < 10 ; i++)
        printf("Id = %d,  i = %d\n", id, i);
}

int main(){
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
                calc(omp_get_thread_num());
            #pragma omp section
                calc(omp_get_thread_num());
            #pragma omp section
                calc(omp_get_thread_num());
        }
    }
}