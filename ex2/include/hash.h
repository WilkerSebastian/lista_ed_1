#pragma once

#define TABLE_SIZE 5
#define KEY_SIZE 11

#define FOUND 0
#define NOT_FOUND 1

typedef struct {
    char key[KEY_SIZE];
    int occupied;
} HashTable;

int hash(const char *str);
void insert(HashTable hashTable[], const char *key);
int search(HashTable hashTable[], const char *key);
void removeKey(HashTable hashTable[], const char *key);
void printHashTable(HashTable hashTable[]);