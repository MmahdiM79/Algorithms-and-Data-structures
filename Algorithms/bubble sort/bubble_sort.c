// C program for implementation of Bubble sort 
// by sumitisnot4u
#include <stdio.h> 
  




void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  


// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
  


/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  




// Driver program to test above functions 
int main()
  {
      printf("\n\n ---------------- \n\n");
      printf("a simple test:\n\n");
 
 
      int array[] = {2, 12, 4, 0, -21, 23, -11, 43, 432, 130, 99, 33};
 
      printf("before sort: ");
      printArray(array, 12);
 
 
 
      bubble_sort(array, 12);
 
      printf("after sort: ");
      printArray(array, 12);
 
 
      printf("\n ---------------- \n\n\n");
 
 
 
 
     return 0;
 } 