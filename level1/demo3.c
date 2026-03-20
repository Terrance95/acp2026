#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float length;
    float width;
    float area;
} Rectangle;

// Function Prototypes - Using pointers for better array handling
void input(int n, Rectangle *rects);
void calculate_area(int n, Rectangle *rects);
int findLargestArea(int n, Rectangle *rects);
void output(int n, int largestIndex, Rectangle *rects);

int main() {
    int n;

    // Prompt for n
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    if(n<=0){
        printf("invalid input for n");
        return 1;
    }

    Rectangle *rects = (Rectangle *)malloc(n * sizeof(Rectangle));
    if (rects == NULL) return 1;

    input(n, rects);
    calculate_area(n, rects);
    int largestIndex = findLargestArea(n, rects);
    output(n, largestIndex, rects);

    free(rects);
    return 0;
}

void input(int n, Rectangle *rects) {
    for (int i = 0; i < n; i++) {
        // Simplified scanf to handle both space-separated and newline-separated input
        if (scanf("%f %f", &rects[i].length, &rects[i].width) != 2) {
            // Error handling for bad float inputs
        }
    }
}

void calculate_area(int n, Rectangle *rects) {
    for (int i = 0; i < n; i++) {
        rects[i].area = rects[i].length * rects[i].width;
    }
}

int findLargestArea(int n, Rectangle *rects) {
    int largestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (rects[i].area > rects[largestIndex].area) {
            largestIndex = i;
        }
    }
    return largestIndex;
}

void output(int n, int largestIndex, Rectangle *rects) {
    printf("\n--- Areas of all rectangles ---\n");
    for (int i = 0; i < n; i++) {
        // MATCH THIS EXACTLY TO YOUR BATS FILE
        printf("Rectangle %d: %.2f x %.2f = Area: %.2f\n", 
                i + 1, rects[i].length, rects[i].width, rects[i].area);
    }

    printf("\n--- Rectangle with Largest Area ---\n");
    printf("Rectangle %d has the largest area: %.2f\n", 
            largestIndex + 1, rects[largestIndex].area);
}