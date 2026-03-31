#include <stdio.h>
#include <stdlib.h>

int* allocate_scores(int n);
void read_scores(int *arr, int n);
int calculate_total(int *arr, int n);
void display_scores(int *arr, int n);
void delete_scores(int **arr);

int main() {
    int n, total;

    printf("Enter number of players:\n");
    // Optimized: Combined scanf check with the n <= 0 check
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("invalid n value\n");
        return 1; // Optimized: Return 1 to indicate an error state to the OS
    }

    // Optimized: Declaration and initialization in one step
    int *scores = allocate_scores(n);
    if (scores == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    read_scores(scores, n);
    display_scores(scores, n);

    total = calculate_total(scores, n);
    printf("Total Score: %d\n", total);

    delete_scores(&scores);

    return 0;
}

int* allocate_scores(int n) {
    // Optimized: No need for a temporary variable, just return the malloc result directly
    return (int*)malloc(n * sizeof(int));
}

void read_scores(int *arr, int n) {
    printf("Enter scores:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void display_scores(int *arr, int n) {
    printf("scores:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}

int calculate_total(int *arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

void delete_scores(int **arr) {
    // Optimized: Added a safety check to ensure the pointer itself isn't NULL before freeing
    if (arr != NULL && *arr != NULL) {
        free(*arr);
        *arr = NULL;
    }
}