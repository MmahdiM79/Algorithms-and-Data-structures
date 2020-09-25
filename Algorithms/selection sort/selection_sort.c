#include <stdio.h>










void selection_sort(int array[], int size)
{
    // hold the index of the minimum value
    int min_value_index;


    for (int i = 0; i < size-1; i++)
    {
        min_value_index = i;

        // find the minimum value
        for (int j = i+1; j < size; j++)
            if (array[j] < array[min_value_index])
                min_value_index = j;

        
        // swap
        int hold = array[i];
        array[i] = array[min_value_index];
        array[min_value_index] = hold;
    }


    return;
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
    

    int array[] = {2, 12, 4, 0, -21, 23, -11, 43, 432, 130, 99, 33};

    printf("before sort: ");
    printArray(array, 12);



    selection_sort(array, 12);

    printf("after sort: ");
    printArray(array, 12);


    printf("\n ---------------- \n\n\n");




    return 0;
}