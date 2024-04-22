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

// Função para construir uma heap a partir de um array
void build(int v[], int n) {
    int startIndex = (n / 2) - 1;  // Índice do último nó não folha

    // Executa heapify em cada nó não folha, de baixo para cima
    for (int i = startIndex; i >= 0; i--) 
        heapify(v, n, i);
}

// Função para calcular o índice do filho esquerdo
int left(int index) {
    return  2 * index + 1;
}

// Função para calcular o índice do filho direito
int right(int index) {
    return  2 * index + 2;
}
