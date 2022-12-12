#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    char name[256];
    int depth;
    struct Node *leftMostChild; // pointer to the left-most child
    struct Node *rightSibling;  // pointer to the right sibling
} Node;

Node *root;
int depth = 0, count = 0;

void initTree()
{
    root = NULL;
}

int emptyTree()
{
    return root == NULL;
}

Node *makeNode(char name[256], int depth)
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->name, name);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    p->depth = depth;
    return p;
}

Node *findNode(Node *current, char name[256])
{
    if (current == NULL)
        return NULL;
    if (!strcmp(current->name, name))
        return current;
    Node *child = current->leftMostChild;
    while (child != NULL)
    {
        Node *res = findNode(child, name);
        if (res != NULL)
            return res;
        child = child->rightSibling;
    }
    return NULL;
}

void pLoad(char *fileName)
{
    initTree();
    FILE *f = fopen(fileName, "r");
    char parentNode[256];
    do
    {
        Node *parent;
        fscanf(f, "%s", parentNode);
        if (!strcmp(parentNode, "$$"))
            break;
        if (emptyTree())
        {
            parent = makeNode(parentNode, 0);
            root = parent;
            count++;
        }
        else
        {
            parent = findNode(root, parentNode);
        }
        char firstChildNode[256];
        fscanf(f, "%s", firstChildNode);
        Node *firstChild = makeNode(firstChildNode, parent->depth + 1);
        if (firstChild->depth > depth)
            depth = firstChild->depth;
        parent->leftMostChild = firstChild;
        count++;
        do
        {
            char childNode[256];
            fscanf(f, "%s", childNode);
            if (!strcmp(childNode, "$"))
                break;
            Node *child = makeNode(childNode, firstChild->depth);
            firstChild->rightSibling = child;
            count++;
            firstChild = child;
        } while (1);
    } while (1);
    fclose(f);
}

int printChildren(char parrentName[256])
{
    Node *parent = findNode(root, parrentName);
    if (parent == NULL)
        return 0;
    Node *child = parent->leftMostChild;
    while (child != NULL)
    {
        printf("%s ", child->name);
        child = child->rightSibling;
    }
    printf("\n");
    return 1;
}

void pPrintChildren()
{
    char name[256];
    do
    {
        printf("Nhap ten node can in danh sach con: ");
        scanf("%s", name);
    } while (!printChildren(name));
}

int addChild(char name[256], char childName[256])
{
    Node *current = findNode(root, name);
    if (current == NULL)
        return 0;
    Node *node;
    if (current->leftMostChild == NULL)
    {
        node = makeNode(childName, current->depth + 1);
        current->leftMostChild = node;
    }
    else
    {
        node = makeNode(childName, current->depth + 1);
        Node *child = current->leftMostChild;
        while (child->rightSibling != NULL)
        {
            child = child->rightSibling;
        }
        child->rightSibling = node;
    }
    if (node->depth > depth)
        depth = node->depth;
    count++;
    return 1;
}

void pAddChild()
{
    char parentName[256];
    char childName[256];
    do
    {
        printf("Nhap ten node can them con: ");
        scanf("%s", parentName);
        printf("Nhap ten con: ");
        scanf("%s", childName);
    } while (!addChild(parentName, childName));
}

void pPrintHeight()
{
    char name[256];
    Node *node;
    do
    {
        printf("Nhap ten node can in chieu cao: ");
        scanf("%s", name);
        node = findNode(root, name);
    } while (node == NULL);
    printf("Chieu cao cua node %s la: %d\n", name, depth - node->depth);
}

void pPrintCount()
{
    printf("Cay co %d node\n", count);
}

// void fPrintChildren(FILE *f, Node *parent)
// {
//     Node *child = parent->leftMostChild;
//     if (child != NULL)
//     {
//         fprintf(f, "%s ", parent->name);
//         do
//         {
//             fprintf(f, "%s ", child->name);
//             child = child->rightSibling;
//             if (child == NULL)
//             {
//                 fprintf(f, "$\n");
//                 break;
//             }
//         } while (1);
//     }
// }

// void pStore(char *fileName)
// {
//     FILE *f = fopen(fileName, "w+");
//     fPrintChildren(f, root);
//     fprintf(f, "$$\n");
//     fclose(f);
// }

int main()
{
    int choose;
    do
    {
        printf("**************************************************\n");
        printf("1. Doc du lieu tu file input.txt\n");
        printf("2. In danh sach con cua mot node\n");
        printf("3. Them mot con vao cuoi danh sach mot node\n");
        printf("4. In danh sach tat ca thanh vien\n");
        printf("5. Tinh chieu cao cua cay\n");
        printf("6. Dem so thanh vien gia dinh\n");
        printf("7. Luu tru vao file\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            pLoad("input.txt");
            break;
        case 2:
            pPrintChildren();
            break;
        case 3:
            pAddChild();
            break;
        case 4:
            break;
        case 5:
            pPrintHeight();
            break;
        case 6:
            pPrintCount();
            break;
        case 7:
            break;
        case 8:
            return 0;
        }
    } while (1);
}