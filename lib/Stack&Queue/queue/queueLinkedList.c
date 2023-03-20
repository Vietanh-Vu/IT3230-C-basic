#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head, *tail;

// function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// function to initialize the queue
void init() {
    head = NULL;
    tail = NULL;
}

// function to check if the queue is empty
int isEmpty() {
    return (head == NULL);
}

// function to add an element to the queue
void enqueue(int data) {
    struct Node* temp = newNode(data);
    if (tail == NULL) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

// function to remove an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = head;
    int data = temp->data;
    head = head->next;
    if (head == NULL)
        tail = NULL;
    free(temp);
    return data;
}

// function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
