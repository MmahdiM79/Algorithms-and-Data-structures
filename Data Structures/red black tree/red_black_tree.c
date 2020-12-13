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
    output->nil->right = output->nil;
    output->nil->left = output->nil;
    output->root = output->nil;
    output->size = 0;

    return output;
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


NODE *rb_minimum(RBT *t)
{
    if (t->root == t->nil)
        return NULL;


    NODE *current = t->root;

    while (current->left != t->nil)
        current = current->left;

    return current;
}


NODE *rb_maximum(RBT *t)
{
    if (t->root == t->nil)
        return NULL;

        
    NODE *current = t->root;

    while (current->right != t->nil)
        current = current->right;

    return current;
}


void inorder_walk(RBT *t)
{
    if (t->root != t->nil)
    {
        NODE *hold = t->root;


        t->root = hold->left;
        inorder_walk(t);

        printf("%d ", hold->value);

        t->root = hold->right;
        inorder_walk(t);


        t->root = hold;
    }
}


void preorder_walk(RBT *t)
{
    if (t->root != t->nil)
    {
        NODE *hold = t->root;


        printf("%d ", hold->value);

        t->root = hold->left;
        preorder_walk(t);

        t->root = hold->right;
        preorder_walk(t);


        t->root = hold;
    }
}


void postorder_walk(RBT *t)
{
    if (t->root != t->nil)
    {
        NODE *hold = t->root;


        t->root = hold->left;
        postorder_walk(t);

        t->root = hold->right;
        postorder_walk(t);

        printf("%d ", hold->value);


        t->root = hold;
    }
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


void rb_insert(RBT *t, NODE *new_node)
{
    NODE *y = t->nil;
    NODE *x = t->root;

    while (x != t->nil)
    {
        y = x;
        
        if (new_node->value < x->value)
            x = x->left;
        else
            x = x->right;
    }

    new_node->p = y;


    if (y == t->nil)
        t->root = new_node;

    else if (new_node->value < y->value)
        y->left = new_node;

    else
        y->right = new_node;


    new_node->left = t->nil;
    new_node->right = t->nil;
    new_node->color = RED;

    rb_insert_fixup(t, new_node);
}


void rb_transplant(RBT *t, NODE *u, NODE *v)
{
    if (u->p == t->nil)
        t->root = v;

    else if (u == u->p->left)
        u->p->left = v;

    else
        u->p->right = v;

    v->p = u->p;
}


void rb_delete_fixup(RBT *t, NODE *z)
{
    while (z != t->root && z->color == BLACK)
    {
        if (z == z->p->left)
        {
            NODE *hold = z->p->right;

            if (hold->color == RED)
            {
                hold->color = BLACK;
                z->p->color = RED;
                left_rotate(t, z->p);

                hold = z->p->right;
            }

            if (hold->left->color == BLACK && hold->right->color == BLACK)
            {
                hold->color = RED;
                z = z->p;
            }
            else if (hold->right->color == BLACK)
            {
                hold->left->color = BLACK;
                hold->color = RED;
                right_rotate(t, hold);

                hold = z->p->right;
            }

            hold->color = z->p->color;
            z->p->color = BLACK;
            hold->right->color = BLACK;
            left_rotate(t, z->p);
            z = t->root;
        }

        else
        {
            if (z == z->p->left)
            {
                NODE *hold = z->p->left;

                if (hold->color == RED)
                {
                    hold->color = BLACK;
                    z->p->color = RED;
                    right_rotate(t, z->p);

                    hold = z->p->left;
                }

                if (hold->right->color == BLACK && hold->left->color == BLACK)
                {
                    hold->color = RED;
                    z = z->p;
                }
                else if (hold->left->color == BLACK)
                {
                    hold->right->color = BLACK;
                    hold->color = RED;
                    left_rotate(t, hold);

                    hold = z->p->left;
                }

                hold->color = z->p->color;
                z->p->color = BLACK;
                hold->left->color = BLACK;
                right_rotate(t, z->p);
                z = t->root;
            }
        }
    }
}


void rb_delete(RBT *t, NODE *node_to_delete)
{
    NODE *x;
    NODE *y = node_to_delete;
    char y_original_color = y->color;


    if (node_to_delete->left = t->nil)
    {
        x = node_to_delete->right;
        rb_transplant(t, node_to_delete, node_to_delete->right);
    }

    else if (node_to_delete->right == t->nil)
    {
        x = node_to_delete->left;
        rb_transplant(t, node_to_delete, node_to_delete->left);
    }

    else
    {
        y = rb_minimum(t);
        y_original_color = y->color;

        x = y->right;


        if (y->p == node_to_delete)
            x->p = y;
        
        else
        {
            rb_transplant(t, y, y->right);
            y->right = node_to_delete->right;
            y->right->p = y;
        }

        rb_transplant(t, node_to_delete, y);
        y->left = node_to_delete->left;
        y->left->p = y;
        y->color = node_to_delete->color;
    }


    if (y_original_color == BLACK)
        rb_delete_fixup(t, x);
}













int main()
{


    printf("\n\n ---------------- \n\n");
    printf("a simple test:\n\n");


    // create a new binary tree
    RBT *t = new_rbt();

    // add some nodes
    rb_insert(t, new_node(2, RED));
    rb_insert(t, new_node(4, RED));
    rb_insert(t, new_node(1, RED));
    rb_insert(t, new_node(5, RED));
    rb_insert(t, new_node(8, RED));
    rb_insert(t, new_node(6, RED));
    rb_insert(t, new_node(9, RED));
    rb_insert(t, new_node(0, RED));
    rb_insert(t, new_node(10, RED));
    rb_insert(t, new_node(3, RED));
    rb_insert(t, new_node(11, RED));
    rb_insert(t, new_node(7, RED));


    // tree walks
    printf("tree walks:\n");
    printf("\tpreorder walk :  "); preorder_walk(t); printf("\n");
    printf("\tinorder walk  :  "); inorder_walk(t); printf("\n");
    printf("\tpostorder walk:  "); postorder_walk(t); printf("\n");


    // add a new node
    printf("\ninorder walk after add a new node with value 12:  "); 
    NODE *node = new_node(12, RED);
    rb_insert(t, node);
    inorder_walk(t);
    printf("\n");


    // remove a node
    printf("\ninorder walk after remove the node with value 12:  "); 
    rb_delete(t, node);
    inorder_walk(t);
    printf("\n");


    // find minimum
    printf("\nminimum value in this tree:  %d\n", rb_minimum(t)->value);
     // find maximum
    printf("\nmaximum value in this tree:  %d\n", rb_minimum(t)->value);






    printf("\n\n ---------------- \n\n\n");





    return 0;
}
