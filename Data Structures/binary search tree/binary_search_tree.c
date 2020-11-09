#include <stdio.h>
#include <stdlib.h>








        /*          Structs         */

typedef struct __NODE__
{
    int value;

    struct __NODE__ *p;
    struct __NODE__ *right;
    struct __NODE__ *left;

} NODE;

NODE *new_node(int value)
{
    NODE *output = (NODE *)malloc(sizeof(NODE));

    output->value = value;
    output->p = output->right = output->left = NULL;

    return output;
}




typedef struct __BINARY_SEARCH_TREE__
{
    NODE *root;
    int size;

} BST;

BST *new_bst()
{
    BST *output = (BST *)malloc(sizeof(BST));

    output->root = NULL;
    output->size = 0;

    return output;
}











            /*          functions           */


void tree_insert(BST *tree, NODE *node)
{
    NODE *current = tree->root;
    NODE *hold = NULL;

    while (current != NULL)
    {
        hold = current;

        if (node->value < current->value)
            current = current->left;
        else 
            current = current->right;
    }

    node->p = hold;

    if (hold == NULL)
        tree->root = node;
    
    else if (node->value < hold->value)
        hold->left = node;

    else 
        hold->right = node;



    tree->size++;
}


void inorder_tree_walk(BST *tree)
{
    if (tree->root != NULL)
    {
        NODE *current = tree->root;


        tree->root = current->left;
        inorder_tree_walk(tree);

        printf("%d ", current->value);

        tree->root = current->right;
        inorder_tree_walk(tree);


        tree->root = current;
    }
}


void preorder_tree_walk(BST *tree)
{
    if (tree->root != NULL)
    {
        NODE *current = tree->root;


        printf("%d ", current->value);

        tree->root = current->left;
        inorder_tree_walk(tree);

        tree->root = current->right;
        inorder_tree_walk(tree);


        tree->root = current;
    }
}















int main()
{
    return 0;
}
