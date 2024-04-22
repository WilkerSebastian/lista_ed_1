#include "hash.h"

#include <string.h>
#include <stdio.h>

// Função de hash simples que retorna o índice calculado a partir da chave
int hash(const char *str) {

     int v = 0;

    while (*str) {
        
        v += *str - 'a';
        str++;

    }

    return v;

}

// Inserção na tabela hash com sondagem linear
void insert(HashTable hashTable[], const char *key) {

    int index = hash(key);
    int i = 0;

    while (hashTable[index].occupied && i < TABLE_SIZE) {
        index = (index + 1) % TABLE_SIZE; // Sondagem linear
        i++;
    }

    if (i < TABLE_SIZE) {

        strcpy(hashTable[index].key, key);
        hashTable[index].occupied = 1;

    }

}

// Busca na tabela hash com sondagem linear
int search(HashTable hashTable[], const char *key) {

    int index = hash(key);
    int i = 0;

    while (hashTable[index].occupied && i < TABLE_SIZE) {
        
        if (strcmp(hashTable[index].key, key) == 0) 
            return FOUND; // Chave encontrada
        
        index = (index + 1) % TABLE_SIZE; // Sondagem linear
        i++;
    
    }
    
    return NOT_FOUND; // Chave não encontrada

}

// Remoção na tabela hash com sondagem linear
void removeKey(HashTable hashTable[], const char *key) {
    
    int index = hash(key);
    int i = 0;

    while (hashTable[index].occupied && i < TABLE_SIZE) {
        
        if (strcmp(hashTable[index].key, key) == 0) {
            hashTable[index].occupied = 0;
            return;
        }
        index = (index + 1) % TABLE_SIZE; // Sondagem linear
        i++;

    }
    
}

// Função para imprimir a tabela hash
void printHashTable(HashTable hashTable[]) {

    for (int i = 0; i < TABLE_SIZE; i++) {

        printf("%d: ", i);

        if (hashTable[i].occupied) 
            printf("%s", hashTable[i].key);
        
        printf("\n");

    }

    printf("\n");

}
