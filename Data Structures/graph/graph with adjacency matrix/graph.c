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
    for (int i = 0; i < number_of_V; i++)
        for (int j = 0; j < number_of_V; j++)
            out->adj[i][j] = -1;
}





        /*      Functions       */


void add_edge(GRAPH *g, long u, long v)
{
    check_V(g, u);
    check_V(g, v);

    g->adj[u][v] = 1;
}


void add_edge_weight(GRAPH *g, long u, long v, long weight)
{
    check_V(g, u);
    check_V(g, v);

    g->adj[u][v] = weight;
}


int main()
{
    return 0;
}