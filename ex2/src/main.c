#include <stdio.h>
#include "hash.h"

int main() {

    HashTable hashTable[TABLE_SIZE];

    // Inserção das chaves
    insert(hashTable, "abc");
    insert(hashTable, "bc");
    insert(hashTable, "bbc");
    insert(hashTable, "fbc");

    printHashTable(hashTable);

    // Busca das chaves
    int a = search(hashTable, "fbc");
    int b = search(hashTable, "bcd");

    printf("\na: %d     b: %d\n\n", a, b);

    printHashTable(hashTable);

    // Remoção das chaves
    removeKey(hashTable, "abc");
    removeKey(hashTable, "bbc");

    printHashTable(hashTable);
    
    return 0;

}