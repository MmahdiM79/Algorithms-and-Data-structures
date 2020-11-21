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

void add_value(HEAP h, int value)
{
    h.array[(h.length)++] = value;
}






#define PARENT(x) (x/2)
#define RIGHT(x) (2*x + 1)
#define LEFT(x) (2*x)
#define swap_int(x, y) \
        {\
            int hold = x;\
            x = y;\
            y = hold;\
        }



void max_heapify(HEAP h, int index)
{
    int r = RIGHT(index);
    int l = LEFT(index);


    int largest;
    if (l <= h.size && h.array[l] > h.array[index])
        largest = l;
    else 
        largest = index;

    if (r <= h.size && h.array[r] > h.array[largest])
        largest = r;


    if (largest != index)
    {
        swap_int(h.array[index], h.array[largest]);
        max_heapify(h, largest);
    }
}












int main()
{
    return 0;
}