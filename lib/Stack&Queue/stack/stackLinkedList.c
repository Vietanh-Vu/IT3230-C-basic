#include <stdio.h>
#include <stdlib.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Global variable for top of stack
struct Node* top = NULL;

// Initialize stack
void init() {
    top = NULL;
}

// Check if stack is empty
int is_empty() {
    if (top == NULL) {
        return 1;
    }
    return 0;
}

// Check if stack is full (not applicable for linked list implementation)
int is_full() {
    return 0;
}

// Get top element of stack
int get_top() {
    if (!is_empty()) {
        return top->data;
    }
    return -1;
}

// Push element onto stack
void push(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

// Pop element off of stack
int pop() {
    if (!is_empty()) {
        int value = top->data;
        struct Node* temp = top;
        top = top->next;
        free(temp);
        return value;
    }
    return -1;
}
