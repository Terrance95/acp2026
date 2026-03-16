#include <stdio.h>

/* Function Prototypes */
void input(int n, float arr[n]);
int find_max_index(int n, float arr[n]);
void output(float arr[], int max_index);

int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    float arr[n];
    
    // Using the input function
    input(n, arr);

    // Finding the max index
    int max_idx = find_max_index(n, arr);

    // Displaying the results
    output(arr, max_idx);

    return 0;
}

// Reads n float values into the array
void input(int n, float arr[n]) {
    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]); // Corrected to %f for floats
    }
}

// Finds and returns the index of the maximum element
int find_max_index(int n, float arr[n]) {
    int max_i = 0; 
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_i]) {
            max_i = i;
        }
    }
    return max_i;
}

// Prints the value and the index
void output(float arr[], int max_index) {
    printf("Maximum element is %.2f\n", arr[max_index]);
    printf("Index of maximum element is %d\n", max_index);
}