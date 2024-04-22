#include <stdio.h>
#include "heap.h"

int main() {

    int vector[] = {1, 5, 7, 6, 8, 9, 10, 12, 13, 15, 11, 14};
    int length = sizeof(vector) / sizeof(vector[0]);

    build(vector, length);

    printArray(vector, length);

    insert(vector, &length, 20);
    insert(vector, &length, 3);
    insert(vector, &length, 18);

    printArray(vector, length);

    return 0;

}

void printArray(int v[], int n) {

    printf("[ ");
    for (int i = 0; i < n; i++) {
        
        printf("%d ", v[i]);

    }
    printf("]\n");

}