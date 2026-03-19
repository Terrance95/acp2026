#include <stdio.h>
#include <stdlib.h>

int* create_array(int n);
void initialize_array(int *arr, int n);
void print_array(int *arr, int n);
void delete_array(int **arr);

int main() {
    int n; 
    int *arr = NULL; 

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    if(n <= 0) {
        printf("Invalid array size!\n");
        return 0;
    }

    arr = create_array(n);

    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    printf("Enter %d integers:\n", n);
    initialize_array(arr, n);

    printf("Array elements are:\n");
    print_array(arr, n);

    delete_array(&arr);

    if(arr == NULL)
        printf("\nMemory successfully freed and pointer set to NULL.\n");

    return 0;
}

int* create_array(int n) {
    int *temp = (int*)malloc(n * sizeof(int));
    return temp;
}

void initialize_array(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void print_array(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_array(int **arr) {
    if (*arr != NULL) {
        free(*arr);    
        *arr = NULL;   
    }
}