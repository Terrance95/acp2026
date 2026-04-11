#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float length;
    float width;
    float area;
} Rectangle;

void input(int n, Rectangle *rects);
void calculate_area(int n, Rectangle *rects);
int findLargestArea(int n, Rectangle *rects);
void output(int n, int largestIndex, Rectangle *rects);

int main() {
    int n;

    printf("enter the num,ber of rectangles: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
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
    printf("enter length and width\n");
    for (int i = 0; i < n; i++) {
        printf("rectangle %d:",i=1);
        if (scanf("%f %f", &rects[i].length, &rects[i].width) != 2) {
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
        printf("Rectangle %d: %.2f x %.2f = Area: %.2f\n", 
                i + 1, rects[i].length, rects[i].width, rects[i].area);
    }

    printf("\n--- Rectangle with Largest Area ---\n");
    printf("Rectangle %d has the largest area: %.2f\n", 
            largestIndex + 1, rects[largestIndex].area);
}