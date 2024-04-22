#include <stdio.h>
#include "heap.h"

int main() {

    int vector[] = {1, 5, 7, 6, 8, 9, 10, 12, 13, 15, 11, 14};
    int length = sizeof(vector) / sizeof(vector[0]);

    build(vector, length);

    printf("[ ");
    for (int i = 0; i < length; i++) {
        
        printf("%d ", vector[i]);

    }
    printf("]\n");

    return 0;

}