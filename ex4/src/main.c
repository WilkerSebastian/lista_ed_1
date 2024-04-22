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

    int value = 9;
    
    No* result = search_recursive(tree, value);

    if (result != NULL)
        printf("Chave %d encontrada na árvore.\n", value);

    else 
        printf("Chave %d não encontrada na árvore.\n", value);

    remove_recursive(tree, 15);
    remove_recursive(tree, 7);

    inorder_traversal(tree);
    printf("\n");

    destroy_tree(tree);

    return 0;

}