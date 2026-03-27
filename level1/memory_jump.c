#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(2 * sizeof(int));
    
    // Print the starting address in Hexadecimal (%p)
    printf("Base Address: %p\n", (void*)ptr);
    printf("Next Address (ptr+1): %p\n", (void*)(ptr + 1)); 

    // Look at the difference: It should be exactly 4 bytes!
    
    free(ptr);
    return 0;
}