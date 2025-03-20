#include "header.h"
#include <stdio.h>

int main() 
{
    int m = 3;
    int mat1[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int id, nproc = 3, shmid, i;
    int *mat3;

    // Allocate shared memory for the result matrix (mat3)
    mat3 = (int *)shared(sizeof(int) * m * m, &shmid);

    // Print mat1
    printf("Matrix 1:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    // Print mat2
    printf("Matrix 2:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    // Fork processes for matrix multiplication
    id = process_fork(nproc);
    
    // Perform matrix multiplication in parallel
    for(i = id; i < m; i += nproc) {
        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int k = 0; k < m; k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            *(mat3 + (m * i) + j) = sum;
            printf("Process %d : %d\n", id, *(mat3 + (m * i) + j));
        }
    }

    // Join processes after multiplication
    process_join(nproc, id);

    // Print final result matrix mat3
    printf("\nFinal Matrix 3 (Result):\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", *(mat3 + (m * i) + j));
        }
        printf("\n");
    }

    return 0;
}
