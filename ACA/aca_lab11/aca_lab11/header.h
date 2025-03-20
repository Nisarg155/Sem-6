#include <unistd.h>  
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h>   
#include <stdlib.h>  
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>

int process_fork(int nproc)
{

    int j;
    for (j = 1; j < nproc; j++)
    {
        if (fork() == 0)
            return (j);
    }

    return (0);
}

void process_join(int nproc, int id)
{

    int i;
    if (id == 0)
    {
        for (i = 1; i < nproc; i++)
            wait(0);
    }
    else
        exit(0);
}

char *shared(int size, int *shmid)
{

    *shmid = shmget(IPC_PRIVATE, size, 0666 | IPC_CREAT);
    return (shmat(*shmid, 0, 0));
}

void spin_lock_init(int *lock, int *condition)
{

    int control;
    *lock = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    if (*condition == 1)
        control = 0;
    else
        control = 1;

    semctl(*lock, 0, SETVAL, control);
}

void spin_lock(int *lock)
{

    struct sembuf operations;
    operations.sem_num = 0;
    operations.sem_op = -1;
    operations.sem_flg = 0;
    semop(*lock, &operations, 1);
}

void spin_unlock(int *lock)
{

    struct sembuf operations;
    operations.sem_num = 0;
    operations.sem_op = 1;
    operations.sem_flg = 0;
    semop(*lock, &operations, 1);
}