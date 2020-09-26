#include <iostream>
using namespace std;
 










void selection_sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        // hold the index of the minmum value
        int min_value_index = i;


        // find the minimum value
        for (int j = i+1 ; j <= size; j++)
            if(array[j] < array[min_value_index])
                min_value_index = j;


        int hold = array[i];
        array[i] = array[min_value_index];
        array[min_value_index] = hold;;
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
    

    int array[] = {5, 13, 4, 0, -1, 3, -11, 43, 54, 32, 26, 33};

    cout << "before sort: ";
    printArray(array, 12);


    selection_sort(array, 12);


    cout << "after sort: ";
    printArray(array, 12);


    cout << "\n ---------------- \n\n\n";



 
    return 0;
}