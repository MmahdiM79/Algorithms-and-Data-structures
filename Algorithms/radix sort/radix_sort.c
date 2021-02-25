#include <stdio.h>
#include <stdlib.h>




#define index(i, exp) ((x/exp) % 10)




int max(int array[])
{
    int max = array[0];
    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
        if (array[i] > max)
            max = array[i];

    return 0;
}   




int *counting_sort(int[] array, int n, int exp)
{
    int count[10+1] = {0};


    for (int i = 0; i < n; i++)
        count[index(array[i], exp)] += 1;

    for (int j = 1; j < 10+1; j++)
        count[j] += count[i-1];

    
    int *out = (int *)malloc(n*sizeof(int));
    for (int k = n-1; k >= 0; k--)
    {
        out[count[index(array[k], exp)]-1] = array[k];
        count[index(array[k], exp)] -= 1;
    }


    return out;
}




void radix_sort(int[] array)
{
    int size = sizeof(array)/sizeof(int);

    int max = max_array(array);


    int exp = 1, *res;
    while (max/exp > 0)
    {
        res = counting_sort(array, size, exp);
        for (int i = 0; i < size; i++)
            array[i] = res[i];
        
        exp *= 10;
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
    return 0;
}
