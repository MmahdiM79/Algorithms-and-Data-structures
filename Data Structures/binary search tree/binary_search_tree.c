#include <stdio.h>






typedef struct __NODE__
{
    int value;

    struct __NODE__ *p;
    struct __NODE__ *right;
    struct __NODE__ *left;

} node;



typedef struct __BINARY_SEARCH_TREE__
{
    node *root;
    int size;
    
} BST;









int main()
{
    return 0;
}
