#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define arrSize 15
int main()
{
    int a[arrSize];
    int NoOfBins;
    int binsize;
    int *histogram;
    int parhist[NoOfBins];
    int *lock, unlocked = 0, locked = 1;
    int shmidlock, shmidhist, shmidparhist;
    int id, nproc;
    int bin;
    int amin, amax;
    int i;
    printf("Enter No OF Bins: ");
    scanf("%d", &NoOfBins);
    // Initialize an Array
    for (i = 0; i < arrSize; i++)
    {
        // printf("Enter a[%d]: ", i);
        // scanf("%d", &a[i]);
        a[i] = i;
    }
    amin = a[0];
    amax = a[0];
    for (i = 1; i < arrSize; i++)
    {
        if (amin > a[i])
            amin = a[i];
        if (amax < a[i])
            amax = a[i];
    }
    binsize = (amax - amin) / NoOfBins;
    lock = (int *)shared(sizeof(int) * NoOfBins, &shmidlock);
    histogram = (int *)shared(sizeof(int) * NoOfBins, &shmidhist);
    printf("\nBin Size: %d", binsize);
    printf("\nNo. Of Bins: %d\n", NoOfBins);
    // Initialize spin_locks
    for (i = 0; i < NoOfBins; i++)
        spin_lock_init(lock + i, &unlocked);
    // Initialize histogram
    for (i = 0; i < NoOfBins; i++)
        *(histogram + i) = 0;
    printf("\n");
    nproc = NoOfBins;
    id = process_fork(nproc);
    for (i = 0; i < NoOfBins; i++)
        parhist[i] = 0;
    for (i = id; i < arrSize; i += nproc)
    {
        bin = abs(a[i] - amin) / binsize;
        if (bin >= NoOfBins)
            bin = NoOfBins - 1;
        printf("Process(%d): Number [%d] is %d\tBin: %d\n", id, i, a[i],
               bin);
        parhist[bin] += 1;
    }
    for (i = 0; i < NoOfBins; i++)
    {
        spin_lock(lock + i);
        *(histogram + i) += parhist[i];
        spin_unlock(lock + i);
    }
    printf("\n");
    process_join(nproc, id);
    for (i = 0; i < NoOfBins; i++)
    {
        printf("No Of Items in Bin (%d) is %d\n", i, *(histogram + i));
    }
    return 0;
}