#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void free_linked_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insert_at_last(Node** head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void remove_first_with_value(Node** head, int value) {
    Node* current = *head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current != NULL) {
        *head = current->next;
        free(current);
    }
}

void remove_all_with_value(Node** head, int value) {
    Node* current = *head;
    Node* prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev != NULL) {
                prev->next = current->next;
            }
            if (current == *head) {
                *head = current->next;
            }
            Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int count(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void reverse(Node** head) {
    Node* current = *head;
    Node* prev = NULL;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

Node* find(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void addafter(Node* head, int u, int v) {
    Node* current = head;
    while (current != NULL && current->data != v) {
        current = current->next;
    }
    if (current != NULL) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = u;
        new_node->next = current->next;
        current->next = new_node;
    }
}

void addbefore(Node* head, int u, int v) {
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL && current->data != v) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = u;
        new_node->next = current;
        if (prev != NULL) {
            prev->next = new_node;
        }
    }
}



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
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
        *head = new_node;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void remove_first_with_value(struct Node** head, int value) {
    struct Node* current = *head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current != NULL) {
        *head = current->next;
        free(current);
    }
}

void remove_all_with_value(struct Node** head, int value) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev != NULL) {
                prev->next = current->next;
            }
            if (current == *head) {
                *head = current->next;
            }
            struct Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
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
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
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
        new_node->next = current->next;
        current->next = new_node;
    }
}

void addbefore(struct Node* head, int u, int v) {
    struct Node* current = head;
    struct Node* prev = NULL;
    while (current != NULL && current->key != v) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->key = u;
        new_node->next = current;
        if (prev != NULL) {
            prev->next = new_node;
        }
    }
}






