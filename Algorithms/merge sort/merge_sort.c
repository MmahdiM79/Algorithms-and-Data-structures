#include <stdio.h>





void merge(int array[], int startIndex, int halfIndex, int lastIndex)
{
    // calculate the size of the sub arrays
    int firstSubArraySize = halfIndex - startIndex + 1;
    int secondSubArraySize = lastIndex - halfIndex;



    // initialize first sub array
    int firstArray[firstSubArraySize + 1];
    for (int i = 0; i < firstSubArraySize; i++)
        firstArray[i] = array[startIndex + i - 1];


    // initialize second sub array
    int secondArray[secondSubArraySize + 1];
    for (int j = 0; j < secondSubArraySize; j++)
        secondArray[j] = array[halfIndex + j];


    

    // set sentinels
    firstArray[firstSubArraySize+1] = __INT_MAX__;
    secondArray[secondSubArraySize+1] = __INT_MAX__;



    // merging
    int i = 1, j = 1;
    for (int k = startIndex; k < lastIndex; k++)
        if (firstArray[i] <= secondArray[j])
            array[k] = firstArray[i++];
        else
            array[k] = secondArray[j++];

}