#include <stdio.h>
#include <string.h>

#define MAX 256

// Function Prototypes
void read_string(char str[], int size);
void print_string(char str[]);
void swap_strings(char str1[], char str2[]);

int main() {
    char str1[MAX], str2[MAX];

    read_string(str1, MAX);
    read_string(str2, MAX);

    swap_strings(str1, str2);

    printf("First string: ");
    print_string(str1);

    printf("Second string: ");
    print_string(str2);

    return 0;
}

void read_string(char str[], int size) {
    if (fgets(str, size, stdin)) {
        str[strcspn(str, "\n")] = 0;
    }
}

void print_string(char str[]) {
    printf("%s\n", str);
}

void swap_strings(char str1[], char str2[]) {
    char temp[MAX];
    
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}