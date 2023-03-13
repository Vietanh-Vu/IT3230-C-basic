#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void init() {
    top = -1;
}

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == MAX_SIZE - 1;
}

int get_top() {
    if (top == -1) {
        printf("Error: Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Error: Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}
