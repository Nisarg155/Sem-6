#include "header.h" //Declaration and scan values
int main()
{
    int sum = 0, *final_sum, id, N, i, shmid, nproc = 4;
    int locked = 1, unlocked = 0, *lock;
    lock = (int *)shared(sizeof(int), &shmid);
    final_sum = (int *)shared(sizeof(sum), &i);
    *final_sum = 0;
    printf("\n Enter N :");
    scanf("%d", &N);
    spin_lock_init(lock, &unlocked);
    id = process_fork(nproc);
    printf("process %d does ->  ", id);
    for (i = id; i <= N; i += nproc)
    {
        sum = sum + i;
        printf("%d  ", i);
    }
    printf("\n");
    spin_lock(lock);
    *final_sum = sum + *final_sum;
    printf("id = %d sum = %d \n", id, sum);
    spin_unlock(lock);
    process_join(4, id);
    printf("\nSum: %d\n", *final_sum);
    return 0;
}