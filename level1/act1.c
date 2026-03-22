#include <stdio.h>

void inputTemperatures(int n, float temps[]);
float findHighest(int n, float temps[]);
float findLowest(int n, float temps[]);
void output(float max, float min);

int main() {
    int n;
    float max, min;

    printf("enter no of temperatures u want to enter:");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("invalid value for n entered\n");
        return 1;
    }
    if(n<=0){
        printf("invalid n");
        return 0;
    }

    float temps[n];

    inputTemperatures(n, temps);

    max = findHighest(n, temps);
    min = findLowest(n, temps); // Fixed: previously calling findHighest

    output(max, min);

    return 0;
}

void inputTemperatures(int n, float temps[]) {
    printf("Enter temperatures:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &temps[i]);
    }
}

float findHighest(int n, float temps[]) {
    float max = temps[0]; // Start with the first element
    for (int i = 1; i < n; i++) {
        if (temps[i] > max) {
            max = temps[i];
        }
    }
    return max;
}

float findLowest(int n, float temps[]) {
    float min = temps[0]; // Start with the first element
    for (int i = 1; i < n; i++) {
        if (temps[i] < min) {
            min = temps[i];
        }
    }
    return min;
}

void output(float max, float min) {
    printf("Highest temperature: %.2f\n", max);
    printf("Lowest temperature: %.2f\n", min);
}