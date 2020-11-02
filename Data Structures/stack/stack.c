#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define error(x) {printf("\n\n"#x"\n"); exit(-1);}
#define nl printf("\n")








/*      stack struct        */

typedef struct __STACK__
{
    int *arr;
    int top;
}stack;

#define forEach(s)  for(int i = 0; i <= s.top; i++)






/*      functions       */


stack *newStack(int capacity)
{
    stack *output = (stack *)malloc(sizeof(stack));

    output->arr = (int *)malloc(capacity * sizeof(int));
    output->top = -1;


    return output;
}


bool isStackEmpty(stack s)
{
    return (s.top == -1);
}


void push(stack *s, int value)
{
    s->arr[++(s->top)] = value;
}


int pop(stack *s)
{
    if (isStackEmpty(*s))
        error(underflow);

    return s->arr[(s->top)--];
}


void printStack(stack s)
{
    printf("stack:  ");
    forEach(s)
        printf("%d, ", s.arr[i]);
    printf("\b\b\b\n");
}







int main()
{
    printf("\n\n ---------------- \n\n");
    printf("a simple test:\n\n");

    
    // initialize a new stack
    stack *s = newStack(100);
    

    // add some values
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    push(s, 11);
    push(s, 12);

    
    printStack(*s);
    nl;


    push(s, 14);
    printf("after push value 14:  \n"); 
    printStack(*s);
    nl;

    
    

    printf("call pop function:  %d\n", pop(s));
    nl;


    printf("after pop value 14:  "); printStack(*s);
    nl;




    printf("\n\n ---------------- \n\n\n");

    return 0;
}