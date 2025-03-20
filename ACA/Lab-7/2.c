#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 4
#define ROW 3
#define COL 3

int main()
{
    int mat[ROW][COL] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    int mat2[ROW][COL] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    int result[ROW][COL] = {0};

    int nthrds = 0;
    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();

#pragma omp single
        {
            nthrds = nthreads;
        }

        // Parallelized outer and middle loops
#pragma omp for collapse(2)
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                int sum = 0;
                for (int k = 0; k < COL; k++)
                {
                    sum += mat[i][k] * mat2[k][j];
                }
                result[i][j] = sum;  // Safe write, each thread writes a separate result[i][j]
            }
        }
    }

    double end = omp_get_wtime();
    printf("Threads: %d\n", nthrds);
    printf("Time Taken: %.15f seconds\n", end - start);

    printf("\nResult Matrix:\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf(" %d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
        