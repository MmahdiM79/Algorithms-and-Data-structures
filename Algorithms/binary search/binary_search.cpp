#include <iostream>
using namespace std;







void binary_search(int array[], int sizeOfArray, int target)
{
    if (sizeOfArray == 0)
    {
        cout << "the given array not included the given target";
        return;
    }


    if (sizeOfArray == 1)
    {
        if (array[0] == target)
            cout << "the given array included the given target";
        else
            cout << "the given array not included the given target";
            
        return;
    }



    int midIndex, start = 0, end = sizeOfArray-1;

    while (1)
    {
        if (start == end)
        {
            cout << "the given array not included the given target";
            return;
        }



        midIndex = (start + end)/2;


        if (array[midIndex] == target)
        {
            cout << "the given array included the given target";
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
    cout << "[";

    for (int i = 0; i < size-1; i++)
        cout << array[i] << ", ";

    cout << array[size-1] << "]\n";
}







int main()
{
    cout << "\n\n ---------------- \n\n";
    cout << "a simple test:\n\n";


    int array[] = {-35, -24, -2, 0, 4, 5, 6, 34, 55, 71, 76, 99, 106, 345, 444, 2245, 3333};

    cout << "array: ";
    printArray(array, 17);


    cout << "\nsearch for -123 in array:  ";
    binary_search(array, 17, -35);

    cout << "\nsearch for 150 in array:   ";
    binary_search(array, 17, 100);


    cout << "\n\n ---------------- \n\n\n";
}