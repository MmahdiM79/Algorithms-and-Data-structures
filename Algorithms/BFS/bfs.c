#include<stdio.h>





typedef struct __NODE__
{
    char color;
    int value;
    struct __NODE__ *neighbor;
} Node;


typedef struct __GRAPH__
{
    Node (*adj)[];
    int number_of_V;
    int number_of_E;
} Graph;




int main()
{
    return 0;
}