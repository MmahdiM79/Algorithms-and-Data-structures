#include <stdio.h>
#include <stdlib.h>








        /*          Structs         */

typedef struct __NODE__
{
    int value;

    struct __NODE__ *p;
    struct __NODE__ *right;
    struct __NODE__ *left;

} node;

#define Node node *

node *new_node(int value)
{
    node *output = (node *)malloc(sizeof(node));

    output->value = value;
    output->p = output->right = output->left = NULL;

    return output;
}




typedef struct __BINARY_SEARCH_TREE__
{
    node *root;
    int size;

} BST;

#define Bst BST *

BST *new_bst()
{
    BST *output = (BST *)malloc(sizeof(BST));

    output->root = NULL;
    output->size = 0;

    return output;
}











            /*          functions           */


void inorder_tree_walk(Bst tree)
{
    Node current = tree->root;

    if (current != NULL)
    {
        tree->root = current->left;
        inorder_tree_walk(tree);

        printf("%d ", current->value);

        tree->root = current->right;
        inorder_tree_walk(tree);
    }

    tree->root = current;


    return;
}












int main()
{
    return 0;
}
