#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    float marks;
};

int readStudents(struct Student s[]);
void writeToFile(struct Student s[], int n);
int readFromFile(struct Student s[]);
void displayStudents(struct Student s[], int n);

int main() {
    struct Student students[MAX_STUDENTS];
    struct Student fileStudents[MAX_STUDENTS];
    int n, m;

    n = readStudents(students);
    writeToFile(students, n);
    m = readFromFile(fileStudents);
    displayStudents(fileStudents, m);

    return 0;
}

int readStudents(struct Student s[]) {
    int n;
    printf("Enter no of students:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter ID, Name, Marks for student %d: ", i + 1);
        scanf("%d %s %f", &s[i].id, s[i].name, &s[i].marks);
    }
    return n;
}

void writeToFile(struct Student s[], int n) {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) return;
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %f\n", s[i].id, s[i].name, s[i].marks);
    }
    fclose(fp);
}

int readFromFile(struct Student s[]) {
    int count = 0;
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) return 0;
    while(fscanf(fp, "%d %s %f", &s[count].id, s[count].name, &s[count].marks) != EOF) {
        count++;
    }
    fclose(fp);
    return count;
}

void displayStudents(struct Student s[], int n) {
    printf("\nStudent Records from File:\n");
    for(int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", s[i].id, s[i].name, s[i].marks);
    }
}