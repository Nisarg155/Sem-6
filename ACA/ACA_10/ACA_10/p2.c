
#include "header.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
   int id, nproc;
   int sum1 = 0, *sum2 , sum=0, shmid;
   sum2 = (int *)shared(sizeof(int),&shmid);
   *sum2 = 0;
   int a=1, b=10, c=9, d=20;
   id = process_fork(2);

   if(id==0){
       sum1 = a+b;
       printf("sum by Parent process : %d\n", sum1);
   }
   else{
       *sum2 = c+d;
       printf("sum by process %d  : %d\n", id, *sum2);
   }
   process_join(2,id);
   sum = sum1 + *sum2;
   printf("Final sum %d\n", sum);
}
    