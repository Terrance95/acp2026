#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char temp[100];
    char **names = NULL; // Pointer to store our array of strings
    int count = 0;

    while (1) {
        printf("Enter next name (or 'exit' to stop): ");
        scanf("%s", temp);

        if (strcmp(temp, "exit") == 0) {
            break;
        }

        // 1. Expand the 'names' array to hold one more char pointer
        char **ptr = realloc(names, (count + 1) * sizeof(char *));
        if (ptr == NULL) {
            printf("Memory allocation failed!\n");
            break;
        }
        names = ptr;

        // 2. Allocate exact memory for the new string and copy it
        names[count] = malloc(strlen(temp) + 1);
        if (names[count] != NULL) {
            strcpy(names[count], temp);
            count++;
        }
    }

    // Display the stored names
    printf("\nStored Names:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, names[i]);
        free(names[i]); // Free individual name memory
    }

    free(names); // Free the pointer array itself
    return 0;
}