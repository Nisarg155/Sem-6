#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int process_fork (int nproc)
{
    int j;
    for (j=1;j<nproc; j++)
    {
        if (fork()==0)
        return (j);
    }

    return(0);
}



void process_join (int nproc, int id)
{
    int i;
    if (id==0)
    {
        for (i=1;i<nproc; i++)
            wait(0);
    }
    else
        exit(0);

}

char *shared (int size, int *shmid)
{
    *shmid =shmget(IPC_PRIVATE,size,0666|IPC_CREAT);
    return (shmat(*shmid,0,0));
}