#include <stdio.h>
#include <stdlib.h>





#define check_V(g, x) if (x < 0 || x >= g->number_of_V)\
                      {\
                          printf("\n\x1b[31m \berror:  \x1b[0mgiven V is invalid\n\n\n");\
                          exit(0);\
                      }




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

void add_edge(GRAPH *g, int u, int v)
{

}


int main()
{
    return 0;
}