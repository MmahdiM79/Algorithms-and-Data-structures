#include <stdio.h>
#include <stdlib.h>









int max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}





void counting_sort(int *array, int n, int k) 
{
    int count[k+1];
    for (int i = 0; i < k+1; i++)
        count[i] = 0;

    for (int j = 0; j < n; j++)
        count[array[j]]++;

    for (int i = 1; i < k+1; i++)
        count[i] += count[i-1];


    int out[n];
    for (int i = n-1; i >= 0; i--)
    {
        out[count[array[i]]-1] = array[i];
        count[array[i]]--;
    }

    for (int j = 0; j < n; j++)
        array[j] = out[j];
}






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
    

    int array[] = {2, 12, 4, 0, 21, 23, 11, 43, 432, 130, 99, 33};

    printf("before sort: ");
    printArray(array, 12);


    counting_sort(array, 12, max(array, 12));


    printf("after sort: ");
    printArray(array, 12);


    printf("\n ---------------- \n\n\n");



    return 0;
}

