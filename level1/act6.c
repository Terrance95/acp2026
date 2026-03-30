#include <stdio.h>
#include <string.h>

void read_string(char *str, int size);
void swap_strings(char *str1, char *str2, int size);

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    read_string(str1, 100);

    printf("Enter second string: ");
    read_string(str2, 100);

    swap_strings(str1, str2, 100);

    printf("\n--- After Optimized Swap ---\n");
    printf("First: %s", str1);
    printf("Second: %s", str2);

    return 0;
}

void read_string(char *str, int size) {
    if (fgets(str, size, stdin)) {
        str[strcspn(str, "\n")] = 0;
    }
}

void swap_strings(char *str1, char *str2, int size) {
    char temp[size]; 
    memcpy(temp, str1, size);
    memcpy(str1, str2, size);
    memcpy(str2, temp, size);
}