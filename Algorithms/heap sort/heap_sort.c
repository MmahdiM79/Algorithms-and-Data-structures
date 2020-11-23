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



void max_heapify(HEAP *h, int index)
{
    int r = RIGHT(index);
    int l = LEFT(index);


    int largest;
    if (l <= h->size && h->array[l] > h->array[index])
        largest = l;
    else 
        largest = index;

    if (r <= h.size && h.array[r] > h.array[largest])
        largest = r;


    if (largest != index)
    {
        swap_int(h->array[index], h->array[largest]);
        max_heapify(h, largest);
    }
}


void build_max_heap(HEAP *h)
{
    h->size = h->length;
    for (int i = (h->length/2)-1; i >= 0; i--)
        max_heapify(h, i);
}


void heap_sort(int array[])
{
    HEAP *h = new_heap(sizeof(array)/sizeof(array[0]));
    h->array = array;
    h->length = h->capacity;


    build_max_heap(h);
    for (int i = h->length; i > 2; i--)
    {
        swap_int(array[1], array[i]);
        h->size--;
        max_heapify(h, 0);
    }
}


// a simple function for printing arrays 
void printArray(int array[], int size)
{
    printf("[");

    for (int i = 0; i < size; i++)
        printf("%d, ", array[i]);

    printf("\b\b]\n");
}












int main()
{
    return 0;
}