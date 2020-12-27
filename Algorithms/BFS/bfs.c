#include <stdio.h>
#include <stdlib.h>






// colors
#define WHITE 'w';
#define GRAY 'g';
#define BLACK 'b';






typedef struct __NODE__
{
    char color;
    int value;
    int d;
    Node *p;
    struct __NODE__ *neighbor;
} Node;

Node *new_Node(int value)
{
    Node *out = malloc(sizeof(Node));
    out->value = value;
    out->d = 0;
    out->p = NULL;
    out->neighbor = NULL;
    out->color = '\0';

    return out;
}


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





void BFS(Graph *g, Node *s)
{
    Node *u;
    for (int i = 0; i < g->number_of_V; i++)
    {
        if (&g->adj[i] == s)
            continue;

        u = g->adj[i];
        u->color = WHITE;
        u->d = INT32_MAX;
        u->p = NULL;
    }

    s->color = GRAY;
    s->d = 0;
    s->p = NULL;
}



int main()
{
    return 0;
}