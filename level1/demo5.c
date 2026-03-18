#include <stdio.h>

void read_array(int n, int arr[]);
void print_array(int n, int arr[]);
void swap_array(int n, int a[n], int b[n]);

int main() {
    int n;
    printf("enter the number of elements:");
    scanf("%d",&n);
    if(n<=0) {
        printf("Invalid input");
        return 0;
    }
    int a[n],b[n];
    // Read first array
    read_array(n, a);

    // Read second array
    read_array(n, b);

    // Swap arrays
    swap_array(n, a, b);

    // Print swapped arrays
    printf("arrays aafter swappping\n");
    print_array(n, a);
    printf("\n");
    print_array(n, b);

    return 0;
}

void read_array(int n, int arr[]) {
    // Write code here to read n elements into the array
    for(int i=0;i<n;i++){
        printf("enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
}

void print_array(int n, int arr[]) {
    // Write code here to print array elements separated by space
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}

void swap_array(int n, int a[n], int b[n]) {
    // Write code here to swap elements of arrays a and b
    int temp[100];
    for(int i=0;i<n;i++){
        temp[i]=a[i];
        a[i]=b[i];
        b[i]=temp[i];
    }

}