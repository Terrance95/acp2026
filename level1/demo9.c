#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    float marks;
};

/* Function Prototypes */
int readStudents(struct Student s[]);
void writeToFile(struct Student s[], int n);
int readFromFile(struct Student s[]);
void displayStudents(struct Student s[], int n);

int main() {

    struct Student students[MAX_STUDENTS];
    struct Student fileStudents[MAX_STUDENTS];

    int n, m;

    /* Read student details */
    n = readStudents(students);

    /* Write data to file */
    writeToFile(students, n);

    /* Read data from file */
    m = readFromFile(fileStudents);

    /* Display student records */
    displayStudents(fileStudents, m);

    return 0;
}

/* Read student details from user */
int readStudents(struct Student s[]) {

    int n;

    // TODO: Implement reading of student records

    return n;
}

/* Write student records to file */
void writeToFile(struct Student s[], int n) {

    // TODO: Implement file writing using fprintf()

}

/* Read student records from file */
int readFromFile(struct Student s[]) {

    int count = 0;

    // TODO: Implement file reading using fscanf()

    return count;
}

/* Display student records */
void displayStudents(struct Student s[], int n) {

    // TODO: Implement display logic

}