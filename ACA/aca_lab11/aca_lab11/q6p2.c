#include "header.h"
#include <time.h>

int main(){
    srand(time(NULL));
    int amin = 0;
    int  amax = 100;
    int n = 10;
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = amin + (rand() % ((amax-amin) + 1));
    }
    // for(int i = 0 ; i <  n; i++)
    //     printf("%d ",arr[i]);
    // printf("\n");

    int buckets = 5;
    int size = (amax - amin)/buckets;
    int shmid;
    int* histogram = (int*)shared(buckets*sizeof(int),&shmid);
    int n_proc = 4;
    int* index = (int*)shared(sizeof(int),&shmid);
    int *lock1 = (int*)shared(sizeof(int),&shmid);
    int *lock2 = (int*)shared(buckets*sizeof(int),&shmid);
    int condition = 0;
    spin_lock_init(&lock1,&condition);
    for(int i = 0 ; i < buckets ; i++){
        spin_lock_init(&(lock2[i]),&condition);
        histogram[i] = 0;
    }

    int id = process_fork(n_proc);
    while(1){
        int i;
        spin_lock(&lock1);
            i = *index;
            (*index)++;
        spin_unlock(&lock1);
        if(i >= n)
            break;
        
        int bin = (arr[i]-amin) / size;
        if(bin >= buckets)
            bin = buckets-1;
        spin_lock(&(lock2[bin]));
            histogram[bin]++;
        spin_unlock(&(lock2[bin]));
        printf("Value: %d in bin: %d\n",arr[i],bin);
    }
    process_join(n_proc,id);

    for(int  i = 0 ; i < buckets ; i++){
        printf("bucket[%d]: %d\n",i,histogram[i]);
    }
}