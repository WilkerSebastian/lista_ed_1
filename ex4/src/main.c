#include <stdio.h>
#include "abb.h"

int main() {

    No* tree = NULL;

    int values[] = {10, 7, 15, 5, 9, 20, 18, 16, 19, 4};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) 
        tree = insert_recursive(tree, values[i]);


    inorder_traversal(tree);
    printf("\n");
    
    return 0;

}