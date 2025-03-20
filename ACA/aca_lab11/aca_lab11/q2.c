#include "header.h"

int main(){
    int shmid;
    int *arr = (int*)shared(10*sizeof(int),&shmid);
    int n = 10;
    for(int i = 0 ; i < n ; i++)
        arr[i] = i;
    int n_proc = 4;
    int i = 0;
    int *index = (int*)shared(sizeof(int),&shmid);
    *index = 0;

    int id = process_fork(n_proc);
    while(1){
        i = *index;
        (*index)++;
        if(i >= n)
            break;
        arr[i] = arr[i] + 1;
        // printf("%d %d\n",id,i);
    }
    process_join(n_proc,id);

    for(i = 0 ; i < n ; i++)
        printf("%d ",arr[i]);
    printf("\n");
}