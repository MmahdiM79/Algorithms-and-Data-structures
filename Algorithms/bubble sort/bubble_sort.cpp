#include <iostream>
using namespace std;





void bubble_sort(int array[], int size)
{
    // hold values for swaping
    int hold;


    for (int i = 1; i <= size; i++)
    {
        bool isSwaped = false;

        for (int j = 0; j <= size-i ; j++)
            if(array[j] > array[j+1])
            {
                hold = array[j];
                array[j] = array[j+1];
                array[j+1] = hold;

                isSwaped = true;
            }

        if(!isSwaped)
            break;
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


    bubble_sort(array, 12);


    cout << "after sort: ";
    printArray(array, 12);


    cout << "\n ---------------- \n\n\n";



    return 0;
}