#include <stdio.h>










void bubble_sort(int array[], int size)
{
    // hold values for swaping
    int hold;



    for (int i = 0; i < size; i++)
        for (int j = i+1; j < size; j++)
            if (array[i] > array[j])
            {
                hold = array[i];
                array[i] = array[j];
                array[j] = hold;
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



    bubble_sort(array, 12);

    printf("after sort: ");
    printArray(array, 12);


    printf("\n ---------------- \n\n\n");




    return 0;
}