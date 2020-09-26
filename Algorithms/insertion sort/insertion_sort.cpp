#include <iostream>
using namespace std;





void insertion_sort(int array[], int size)
{
    for (int i = 1; i <= size; i++)
        for (int j = i-1; j >= 0; j--)
        {
            if(array[j] > array[j+1])
            {
                int hold = array[j];
                array[j] = array[j+1];
                array[j+1] = hold;
            }

            else
                break;
        }
}




// a simple function for printing arrays 
void printArray(int array[], int size)
{
    cout << "[";

    for (int i = 0; i < size; i++)
        cout << array[i] << ", ";

    cout << "\b\b]\n";
}
 





int main()
{
    cout << "\n\n ---------------- \n\n";
    cout << "a simple test:\n\n";
    

    int array[] = {5, 113, 4, 0, -1, 3, -11, 43, 354, 132, 26, 33};

    cout << "before sort: ";
    printArray(array, 12);


    insertion_sort(array, 12);


    cout << "after sort: ";
    printArray(array, 12);


    cout << "\n ---------------- \n\n\n";



    return 0;
}