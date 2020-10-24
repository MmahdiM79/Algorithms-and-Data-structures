#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>



#define raiseERROR(x) {printf("\n\x1b[31m \berror:  \x1b[0m"#x"\n\n\n"); exit(EXIT_FAILURE);}
#define nl printf("\n")








/*      queue struct        */

typedef struct __QUEUE__
{
    int *arr;
    unsigned int capacity;

    int head;
    int tail;
    int size;

} queue;









/*      functions       */


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


bool is_empty(queue *q)
{
    return (q->size == 0);
}


bool is_full(queue *q)
{
    return (q->size == q->capacity);
}


void enqueue(queue *q, int value)
{
    if (is_full(q))
        raiseERROR(Queue is full);

    q->arr[q->tail] = value;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
}


int dequeue(queue *q)
{
    if (is_empty(q))
        raiseERROR(Queue is empty);

    int output = q->arr[q->head];

    q->head = (q->head + 1) % q->capacity;
    q->size--;

    return output;
}


int capacity(queue *q)
{
    return q->capacity;
}


int empty_space(queue *q)
{
    return (q->capacity - q->size);
}


void printqueue(queue *q)
{
    int h, t;
    h = q->head;
    t = q->tail;

    printf("queue:  ");
    while (h != t)
    {
        printf("%d, ", q->arr[h]);
        
        h++;
        h %= (q->capacity) -1;
    }
    printf("\b\b\n");

    return;
}







int main()
{
    printf("\n\n ---------------- \n\n");
    printf("a simple test:\n\n");

    
    // initialize a new queue
    queue *q = newQueue(100);

    // add some values
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);

    
    printqueue(q);
    nl;


    enqueue(q, 14);
    printf("after push value 14:  \n"); 
    printqueue(q);
    nl;

    
    

    printf("call pop function:  %d\n", dequeue(q));
    nl;


    printf("after pop value 14:  "); printqueue(q);
    nl;




    printf("\n\n ---------------- \n\n\n");

    return 0;
}


