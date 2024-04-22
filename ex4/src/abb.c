#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar um novo nó
No* create(int value) {

    No* node = (No*)malloc(sizeof(No));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;

}

// Função para inserir um novo nó de forma recursiva
No* insert_recursive(No* node, int value) {

    // Se a árvore estiver vazia, retornamos um novo nó
    if (node == NULL) 
        return create(value);
    

    // Caso contrário, realizamos a inserção de forma recursiva
    if (value < node->value) 
        node->left = insert_recursive(node->left, value);

    else if (value > node->value) 
        node->right = insert_recursive(node->right, value);
    

    return node;

}

// Função para percorrer a árvore em ordem (in-order) e imprimir os nós
void inorder_traversal(No* node) {

    if (node != NULL) {

        inorder_traversal(node->left);
        printf("%d ", node->value);
        inorder_traversal(node->right);

    }

}