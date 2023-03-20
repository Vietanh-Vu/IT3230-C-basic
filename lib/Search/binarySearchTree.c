#include <stdio.h>
#include <stdlib.h>

// Define a node in the binary search tree with data, left child, and right child
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// free tree
void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Create a new node with given data
Node *newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a node with given data into the binary search tree
Node *insert(Node *node, int data) {
    // If the tree is empty, create a new node
    if (node == NULL) {
        return newNode(data);
    }
    // If data is less than the current node, insert it to the left subtree
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    // If data is greater than the current node, insert it to the right subtree
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    // If data is equal to the current node, do not insert
    return node;
}

// Find the node with the minimum value in a binary search tree
Node *minValueNode(Node *node) {
    Node *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete a node with given data from the binary search tree
Node *deleteNode(Node *root, int data) {
    // If the tree is empty, return root
    if (root == NULL) {
        return root;
    }
    // If data is less than the current node, delete it from the left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If data is greater than the current node, delete it from the right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // If data is equal to the current node, delete it
    else {
        // If the node has no left child, replace it with its right child
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        // If the node has no right child, replace it with its left child
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // If the node has both left and right child, replace it with the minimum value node in the right subtree
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search for a node with given data in the binary search tree
Node *search(Node *root, int data) {
    // If the tree is empty or the node is found, return root
    if (root == NULL || root->data == data) {
        return root;
    }
    // If data is less than the current node, search it in the left subtree
    if (data < root->data) {
        return search(root->left, data);
    }
    // If data is greater than the current node, search it in the right subtree
    return search(root->right, data);
}


void inorderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}


int main() {
    // Create a binary search tree
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Search for a node with data = 60
    struct node *result = search(root, 60);
    if (result != NULL) {
        printf("Node with data 60 is found\n");
    }
    else {
        printf("Node with data 60 is not found\n");
    }

    // Delete a node with data = 20
    root = deleteNode(root, 20);

    // Search for a node with data = 20
    result = search(root, 20);
    if (result != NULL) {
        printf("Node with data 20 is found\n");
    }
    else {
        printf("Node with data 20 is not found\n");
    }

    return 0;
}
