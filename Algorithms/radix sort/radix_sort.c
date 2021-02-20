#include <stdio.h>








#define max_array(arr) {int max = arr[0];\
                        for (int i = 0; i < sizeof(arr)/sizeof(int); i++)\
                            if (max < arr[i])\
                                max = arr[i];\
                        return max}
                        
#define index(i, exp) ((x/exp) % 10)




int *counting_sort(int[] array, int n, int exp)
{
    int count[10+!] = {0};


    for (int i = 0; i < n; i++)
        count[index(array[i], exp)] += 1;

    for (int j = 1; j < 10+1; j++)
        count[j] += count[i-1];

    
    int out[n];
    for (int k = n-1; k >= 0; k--)
    {
        out[count[index(array[k], exp)]-1] = array[k];
        count[index(array[k], exp)] -= 1;
    }


    return out;
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
    return 0;
}
