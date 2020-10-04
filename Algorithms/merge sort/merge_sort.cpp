#include <iostream>
using namespace std;






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
    cout << "[";

    for (int i = 0; i < size-1; i++)
        cout << array[i] << ", ";

    cout << array[size-1] << "]\n";
}





int main()
{
    cout << "\n\n ---------------- \n\n";
    cout << "a simple test:\n\n";
    

    int array[] = {5, 113, 4, 0, -1, 3, -11, 43, 354, 132, 26, 33};

    cout << "before sort: ";
    printArray(array, 12);


    merge_sort(array, 0, 11);


    cout << "after sort: ";
    printArray(array, 12);


    cout << "\n ---------------- \n\n\n";



    return 0;
}