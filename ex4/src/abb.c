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

// Função de remoção recursiva
No* remove_recursive(No* node, int value) {

    // Caso base: se a árvore estiver vazia
    if (node == NULL) 
        return node;
    
    // Se a chave for menor que a chave da raiz, busca na subárvore esquerda
    if (value < node->value) 
        node->left = remove_recursive(node->left, value);
        
    // Se a chave for maior que a chave da raiz, busca na subárvore direita
    else if (value > node->value) 
        node->right = remove_recursive(node->right, value);
    
    // Se a chave for igual à chave da raiz, este é o nó a ser removido
    else {

        // se nó sem filhos ou com apenas um filho
        if (node->left == NULL) {

            No* temp = node->right;
            free(node);
            return temp;

        } else if (node->right == NULL) {

            No* temp = node->left;
            free(node);
            return temp;

        }
        
        // nó com dois filhos
        // Encontrando o sucessor (nó com o menor valor na subárvore direita)
        No* temp = findMinNode(node->right);
        
        // Copiando o valor do sucessor para este nó
        node->value = temp->value;
        
        // Removendo o sucessor da subárvore direita
        node->right = remove_recursive(node->right, temp->value);

    }
    
    return node;

}

// Função para encontrar o nó com o menor valor em uma subárvore
No* findMinNode(No* node) {

    No* current = node;

    while (current && current->left != NULL) 
        current = current->left;

    return current;

}

// Função para percorrer a árvore em ordem (in-order) e imprimir os nós
void inorder_traversal(No* node) {

    if (node != NULL) {

        inorder_traversal(node->left);
        printf("%d ", node->value);
        inorder_traversal(node->right);

    }

}

// Função de busca recursiva
No* search_recursive(No* node, int value) {

    // Se a árvore estiver vazia ou a chave for encontrada na raiz
    if (node == NULL || node->value == value) 
        return node; 
    
    // Se a chave for menor que a chave da raiz, busca na subárvore esquerda
    if (value < node->value) 
        return search_recursive(node->left, value);
    
    // Se a chave for maior que a chave da raiz, busca na subárvore direita
    return search_recursive(node->right, value);

}
