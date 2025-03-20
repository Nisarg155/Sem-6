#include <stdio.h>
#include "header.h"

int main()
{
    int id, nproc;

    printf("Enter number of processes you want to create: ");
    scanf("%d", &nproc);

    id = process_fork(nproc);

    printf("Process id is %d\n", id);

    process_join(nproc, id);

    printf("Parent id is %d\n", id);

    return 0;
}
