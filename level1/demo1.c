#include <stdio.h>

/* Function Prototypes */
void input(int n, float arr[n]);
int find_max_index(int n, float arr[n]);
void output(float arr[], int max_index);

int main() {
    int n;
    printf("Enter the number of elements: \n");
    
    // Check if scanf successfully read an integer
    if (scanf("%d", &n) != 1) {
        printf("Invalid input: Please enter a number.\n");
        return 0;
    }
    
    // Handle edge case: 0 or negative elements
    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 0;
    }

    float arr[n];
    printf("Enter the array elements:\n");
    input(n, arr);
    
    int max_idx = find_max_index(n, arr);
    output(arr, max_idx);
    
    return 0;
}

void input(int n, float arr[n]) {
    for (int i = 0; i < n; i++) {
        // Checking return value here too ensures we don't 
        // process junk if a float input is invalid
        if (scanf("%f", &arr[i]) != 1) {
            printf("Error reading element %d.\n", i);
            return;
        }
    }
}

int find_max_index(int n, float arr[n]) {
    int max_i = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_i]) {
            max_i = i;
        }
    }
    return max_i;
}

void output(float arr[], int max_index) {
    printf("Maximum element is %.2f\n", arr[max_index]);
    printf("Index of maximum element is %d\n", max_index);
}