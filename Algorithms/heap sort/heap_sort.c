#include <stdio.h>
#include <stdlib.h>





typedef struct __HEAP__
{
    int *array;
    long length;
    long size;
} HEAP;

HEAP *new_heap(long length)
{
    HEAP *output = (HEAP *)malloc(sizeof(HEAP));

    output->array = (int *)malloc(length * sizeof(int));
    output->length = length;
    output->size = 0;

    return output;
}



#define PARENT(x) (x/2)
#define RIGHT(x) (2*x + 1)
#define LEFT(x) (2*x)







int main()
{
    return 0;
}