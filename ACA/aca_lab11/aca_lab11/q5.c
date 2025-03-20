#include "header.h"
int main()
{
    int sum = 0, *final_sum, id, a[10], i = 0, nproc = 4;
    int unlocked = 0, *lock1, *lock2;
    int shmid, *index;
    final_sum = (int *)shared(sizeof(int), &shmid);
    *final_sum = 0;
    lock1 = (int *)shared(sizeof(int), &shmid);
    lock2 = (int *)shared(sizeof(int), &shmid);
    index = (int *)shared(sizeof(int), &shmid);
    *index = 0;
    for (i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    spin_lock_init(lock1, &unlocked);
    spin_lock_init(lock2, &unlocked);
    id = process_fork(nproc);
    printf("process %d sums ", id);
    while (1)
    {
        spin_lock(lock1);
        i = *index;
        *index = *index + 1;
        printf("a[%d], ", i);
        spin_unlock(lock1);
        printf("\n");
        if (i < 10)
            sum = sum + a[i];
        else
            break;
    }
    spin_lock(lock2);
    *final_sum = sum + *final_sum;
    spin_unlock(lock2);
    process_join(nproc, id);
    printf("\n Sum: %d\n", *final_sum);
    return 0;
}