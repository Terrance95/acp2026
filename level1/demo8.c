#include <stdio.h>

// Function Prototypes
void input(char *str);
void concatenate_strings(char *str1, char *str2);
void display(char *str);

int main() {

    char str1[100], str2[100];

    input(str1);
    input(str2);

    concatenate_strings(str1, str2);

    display(str1);

    return 0;
}

void input(char *str) {
    printf("Enter string:\n");
    fgets(str,100,stdin);
    // Write code to read the string
}

void concatenate_strings(char *str1, char *str2) {
    // Write code to concatenate str2 to str1 using while/do while
    int i=0,j=0;
    while(str2[i]!='\0'){
        i++;
    }
    while(str1[j]!='\0'){
        str2[i]=str1[j];
        i++;
        j++;
    }
}

void display(char *str) {
    printf("Concatenated string:%s\n",str);
    // Write code to display the string
}