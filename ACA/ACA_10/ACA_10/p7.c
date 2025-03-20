#include <stdio.h>
#include "header.h"
int main(){
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  int id, nproc = 4, shmid, i;
  int *fac, final_factorial = 1;
  fac = (int *)shared(sizeof(int)*nproc, &shmid);
  id = process_fork(nproc);
  for(i = id; i<nproc; i+=nproc)
  {
      *(fac + i) = 1;
  }
  for(i = id +1; i<=num; i += nproc)
  {
      *(fac + id) *= i;
  }
  printf("Process %d : %d\n", id, *(fac + id));
  process_join(nproc, id);
  for(i = 0; i<nproc; i++)
  {
      final_factorial *= *(fac + i);
  }
   printf("Factorial of %d is %d\n", num, final_factorial);
}
