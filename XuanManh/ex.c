#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_L 256
#define MAX 100000
#define M 100

// Tao va xoa cay

typedef struct Node
{
    char name[256];
    char email[256];
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

void freeTree(Node *r)
{
    if (r == NULL)
        return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

// hash function

int h(char *s) 
{ 
    int rs = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        rs = (rs * 255 + s[i]) % M;
    return rs;
}

Node *root[M];

void init()
{
    for (int i = 0; i < M; i++)
    root[i] = NULL;
}

// Tao node moi

Node *makeNewNode(char *name, char *email)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

// Them node vao cuoi cay

Node *insert(Node *node, char *name, char *email)
{
    if (node == NULL)
        return makeNewNode(name, email);
    int n = strcmp(name, node->name);
    if (n < 0)
        node->leftChild = insert(node->leftChild, name, email);
    else
        node->rightChild = insert(node->rightChild, name, email);
    return node;
}

void ProcessInsert()
{
    printf("Nhập tên sinh viên cần thêm: ");
    char name[MAX_L];
    scanf("%s", name);
    printf("Nhập email sinh viên cần thêm: ");
    char email[MAX_L];
    scanf("%s", email);
    root[h(name)] = insert(root[h(name)], name, email);
}

// Nhap du lieu tu file

void load(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        printf("Load data -> file not found\n");
    while (!feof(f))
    {
        char name[MAX_L], email[MAX_L];
        fscanf(f, "%s%s", name, email);
        root[h(name)] = insert(root[h(name)], name, email);
    }
    fclose(f);
}

void ProcessLoad()
{
    printf("Nhập tên file cần đọc dữ liệu: ");
    char fileName[MAX_L];
    scanf("%s", fileName);
    load(fileName);
}

// Tim nut phai nhat ben trai

Node *maxValueNode(Node *node)
{
    Node *current = node;
    while (current->rightChild != NULL)
        current = current->rightChild;
    return current;
}

// Xoa node

Node *removeNode(Node *node, char *name)
{
    // Node rong
    if (node == NULL)
        return NULL;

    // Node ton tai
    int n = strcmp(name, node->name);
    if (n < 0) // De quy con trai
        node->leftChild = removeNode(node->leftChild, name);
    else if (n > 0) // De quy con phai
        node->rightChild = removeNode(node->rightChild, name);
    else
    {                                                            // Tim duoc node can xoa
        if (node->leftChild == NULL && node->rightChild == NULL) // Node la nut la
        {
            free(node);
            node = NULL;
        }
        else if (node->leftChild != NULL && node->rightChild != NULL) // Node co 2 con
        {
            Node *tmp = maxValueNode(node->leftChild); // tmp la con phai nhat tren cay trai cua node
            // copy du lieu
            strcpy(node->name, tmp->name);
            strcpy(node->email, tmp->email);
            // Xoa tmp
            node->leftChild = removeNode(node->leftChild, tmp->name);
        }
        else // Node co 1 con
        {
            Node *tmp = node;
            if (node->leftChild == NULL) // Node khong co con trai
            {
                node = node->rightChild;
            }
            else // Node khong co con phai
            {
                node = node->leftChild;
            }
            free(tmp);
        }
    }
    return node; // update node moi
}

void ProcessRemove()
{
    printf("Nhập tên người cần xóa: ");
    char name[MAX_L];
    scanf("%s", name);
    root[h(name)] = removeNode(root[h(name)], name);
}

// Tim node

Node *find(Node *node, char *name)
{
    // Tim khong thay
    if (node == NULL)
        return node;
    int n = strcmp(name, node->name);
    if (n == 0) // Tim thay
        return node;
    if (n < 0) // De quy con trai
        return find(node->leftChild, name);
    else // De quy con phai
        return find(node->rightChild, name);
}

void ProcessFind()
{
    printf("Nhập tên người cần tìm: ");
    char name[MAX_L];
    scanf("%s", name);
    Node *node = find(root[h(name)], name);
    printf("Thông tin của %s là:\n", name);
    printf("Name: %s\nEmail: %s\n", node->name, node->email);
}

// In cay theo thu tu giua

void printInOrder(FILE *f, Node *node)
{
    if (node == NULL)
        return;
    printInOrder(f, node->leftChild);
    fprintf(f, "%s %s\n", node->name, node->email);
    printInOrder(f, node->rightChild);
}

// Ghi du lieu vao file

void store(char *fileName)
{
    FILE *f = fopen(fileName, "w+");
    for (int i = 0; i < M; i++)
    {
        printInOrder(f, root[i]);
    }
    fclose(f);
}

void ProcessStore()
{
    printf("Nhập tên file cần ghi dữ liệu: ");
    char fileName[MAX_L];
    scanf("%s", fileName);
    store(fileName);
}

int main()
{
    while (1)
    {
        int cmp;
        printf("1.Đọc thông tin từ file\n");
        printf("2.Ghi thông tin vào file\n");
        printf("3.Tìm kiếm theo tên\n");
        printf("4.Thêm một người\n");
        printf("5.Xóa một người\n");
        printf("6.Thoát\n");
        printf("Nhập chức năng muốn thực hiện (1-6): ");
        scanf("%d", &cmp);
        switch (cmp)
        {
        case 1:
            ProcessLoad();
            break;

        case 2:
            ProcessStore();
            break;

        case 3:
            ProcessFind();
            break;

        case 4:
            ProcessInsert();
            break;

        case 5:
            ProcessRemove();
            break;

        default:
            break;
        }
        if (cmp == 6)
            break;
    }
    return 0;
}