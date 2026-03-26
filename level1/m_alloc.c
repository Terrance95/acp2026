#include <stdio.h>
#include <stdlib.h> // Essential for memory functions

int main() {
    int *ptr;
    int n = 3;

    // 1. MALLOC: Allocate space for 3 integers
    ptr = (int*)malloc(n * sizeof(int));

    if (ptr == NULL) { 
        printf("Memory not allocated.\n"); 
        return 1; 
    }

    ptr[0] = 10; ptr[1] = 20; ptr[2] = 30;

    // 2. REALLOC: Expand the memory to hold 5 integers
    ptr = (int*)realloc(ptr, 5 * sizeof(int));
    ptr[3] = 40; ptr[4] = 50;

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i)); // Using Pointer Arithmetic!
    }

    // 3. FREE: The most important step for NAOS efficiency
    free(ptr); 

    return 0;
}