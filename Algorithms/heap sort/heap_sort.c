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





int main()
{
    return 0;
}