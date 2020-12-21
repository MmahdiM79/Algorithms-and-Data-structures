#include <stdio.h>
#include <stdlib.h>






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

Graph *new_Graph(int number_of_V)
{
    Graph *out = malloc(sizeof(Graph));
    out->number_of_V = number_of_V;
    out->adj = malloc(out->number_of_V*sizeof(Graph *));

    return out;
}




int main()
{
    return 0;
}