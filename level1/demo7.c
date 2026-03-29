#include <stdio.h>
#include <string.h>

void inputStrings(char str1[], char str2[]);
int compareStrings(char str1[], char str2[]);
void output(int result);

int main() {
    char str1[100], str2[100];
    int result;

    inputStrings(str1, str2);
    
    // CRITICAL FIX: You must assign the returned value to 'result'
    result = compareStrings(str1, str2);
    
    output(result);

    return 0;
}

void inputStrings(char str1[], char str2[]) {
    printf("Enter first string:\n");
    fgets(str1, 100, stdin);
    str1[strcspn(str1,"\n")] = 0; // Removes trailing newline for clean comparison

    printf("Enter second string:\n");
    fgets(str2, 100, stdin);
    str2[strcspn(str2,"\n")] = 0; // Removes trailing newline for clean comparison
}

int compareStrings(char str1[], char str2[]) {
    int val = strcmp(str1, str2);
    
    // Standardizing output: 0 if equal, 1 if str1 > str2, -1 if str1 < str2
    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}

void output(int result) {
    if (result == 0) 
        printf("Strings are equal (Result: %d)\n", result);
    else if (result > 0)
        printf("First string is greater (Result: %d)\n", result);
    else
        printf("Second string is greater (Result: %d)\n", result);
}