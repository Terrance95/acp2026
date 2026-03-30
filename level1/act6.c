#include <stdio.h>
#include <string.h>

#define MAX 256

// Function Prototypes
void read_string(char str[], int size);
void print_string(char str[]);
void swap_strings(char str1[], char str2[]);

int main() {
    char str1[MAX], str2[MAX];

    // Using fgets inside read_string for space-handling and safety
    read_string(str1, MAX);
    read_string(str2, MAX);

    swap_strings(str1, str2);

    // Clean output for BATS matching
    printf("First string: ");
    print_string(str1);

    printf("Second string: ");
    print_string(str2);

    return 0;
}

void read_string(char str[], int size) {
    // fgets reads up to size-1 characters and adds \0
    if (fgets(str, size, stdin)) {
        // Remove the trailing newline character (\n) if present
        str[strcspn(str, "\n")] = 0;
    }
}

void print_string(char str[]) {
    // Standard output with a newline for clarity
    printf("%s\n", str);
}

void swap_strings(char str1[], char str2[]) {
    char temp[MAX];
    
    // Copying the data physically between buffers
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}