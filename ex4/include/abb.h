#pragma once

typedef struct no {
    int value;
    struct no *left;
    struct no *right;
} No;

No* create(int value);
No* insert_recursive(No* node, int value);
void inorder_traversal(No* node);
No* search_recursive(No* node, int value);
No* remove_recursive(No* node, int value);
No* findMinNode(No* node);
void destroy_tree(No* node);