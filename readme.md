# Lista de Estrutura de Dados

### Exericio 1

(heap) Considere o seguinte vetor:

[ 1, 5, 7, 6, 8, 9, 10, 12, 13, 15, 11, 14 ]

(a) Construa a max-heap deste vetor mostrando todas as operações realizadas;

(b) Com a max-heap, faça a inserção dos elementos 20, 3, 18;

(c) Com a heap alterada do exercício anterior, faça a remoção do valor máximo três vezes;

(d) Altere a prioridade do nó que está na posição 1 do vetor para o valor 2;

(e) Altere a prioridade do nó que está na posição 4 do vetor para o valor 100;

(f) Implemente a função pai, filho esquerda, filho direita;

(g) Implemente a função desce;

(h) Implemente a função constrói heap;

(i) Implemente a função de ordenação heapsort;

(j) Implemente a função que extrai o valor máximo da heap;

(k) Implemente a função que altera a prioridade da heap.

### Exericio 2

```c
int hash(const char * str){

    int v;

    while(*str){
        v += *str - 'a';
        str++;
    }

    return v;
}
```

Implemente as operações de inserção, busca e remoção de uma hash com sondagem linear alocada estaticamente, onde cada bucket é uma string de 10 caracteres. Faça as operações de inserção, remoção e busca do exercício 2a nesta implementação.

### Exericio 3

(h) Implemente a função de inserção pelo método recursivo.

(i) Implemente a função de busca pelo método recursivo.

(j) Implemente a função de remoção pelo método recursivo.

(k) Implemente a função de destruição da árvore.