#include <stdio.h>

typedef struct { 
     char name[50]; 
     float length; 
     float width; 
     float area; 
} Rectangle; 

Rectangle input(); 
float calculate_area(Rectangle rect); 
void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3);

int main() {
    Rectangle r1, r2, r3;
    r1 = input(); r1.area = calculate_area(r1);
    r2 = input(); r2.area = calculate_area(r2);
    r3 = input(); r3.area = calculate_area(r3);

    printf("Area of %s:%.2f\n", r1.name, r1.area);
    printf("Area of %s:%.2f\n", r2.name, r2.area);
    printf("Area of %s:%.2f\n", r3.name, r3.area);
    
    compare_areas(r1, r2, r3);
    return 0;
}

Rectangle input() {
    Rectangle rect;
    printf("Enter details:\n"); 
    scanf("%s %f %f", rect.name, &rect.length, &rect.width);
    return rect;
}

float calculate_area(Rectangle rect) {
    return rect.length * rect.width;
}

void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3) {
    if (r1.area > r2.area && r1.area > r3.area) {
        printf("%s has the largest area.\n", r1.name);
    } else if (r2.area > r1.area && r2.area > r3.area) {
        printf("%s has the largest area.\n", r2.name);
    } else if (r3.area > r1.area && r3.area > r2.area) {
        printf("%s has the largest area.\n", r3.name);
    } else {
        printf("Two or more rectangles have equal largest area\n");
    }
}