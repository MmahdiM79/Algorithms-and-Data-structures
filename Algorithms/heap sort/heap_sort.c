#include <stdio.h>








#define swap(x, y) \
            int hold = x;\
            x = y;\
            y = hold;\


#define RIGHT(x) (2*x + 2)
#define LEFT(x) (2*x + 1)



void max_heapify(int array[], int size, int i)
{
    int l = LEFT(i);
    int r = RIGHT(i); 
 

    int largest;
    if (l < size && array[l] > array[i])
        largest = l;
    else
        largest = i;
 
    if (r < size && array[r] > array[largest])
        largest = r;

 
    if (largest != i) 
    {
        swap(array[i], array[largest]);
        max_heapify(array, size, largest);
    }
}


void heap_sort(int array[], int size)
{
    for (int i = size/2 - 1; i >= 0; i--)
        max_heapify(array, size, i);
 

    for (int i = size-1; i > 0; i--) 
    {
        swap(array[0], array[i]);
        max_heapify(array, i, 0);
    }
}





int main()
{
    return 0;
}