#include <stdio.h>
#include <math.h>
#include "heap.h"

int main() {

    int vector[] = {1, 5, 7, 6, 8, 9, 10, 12, 13, 15, 11, 14};
    int length = sizeof(vector) / sizeof(vector[0]);

    build(vector, length);

    printHeap(vector, length, 0, 0);

    insert(vector, &length, 20);
    insert(vector, &length, 3);
    insert(vector, &length, 18);
    
    build(vector, length);

    printf("\n-----------------\n");
    printHeap(vector, length, 0, 0);

    return 0;

}