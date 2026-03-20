#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define FILENAME "students.dat"

typedef struct {
    int rollNo;
    char name[50];
    float cgpa;
} Student;

void inputStudents(Student students[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Student %d (RollNo Name CGPA): ", i + 1);
        scanf("%d %s %f", &students[i].rollNo, students[i].name, &students[i].cgpa);
    }
}

void writeToBinaryFile(Student students[], int n, const char *filename) {
    FILE *fp = fopen(filename, "wb"); // 'wb' means Write Binary
    if (fp == NULL) return;
    fwrite(students, sizeof(Student), n, fp);
    fclose(fp);
}

int readFromBinaryFile(Student students[], const char *filename) {
    FILE *fp = fopen(filename, "rb"); // 'rb' means Read Binary
    if (fp == NULL) return 0;
    int n = 0;
    while(fread(&students[n], sizeof(Student), 1, fp) == 1) {
        n++;
    }
    fclose(fp);
    return n;
}

void printStudents(Student students[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Roll: %d, Name: %s, CGPA: %.2f\n", students[i].rollNo, students[i].name, students[i].cgpa);
    }
}

int main() {
    Student input[MAX], output[MAX];
    int n, count;

    printf("Enter number of students: ");
    scanf("%d", &n);

    inputStudents(input, n);
    writeToBinaryFile(input, n, FILENAME);
    count = readFromBinaryFile(output, FILENAME);
    printStudents(output, count);

    return 0;
}