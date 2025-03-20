
#include "header.h"
#include <stdio.h>
int main()
{
   // Declaration and scan values
   int id, a[3][3], b[3][3], *c, i, j, nproc = 3, shmid;
   c = (int *)shared(sizeof(int) * 3 * 3, &shmid);
   // c is shared among parent and children
   for (j = 0; j < 3; j++) // Scan matrix A
   {
       for (i = 0; i < 3; i++)
       {
           printf ("Enter element a[%d][%d]:",j+1,i+1);
           scanf ("%d", &a [j] [i]);
       }
   }
   printf("\n");

   for (j = 0; j < 3; j++) // Scan matrix B
   {
       for (i = 0; i < 3; i++)
       {
           printf("Enter element b[%d][%d]: ", j + 1, i + 1);
           scanf("%d", &b[j][i]);
       }
   }

   // program logic
   id = process_fork(nproc); // nproc=3
   for (i = id; i < 3; i += 3)
   {
       for (j = 0; j < 3; j++){
           *(c + 3 * i + j) = a[i][j] + b[i][j];
           printf("Element %d is added using process id: %d\n", *(c+3*i+j), id);
       }
   }

   process_join(nproc, id); // Children are exited
  
   // Print final Values
   for (i = 0; i < 3; i++) // print matrix A
   {
       for (j = 0; j < 3; j++)
       {
           printf("a [%d][%d]=%d \t",i+1,j+1, a[i][j]);
       }
       printf("\n");
   }
   printf("\n");

   for (i = 0; i < 3; i++) // print matrix B
   {
       for (j = 0; j < 3; j++)
       {
           printf("b [%d][%d]=%d \t",i+1,j+1, b[i][j]);
       }
       printf("\n");
   }
   printf("\n");
  
   for (i = 0; i < 3; i++) // print resultant matrix C
   {
       for (j = 0; j < 3; j++)
           printf("c [%d][%d]=%d\t", i + 1, j+1, *(c + 3 * i + j));
       printf("\n");
   }
}
