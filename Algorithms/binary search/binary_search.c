#include <stdio.h>








void binary_search(int array[], int sizeOfArray, int target)
{
    if (sizeOfArray == 0)
    {
        printf("the given array not included the given target");  
        return;
    }


    if (sizeOfArray == 1)
    {
        if (array[0] == target)
            printf("the given array included the given target");
        else
            printf("the given array not included the given target");
            
        return;
    }



    int midIndex, start = 0, end = sizeOfArray-1;

    while (1)
    {
        if (start == end)
        {
            printf("the given array not included the given target");
            return;
        }



        midIndex = (start + end)/2;


        if (array[midIndex] == target)
        {
            printf("the given array included the given target");
            return;
        }

        if (target > array[midIndex])
            start = midIndex+1;
        else
            end = midIndex;
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
    printf("\n\n ---------------- \n\n");
    printf("a simple test:\n\n");


    int array[] = {-123, -23, -2, 0, 2, 5, 6, 34, 43, 55, 66, 76, 99,  100, 106, 345, 444, 2345, 3333};

    printf("array: ");
    printArray(array, 19);


    printf("\nsearch for -123 in array:  ");
    binary_search(array, 19, -123);

    printf("\nsearch for 150 in array:   ");
    binary_search(array, 19, 150);


    printf("\n\n ---------------- \n\n\n");
}