#include <stdio.h>
#include <stdlib.h>






// colors
#define WHITE 'w';
#define GRAY 'g';
#define BLACK 'b';


/*      queue struct        */
typedef struct __QUEUE__
{
    int *arr;
    unsigned int capacity;

    int head;
    int tail;
    int size;

} queue;

queue *newQueue(int capacity)
{
    queue *output = (queue *) malloc(sizeof(queue));
    output->arr = (int *) malloc(capacity*sizeof(int));
    output->capacity = capacity;
    output->head = 0;
    output->tail = 0;
    output->size = 0;

    return output;
}

void enqueue(queue *q, int value)
{
    if (q->size == q->capacity)
    {
        printf("\n\x1b[31m \berror:  \x1b[0m Queue is full\n\n\n"); 
        exit(EXIT_FAILURE);
    }

    q->arr[q->tail] = value;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
}

int dequeue(queue *q)
{
    if (q->size == 0)
    {
        printf("\n\x1b[31m \berror:  \x1b[0m Queue is empty\n\n\n"); 
        exit(EXIT_FAILURE);
    }


    int output = q->arr[q->head];

    q->head = (q->head + 1) % q->capacity;
    q->size--;

    return output;
}







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