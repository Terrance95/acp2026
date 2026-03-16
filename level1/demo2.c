#include <stdio.h>

typedef struct { 
     char name[50]; 
     float length; 
     float width; 
     float area; 
} Rectangle; 

/* Function prototypes */
Rectangle input(); 
float calculate_area(Rectangle rect); 
void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3);

int main() {
    Rectangle r1,r2,r3;
    printf("Enter details for Rectangle 1:\n");
    /* Input and calculate area for first rectangle */
    r1=input();
    r1.area=calculate_area(r1);
    printf("Enter details for Rectangle 2:\n");
    /* Input and calculate area for second rectangle */
    r2=input();
    r2.area=calculate_area(r2);
    printf("Enter details for Rectangle 3:\n");
    /* Input and calculate area for third rectangle */
    r3=input();
    r3.area=calculate_area(r3);
    /* Display areas of all rectangles */
    printf("Area of %s:%.2f\n",r1.name,r1.area);
    printf("Area of %s:%.2f\n",r2.name,r2.area);
    printf("Area of %s:%.2f\n",r3.name,r3.area);
    /* Determine and display the largest area */
    compare_areas(r1,r2,r3);
    return 0;
}

Rectangle input() {
    Rectangle rect;
    printf("Enter name: Enter length: Enter width: \n");
    scanf("%s%f%f",rect.name,&rect.length,&rect.width);
    /* Read rectangle details */
    return rect;
}

float calculate_area(Rectangle rect) {
    /* Return area calculation */
    return rect.length*rect.width;
}

void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3) {
    /* Print largest rectangle or tie message */
    if(r1.area>r2.area && r1.area>r3.area){
        printf("%s has the largest area.\n",r1.name);
    }else if(r2.area>r1.area && r2.area>r3.area){
        printf("%s has the largest area.\n",r2.name);
    }else if(r3.area>r1.area && r3.area>r2.area){
        printf("%s has the largest area.\n",r3.name);
    }else{
        printf("Two or more rectangles have equal largest area");
    }
}