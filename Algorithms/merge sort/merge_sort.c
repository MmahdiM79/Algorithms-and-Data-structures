#include <stdio.h>





void merge(int array[], int startIndex, int midIndex, int lastIndex)
{
    // calculate the size of the sub arrays
    int rightSubArraySize = midIndex - startIndex + 1;
    int leftSubArraySize = lastIndex - midIndex;



    // initialize first sub array
    int rightArray[rightSubArraySize + 1];
    for (int i = 0; i < rightSubArraySize; i++)
        rightArray[i] = array[startIndex + i];


    // initialize second sub array
    int leftArray[leftSubArraySize + 1];
    for (int j = 0; j < leftSubArraySize; j++)
        leftArray[j] = array[midIndex + j + 1];


    

    // set sentinels
    rightArray[rightSubArraySize] = __INT_MAX__;
    leftArray[leftSubArraySize] = __INT_MAX__;



    // merging
    int i = 0, j = 0;
    for (int k = startIndex; k <= lastIndex; k++)
        if (rightArray[i] <= leftArray[j])
            array[k] = rightArray[i++];
        else
            array[k] = leftArray[j++];

}




void merge_sort(int array[], int startIndex, int lastIndex)
{
    if (startIndex < lastIndex)
    {
        int midIndex = (startIndex + lastIndex)/2;


        // sort first half
        merge_sort(array, startIndex, midIndex);

        // sort second half
        merge_sort(array, midIndex+1, lastIndex);

        // merge two halfs
        merge(array, startIndex, midIndex, lastIndex);
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
    

    int array[] = {2, 12, 4, 0, -21, 23, -11, 43, 432, 130, 99, 33};

    printf("before sort: ");
    printArray(array, 12);



    merge_sort(array, 0, 11);

    printf("after sort: ");
    printArray(array, 12);


    printf("\n ---------------- \n\n\n");




    return 0;
}