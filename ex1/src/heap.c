#include "heap.h"

// Função para transformar uma subárvore em uma heap, mantendo a propriedade de heap
void heapify(int v[], int n, int i) {
    int largest = i;  // Inicializa o índice do maior elemento como o próprio índice
    int lt = left(i);  // Índice do filho esquerdo
    int rt = right(i);  // Índice do filho direito

    // Se o filho esquerdo é maior que o nó atual
    if (lt < n && v[lt] > v[largest])
        largest = lt;

    // Se o filho direito é maior que o maior dos filhos (esquerdo ou atual)
    if (rt < n && v[rt] > v[largest])
        largest = rt;

    // Se o maior elemento não é o nó atual
    if (largest != i) {
        // Troca o nó atual com o maior dos filhos
        int temp = v[i];
        v[i] = v[largest];
        v[largest] = temp;

        // Chama recursivamente heapify no nó afetado
        heapify(v, n, largest);
    }
}

// Adiciona o novo elemento ao final do array
void insert(int v[], int *n, int element) {

    v[*n] = element; 
    (*n)++; // Incrementa o tamanho do array

    int i = *n - 1; // Índice do novo elemento

    int father = parent(i); // Índice do pai do elemento atual

    // Sift-up do novo elemento até restaurar a propriedade de heap
    while (i > 0 && v[father] < v[i]) {

        father = parent(i); // Índice do pai do elemento atual

        // Troca o elemento com seu pai
        int temp = v[i];
        v[i] = v[father];
        v[father] = temp;
        // Atualiza o índice para o pai
        i = father;
    }

    // Reconstrói a heap após a inserção
    build(v, *n);

}

// Função para construir uma heap a partir de um array
void build(int v[], int n) {
    int startIndex = (n / 2) - 1;  // Índice do último nó não folha

    // Executa heapify em cada nó não folha, de baixo para cima
    for (int i = startIndex; i >= 0; i--) 
        heapify(v, n, i);
}

void removeMax(int v[], int *n) {

    if (*n == 0) 
        return;

    // Troca o primeiro elemento valor máximo com o último
    int temp = v[0];
    v[0] = v[*n - 1];
    v[*n - 1] = temp;

    // Decrementa o tamanho da heap
    (*n)--;

    // Reconstrói a heap após a remoção
    build(v, *n);
    
}

// Função para calcular o índice do filho esquerdo
int left(int index) {
    return  2 * index + 1;
}

// Função para calcular o índice do filho direito
int right(int index) {
    return  2 * index + 2;
}

int parent(int index) {

    return (index - 1) / 2;

}

void printSpaces(int count) {
    for (int i = 0; i < count; ++i) {
        printf(" ");
    }
}

// Função para imprimir a heap como uma árvore
void printHeap(int v[], int n, int index, int level) {
    if (index < n) {

        printHeap(v, n, right(index), level + 1); // Imprime o nó direito
        printSpaces(level * 4); // Espaçamento para alinhar os elementos

        printf("%d\n", v[index]); // Imprime o nó atual

        printHeap(v, n, left(index), level + 1); // Imprime o nó esquerdo

    }
}