#include <stdio.h>
#include <stdlib.h>

int rows, cols, startRow, startCol;
int maze[100][100];

typedef struct Node
{
    int row;
    int col;
    int step;
    struct Node *next;
    struct Node *prev;
} Node;
Node *first, *last, *finalNode;

void initQueue()
{
    first = NULL;
    last = NULL;
}

int isQueueEmpty()
{
    return first == NULL && last == NULL;
}

Node *makeNode(int row, int col, int step, Node *parent)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->row = row;
    p->col = col;
    p->next = parent;
    p->prev = NULL;
    p->step = step;
    return p;
}

void push(int row, int col, int step, Node *parent)
{
    Node *node = makeNode(row, col, step, parent);
    if (isQueueEmpty())
    {
        first = node;
        last = node;
    } else
    {
        first->prev = node;
        first = node;
    }
    maze[row - 1][col - 1] = 1;
}

Node *pop()
{
    Node *node = last;
    last = node->prev;
    if (last == NULL)
    {
        first = NULL;
    }
    return node;
}

int check(int a, int b)
{
    return (a - 1 == rows || a - 1 == 0 || b - 1 == cols || b - 1 == 0);
}

void prepare()
{
    FILE *f = NULL;
    f = fopen("input.txt", "r");
    fscanf(f, "%d %d %d %d\n", &rows, &cols, &startRow, &startCol);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            fscanf(f, "%d ", &maze[i][j]);
        }        
    }
    fclose(f);
    initQueue();
}

int main()
{
    prepare();
    push(startRow, startCol, 1, NULL);
    while (1)
    {
        Node *node = pop();
        if (check(node->row, node->col))
        {
            printf("%d\n", node->step);
            finalNode = node;
            break;
        }
        if (!maze[node->row - 2][node->col - 1])
            push(node->row - 1, node->col, node->step + 1, node);
        if (!maze[node->row][node->col - 1])
            push(node->row + 1, node->col, node->step + 1, node);
        if (!maze[node->row - 1][node->col - 2])
            push(node->row, node->col - 1, node->step + 1, node);
        if (!maze[node->row - 1][node->col])
            push(node->row, node->col + 1, node->step + 1, node);
    }
    Node *node = finalNode;
    while (node!=NULL) {
        printf("(%d,%d) ", node->row, node->col);
        node = node->next;
    }
    printf("\n");
}