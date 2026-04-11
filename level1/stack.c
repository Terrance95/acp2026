#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void display() {
    if (top == -1) {
        printf("\n[ Stack is currently EMPTY ]\n");
        return;
    }
    printf("\n--- Current Stack State ---\n");
    for (int i = top; i >= 0; i--) {
        if (i == top) 
            printf("| %d | <-- TOP\n", stack[i]);
        else 
            printf("| %d |\n", stack[i]);
    }
    printf("---------------------------\n");
}

void push(int value) {
    if (top == MAX - 1) {
        printf("\nERROR: Stack Overflow! Cannot add %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("\nACTION: Pushed %d", value);
        display();
    }
}

void pop() {
    if (top == -1) {
        printf("\nERROR: Stack Underflow! Nothing to remove.\n");
    } else {
        int val = stack[top];
        top--; // We just move the pointer down
        printf("\nACTION: Popped %d", val);
        display();
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    push(40);
    
    return 0;
}