#include <stdio.h>





void merge(int array[], int startIndex, int halfIndex, int lastIndex)
{
    // calculate the size of the sub arrays
    int rightSubArraySize = halfIndex - startIndex + 1;
    int leftSubArraySize = lastIndex - halfIndex;



    // initialize first sub array
    int rightArray[rightSubArraySize + 1];
    for (int i = 0; i < rightSubArraySize; i++)
        rightArray[i] = array[startIndex + i - 1];


    // initialize second sub array
    int leftArray[leftSubArraySize + 1];
    for (int j = 0; j < leftSubArraySize; j++)
        leftArray[j] = array[halfIndex + j];


    

    // set sentinels
    rightArray[rightSubArraySize+1] = __INT_MAX__;
    leftArray[leftSubArraySize+1] = __INT_MAX__;



    // merging
    int i = 1, j = 1;
    for (int k = startIndex; k < lastIndex; k++)
        if (rightArray[i] <= leftArray[j])
            array[k] = rightArray[i++];
        else
            array[k] = leftArray[j++];

}