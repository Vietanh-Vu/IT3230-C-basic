#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int num[1000000];
int head = 0;
int tail = -1;

int isEmpty() {
    if (tail < head) return 1;
    return 0;
}

void push(int pushNum) {
    tail = tail + 1;
    num[tail] = pushNum;
}

int pop() {
    if (isEmpty()) {
        return -1;
    }
    int popNum = num[head];
    head++;
    return popNum;
}

int main() {
    char choice[256];
    // int result[1000000];
    // int i=0;
    do {
        scanf("%s", &choice);
        if (strcmp(choice, "PUSH") == 0) {
            int pushNum;
            scanf("%d", &pushNum);
            push(pushNum);
        }
        if (strcmp(choice, "POP") == 0) {
            int tmp = pop();
            if (tmp != -1) printf("%d\n", tmp);
            else printf("NULL\n");
        }
    } while (strcmp(choice, "#") != 0);
    return 0;
}
///////////////////////////////////////////////////////////////////////

#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int head = 0, tail = -1;

// function to check if the queue is empty
int isEmpty() {
    return (tail == -1);
}

// function to check if the queue is full
int isFull() {
    return (tail+1)%MAX_SIZE == head;
}

// function to add an element to the queue
void enqueue(int x) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    tail = (tail+1)%MAX_SIZE;
    queue[tail] = x;
}

// function to remove an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = queue[head];
    head = (head+1)%MAX_SIZE;
    if(head == (tail+1)%MAX_SIZE) {
        tail = -1;
        head = 0;
    }
    return x;
}

// function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    if(tail >= head) {
        for(int i = head; i <= tail; i++)
            printf("%d ", queue[i]);
    }else {
        for(int i = head; i < MAX_SIZE; i++)
            printf("%d ", queue[i]);
        for(int i = 0; i <= tail; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}
