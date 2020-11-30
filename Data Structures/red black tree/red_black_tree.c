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

#define RED 'r'
#define BLACK 'b'

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


void right_rotate(RBT *t, NODE *x)
{
    NODE *y = x->left;       // set y
    x->left = y->right;      // turn y's right subtree into x's left subtree

    if (y->right != t->nil)
        y->right->p = x;

    y->p = x->p;             // link x's parent to y


    if (x->p == t->nil)
        t->root = y;
    
    else if (x == x->p->right)
        x->p->right = y;

    else
        x->p->left = y;


    y->right = x;              // put x on y's right
    x->p = y;
}


void rb_insert_fixup(RBT *t, NODE *added_node)
{
    while (added_node->p->color == RED)
    {
        if (added_node->p == added_node->p->p->left)
        {
            NODE *uncle = added_node->p->p->right;

            if (uncle->color == RED)
            {
                added_node->p->color = BLACK;
                uncle->color = BLACK;
                added_node->p->p->color = RED;
                added_node = added_node->p->p;
            }
            else if (added_node == added_node->p->right)
            {
                added_node = added_node->p;
                left_rotate(t, added_node);
            }

            added_node->p->color = BLACK;
            added_node->p->p->color = RED;
            right_rotate(t, added_node->p->p);
        }
        else
        {
            NODE *uncle = added_node->p->p->left;

            if (uncle->color == RED)
            {
                added_node->p->color = BLACK;
                uncle->color = BLACK;
                added_node->p->p->color = RED;
                added_node = added_node->p->p;
            }
            else if (added_node == added_node->p->left)
            {
                added_node = added_node->p;
                right_rotate(t, added_node);
            }

            added_node->p->color = BLACK;
            added_node->p->p->color = RED;
            left_rotate(t, added_node->p->p);
        }
    }

    t->root->color = BLACK;
}














int main()
{



    return 0;
}
