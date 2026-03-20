#include <stdio.h>
#include <string.h>

void input(char *str);
void concatenate_strings(char *str1, char *str2);
void display(char *str);

int main() {
    char str1[200], str2[100];

    input(str1);
    input(str2);

    concatenate_strings(str1, str2);

    display(str1);

    return 0;
}

void input(char *str) {
    printf("Enter string:\n");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
}

void concatenate_strings(char *str1, char *str2) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        i++;
    }
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

void display(char *str) {
    printf("Concatenated string: %s\n", str);
}