#include <stdio.h>








void binary_search(int array[], int startIndex, int endIndex, int target)
{
    if (startIndex >= endIndex)
    {
        if (array[0] == target)
            printf("the given array included the given target");
        else
            printf("the given array not included the given target");
            
        return;
    }



    int midIndex = (startIndex - endIndex + 1)/2;

    if (array[midIndex] == target)
    {
        printf("the given array included the given target");
        return;
    }

    if (target > array[midIndex])
        binary_search(array, midIndex, endIndex, target);
    else 
        binary_search(array, startIndex, midIndex, target);
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


    int array[] = {-123, -23, -2, 0, 2, 5, 6, 34, 55, 66, 76, 99, 106, 345, 444, 2345, 3333};

    printf("array: ");
    printArray(array, 17);


    printf("\nsearch for -123 in array:  ");
    binary_search(array, 0, 16, -123);

    printf("\nsearch for 150 in array:   ");
    binary_search(array, 0, 16, 150);


    printf("\n\n ---------------- \n\n\n");
}