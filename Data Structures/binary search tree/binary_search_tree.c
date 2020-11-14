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
        tree->root = current->left;
    else 
        tree->root = current->right;
        

    output = tree_search_recursive(tree, value);
    tree->root = current;
    return output;
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
        return tree_minimum_node(tree);
    
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
        return tree_minimum_node(tree);
    
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
        preorder_tree_walk(tree);

        tree->root = current->right;
        preorder_tree_walk(tree);


        tree->root = current;
    }
}


void postorder_tree_walk(BST *tree)
{
    if (tree->root != NULL)
    {
        NODE *current = tree->root;


        tree->root = current->left;
        postorder_tree_walk(tree);

        tree->root = current->right;
        postorder_tree_walk(tree);

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
        transplant(tree, node_to_delete, node_to_delete->right);

    else if (node_to_delete->right == NULL)
        transplant(tree, node_to_delete, node_to_delete->left);

    else 
    {
        NODE *root = tree->root;
        tree->root = node_to_delete->right;
        NODE *hold = tree_minimum_node(tree);
        tree->root = root;

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


    printf("\n\n ---------------- \n\n");
    printf("a simple test:\n\n");


    // create a new binary tree
    BST *t = new_bst();

    // add some nodes
    tree_insert(t, new_node(2));
    tree_insert(t, new_node(4));
    tree_insert(t, new_node(1));
    tree_insert(t, new_node(5));
    tree_insert(t, new_node(8));
    tree_insert(t, new_node(6));
    tree_insert(t, new_node(9));
    tree_insert(t, new_node(0));
    tree_insert(t, new_node(10));
    tree_insert(t, new_node(3));
    tree_insert(t, new_node(11));
    tree_insert(t, new_node(7));


    // tree walks
    printf("tree walks:\n");
    printf("\tpreorder walk :  "); preorder_tree_walk(t); printf("\n");
    printf("\tinorder walk  :  "); inorder_tree_walk(t); printf("\n");
    printf("\tpostorder walk:  "); postorder_tree_walk(t); printf("\n");


    // add a new node
    printf("\ninorder walk after add a new node with value 12:  "); 
    NODE *node = new_node(12);
    tree_insert(t, node);
    inorder_tree_walk(t);
    printf("\n");


    // remove a node
    printf("\ninorder walk after remove the node with value 12:  "); 
    tree_delete(t, node);
    inorder_tree_walk(t);
    printf("\n");


    // find minimum
    printf("\nminimum value in this tree:  %d\n", tree_minimum_node(t)->value);
     // find maximum
    printf("\nmaximum value in this tree:  %d\n", tree_maximum_node(t)->value);






    printf("\n\n ---------------- \n\n\n");



    return 0;
}
