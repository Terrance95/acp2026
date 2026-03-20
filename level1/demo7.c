#include <stdio.h>
#include<string.h>

// Function Prototypes
void inputStrings(char str1[], char str2[]);
int compareStrings(char str1[], char str2[]);
void output(int result);

int main() {

    char str1[100], str2[100];
    int result;

   // Call the function to input the two strings
   inputStrings(str1,str2);
   // Call the function to compare the two strings and store the returned value
   compareStrings(str1,str2);
   // Call the function to display the result
   output(result);

    return 0;
}

void inputStrings(char str1[], char str2[]) {
    printf("Enter first string:\n");
    fgets(str1,100,stdin);
    printf("Enter second string:\n");
    fgets(str2,100,stdin);

    // Write code to read both strings
}

int compareStrings(char str1[], char str2[]) {
    // Write code to compare two strings and return 0, 1, or -1
    int result=(strcmp(str1,str2));
    return result;
}

void output(int result) {
    printf("%d\n", result);
    // Write code to display the result
}