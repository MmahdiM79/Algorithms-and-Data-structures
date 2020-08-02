#include <stdio.h>





void insertion_sort(int array[], int size)
{
    // required variables
    int hold = 0, j = 0;


    for (int i = 2; i < size; i++)
    {
        // hold to compare with others
        hold = array[i];

        // divide list to two parts (array[0] to array[j] and array[j+1] to array[size-1])
        j = i-1;


        // compare 'hold' with other variables in array[0] to array[j] part
        while (j >= 0 && array[j] > hold)
        {
            // shift variable
            array[j+1] = array[j];

            j--;
        }

        array[j+1] = hold;
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
    

    int array[] = {2, 10, 4, 0, -1, 23, -11, 43, 500, 100, 7, 33};

    printf("before sort: ");
    printArray(array, 12);



    insertion_sort(array, 12);

    printf("after sort: ");
    printArray(array, 12);


    printf("\n ---------------- \n\n\n");



    return 0;
}