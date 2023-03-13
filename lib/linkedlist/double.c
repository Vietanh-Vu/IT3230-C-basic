#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insert_at_last(struct Node** head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void remove_first_with_value(struct Node** head, int value) {
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            if (current == *head) {
                *head = current->next;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

void remove_all_with_value(struct Node** head, int value) {
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            if (current == *head) {
                *head = current->next;
            }
            struct Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

int count(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void reverse(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

struct Node* find(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void addafter(struct Node* head, int u, int v) {
    struct Node* current = head;
    while (current != NULL && current->key != v) {
        current = current->next;
    }
    if (current != NULL) {
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->key = u;
        new_node->prev = current;
        new_node->next = current->next;
        if (current->next != NULL) {
            current->next->prev = new_node;
        }
        current->next = new_node;
    }
}

void addbefore(struct Node* head, int u, int v) {
    struct Node* current = head;
    while (current != NULL && current->key != v) {
        current = current->next;
    }
    if (current != NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->key = u;
        new_node->next = current;
        new_node->prev = current->prev;
    if (current->prev != NULL) {
        current->prev->next = new_node;
    }
    current->prev = new_node;
}
