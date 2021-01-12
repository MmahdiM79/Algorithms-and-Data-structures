#include <stdio.h>
#include <stdlib.h>








typedef struct __GRAPH__
{
    long number_of_V;
    long number_of_E;

    long **adj;
    
} GRAPH;

GRAPH *new_graph(long number_of_V)
{
    GRAPH *out = (GRAPH *)malloc(sizeof(GRAPH));

    out->number_of_V = number_of_V;
    out->number_of_E = 0;

    out->adj = (int **)malloc(number_of_V*sizeof(number_of_V*sizeof(long)));
}



int main()
{
    return 0;
}