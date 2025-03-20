#include <stdio.h>
#include "header.h"
int main()
{
    int *a, *next_index, i, id, k = 4, nproc = 3, shmid;
    int *lock1, unlock = 0;
    next_index = (int *)shared(sizeof(int), &shmid);
    *next_index = 0;
    a = (int *)shared(sizeof(int) * 10, &shmid);
    lock1 = (int *)shared(sizeof(int) * 10, &shmid);
    spin_lock_init(lock1, &unlock);
    for (int i = 0; i < 10; i++)
    {
        
        *(a + i) = i;
    }
    id = process_fork(nproc);
    while (1)
    {
        spin_lock(lock1);
        printf("process %d entered\n", i);
        i = *next_index;
        *next_index = *next_index + 1;
        printf("process %d exiting\n", i);
        spin_unlock(lock1);
        if (i < 10)
        {
            *(a + i) = *(a + i) + k;
        }
        else
            break;
    }
    process_join(nproc, id);
    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", *(a + i));
    }
    printf("\n");
}
