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


NODE *tree_search_recursive(BST *tree, int value)
{
    NODE *current = tree->root;
    NODE *output = NULL;


    if (current == NULL || current->value == value)
        return current;

    if (value < current->value)
    {
        tree->root = current->left;
        output = tree_search_recursive(tree, value);
        tree->root = current;

        return output;
    }
    else 
    {
        tree->root = current->right;
        output = tree_search_recursive(tree, value);
        tree->root = current;

        return output;
    }
}


NODE *tree_search(BST *tree, int value)
{
    NODE *current = tree->root;

    while (current != NULL)
    {
        if (current->value == value)
            return current;

        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }


    return NULL;
}


NODE *tree_minimum_node(BST *tree)
{
    if (tree->root == NULL)
        return NULL;

    
    NODE *current = tree->root;
    
    while (current->left != NULL)
        current = current->left;

    
    return current;
}


NODE *tree_maximum_node(BST *tree)
{
    if (tree->root == NULL)
        return NULL;

    
    NODE *current = tree->root;
    
    while (current->right != NULL)
        current = current->right;

    
    return current;
}


NODE *tree_successor(BST *tree)
{
    if (tree->root == NULL)
        return NULL;
    

    NODE *current = tree->root;

    if (current->right != NULL)
        return tree_minimum(tree);
    
    NODE *hold = current->p;
    while (hold != NULL && current == hold->right)
    {
        current = hold;
        hold = hold->p;
    }

    return hold;
}


NODE *tree_predecessor(BST *tree)
{
    if (tree->root == NULL)
        return NULL;
    

    NODE *current = tree->root;

    if (current->left != NULL)
        return tree_minimum(tree);
    
    NODE *hold = current->p;
    while (hold != NULL && current == hold->left)
    {
        current = hold;
        hold = hold->p;
    }

    return hold;
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


void postorder_tree_walk(BST *tree)
{
    if (tree->root != NULL)
    {
        NODE *current = tree->root;


        tree->root = current->left;
        inorder_tree_walk(tree);

        tree->root = current->right;
        inorder_tree_walk(tree);

        printf("%d ", current->value);


        tree->root = current;
    }
}



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


void transplant(BST *tree, NODE *node1, NODE *node2)
{
    if (node1->p == NULL)
        tree->root = node2;

    else if (node1 == node1->p->left)
        node1->p->left = node2;

    else
        node1->p->right = node2;

    if (node2 != NULL)
        node2->p = node1->p;
}


void tree_delete(BST *tree, NODE *node_to_delete)
{
    if (node_to_delete->left == NULL)
        transplant(tree, node_to_delete, node_to_delete->left);

    else if (node_to_delete->right == NULL)
        transplant(tree, node_to_delete, node_to_delete->right);

    else 
    {
        NODE *hold = tree_minimum(tree);

        if (hold->p != node_to_delete)
        {
            transplant(tree, hold, hold->right);
            hold->right = node_to_delete->right;
            hold->right->p = hold;
        }

        transplant(tree, node_to_delete, hold);
        hold->left = node_to_delete->left;
        hold->left->p = hold;
    }


    tree->size--;
}















int main()
{
    return 0;
}
