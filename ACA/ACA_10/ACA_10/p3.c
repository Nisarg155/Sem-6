#include "header.h"
#include <stdio.h>
int main()
{
  int nproc = 4;
  int id, a[10], *b, i;
  b = (int *)shared(sizeof(i) * 10, &i);
  for (i = 0; i < 10; i++)
  {
      printf ("Enter elements of a [%d]:",i+1);
      scanf ("%d", &a [i]);
  }
  id = process_fork(nproc);
  if (id == 0)
  {
      for (i = 0; i < 10; i += nproc){
          printf("Element %d is copied by process %d\n", i, id);
          *(b + i) = a[i];
      }
  }
  else if (id == 1)
  {
      for (i = 1; i <= 10; i += nproc){
          printf("Element %d is copied by process %d\n", i, id);
          *(b + i) = a[i];
      }
  }
  else if (id == 2)
  {
      for (i = 2; i < 10; i += nproc){
          printf("Element %d is copied by process %d\n", i, id);
          *(b + i) = a[i];
      }
  }
  else
  {
      for (i = 3; i <= 10; i += nproc){
          printf("Element %d is copied by process %d\n", i, id);
          *(b + i) = a[i];
      }
  }


  process_join(nproc, id);
  printf("elements of b :");
  for(int i=0;i<10;i++){
      printf("%d, ", b[i]);
  }
  printf("\n");
}
