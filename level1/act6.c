#include <stdio.h>
#include <string.h>

void read_string(char str[], int size);
void print_string(char str[]);
void swap_strings(char str1[], char str2[]);

int main() {

    char str1[100], str2[100];

    printf("Enter first string:\n");
    read_string(str1, 100);

    printf("Enter second string:\n");
    read_string(str2, 100);

    swap_strings(str1, str2);

    printf("After swapping:\n");

    printf("First string: ");
    print_string(str1);

    printf("Second string: ");
    print_string(str2);

    return 0;
}

void read_string(char str[], int size) {
    scanf("%s", str);
}

void print_string(char str[]) {
    printf("%s\n", str);
}

void swap_strings(char str1[], char str2[]) {

    char temp[100];

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}