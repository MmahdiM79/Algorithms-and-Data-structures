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

    out->adj = (long **)malloc(number_of_V*sizeof(number_of_V*sizeof(long)));
    for (int i = 0; i < number_of_V; i++)
    {
        out->adj[i] = (long *)malloc(number_of_V*sizeof(long));

        for (int j = 0; j < number_of_V; j++)
            out->adj[i][j] = -1;
    }

    return out;
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


int has_edge(GRAPH *g, int u, int v)
{
    check_V(g, u);
    check_V(g, v);

    return (g->adj[u][v] != -1);
}


int has_vertice(GRAPH *g, int v)
{
    return !(v >= g->number_of_V || v < 0);
}









int main()
{
    // create a new graph
    GRAPH *g = new_graph(10);


    // add some edges
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 0, 3);
    add_edge(g, 1, 4);
    add_edge(g, 1, 5);
    add_edge(g, 1, 6);
    add_edge(g, 1, 7);
    add_edge(g, 2, 8);
    add_edge(g, 2, 9);
    add_edge(g, 2, 1);
    add_edge(g, 3, 4);
    add_edge(g, 3, 9);
    add_edge(g, 9, 5);
    add_edge(g, 8, 7);
    add_edge(g, 6, 4);


    // check some edges
    printf("\n\nis there any edge between vertices 0 and 3 ?:   %d\n", has_edge(g, 0, 3));
    printf("is there any edge between vertices 0 and 3 ?:   %d\n", has_edge(g, 4, 3));

    // check some vertices
    printf("\n\nis there 5  vertice in graph g ?:   %d\n", has_vertice(g, 5));
    printf("is there 10 vertice in graph g ?:   %d\n\n\n", has_vertice(g, 11));
    


    return 0;
}