#include <stdio.h>
#include <stdlib.h>





typedef struct __HEAP__
{
    int *array;
    long capacity;
    long length;
    long size;
} HEAP;

HEAP *new_heap(long capacity)
{
    HEAP *output = (HEAP *)malloc(sizeof(HEAP));

    output->array = (int *)malloc(capacity * sizeof(int));
    output->capacity = capacity;
    output->length = 0;
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