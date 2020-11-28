#include <stdio.h>
#include <stdlib.h>






typedef struct __NODE__
{
    int value;
    char color;

    struct __NODE__ *p;
    struct __NODE__ *right;
    struct __NODE__ *left;
} NODE;

NODE *new_node(int value, char color)
{
    NODE *output = (NODE *)malloc(sizeof(NODE));

    output->value = value;
    output->color = color;

    output->p = NULL;
    output->right = NULL;
    output->left = NULL;

    return output;
}



typedef struct __RED_BLACK_TREE__
{
    NODE *nil;
    NODE *root;

    long size;
} RBT;

RBT *new_rbt()
{
    RBT *output = (RBT *)malloc(sizeof(RBT));

    output->nil = new_node(0, 'b');
    output->root = NULL;
    output->size = 0;

    return 0;
}









        /*          functions           */


void left_rotate(RBT *t, NODE *x)
{
    NODE *y = x->right;      // set y
    x->right = y->left;      // turn y's left subtree into x's right subtree

    if (y->left != t->nil)
        y->left->p = x;

    y->p = x->p;             // link x's parent to y


    if (x->p == t->nil)
        t->root = y;
    
    else if (x == x->p->left)
        x->p->left = y;

    else
        x->p->right = y;


    y->left = x;              // put x on y's left
    x->p = y;
}











int main()
{



    return 0;
}
