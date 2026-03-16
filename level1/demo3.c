#include <stdio.h>

typedef struct {
    float length;
    float width;
    float area;
} Rectangle;

// Function Prototypes
void input(int n, Rectangle rects[n]);
void calculate_area(int n, Rectangle rects[n]);
int findLargestArea(int n, Rectangle rects[n]);
void output(int n, int largestIndex, Rectangle rects[n]);

int main() {
    int n;

    printf("Enter number of rectangles: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    Rectangle rects[n];

    input(n, rects);
    calculate_area(n, rects);
    int largestIndex = findLargestArea(n, rects);
    output(n, largestIndex, rects);

    return 0;
}

void input(int n, Rectangle rects[n]) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter dimensions for rectangle %d:\n", i + 1);
        printf("Length: ");
        scanf("%f", &rects[i].length);
        printf("Width: ");
        scanf("%f", &rects[i].width);
    }
}

void calculate_area(int n, Rectangle rects[n]) {
    for (int i = 0; i < n; i++) {
        rects[i].area = rects[i].length * rects[i].width;
    }
}

int findLargestArea(int n, Rectangle rects[n]) {
    int largestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (rects[i].area > rects[largestIndex].area) {
            largestIndex = i;
        }
    }
    return largestIndex;
}

void output(int n, int largestIndex, Rectangle rects[n]) {
    printf("\n--- Areas of all rectangles ---\n");
    for (int i = 0; i < n; i++) {
        printf("Rectangle %d: %.2f x %.2f = Area: %.2f\n", 
                i + 1, rects[i].length, rects[i].width, rects[i].area);
    }

    printf("\n--- Rectangle with Largest Area ---\n");
    printf("Rectangle %d has the largest area: %.2f\n", 
            largestIndex + 1, rects[largestIndex].area);
}