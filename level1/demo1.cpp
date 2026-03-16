#include <stdio.h>

/* Function Prototypes */
void input(int n, float arr[n]);
int find_max_index(int n, float arr[n]);
void output(float arr[], int max_index);

int main() {
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    
    if (n <= 0){
        printf("Invalid number of elements.");
        return 0;
    }
    float arr[n];
    printf("Enter the array elements:\n");
    input(n,arr);
    int max_idx=find_max_index(n,arr);
    output(arr,max_idx);
    
    return 0;
}

void input(int n, float arr[n]) {
    // Write code here to read n float values into the array
    for(int i=0;i<n;i++){
        printf("Element %d:",i);
        scanf("%f",&arr[i]);
    }
}

int find_max_index(int n, float arr[n]) {
    // Write code here to find and return the index of the maximum element
   int max_i=0;
   for(int i=1;i<n;i++){
       if(arr[i]>arr[max_i]){
           max_i=i;
       }
   }
   return max_i;
}

void output(float arr[], int max_index) {
    printf("Maximum element is %.2f\n",arr[max_index] );
    printf("Index of maximum element is %d\n",max_index );
}