#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// declare variable
typedef struct Node{
    int row,col;// chỉ số hang và cột của trạng thái hiện tại
    int step; // số bước di chuyển để đi từ trạng thái xuất phát đến trạng thái hiện tại
    struct Node* next; // con trỏ đến phần tử tiếp theo trong hàng đợi
    struct Node* parent;// con trỏ trỏ đến trạng thái sinh ra trạng thái hiện tại
}Node;

Node *head;
Node *tail;
int A[MAX][MAX];
int r,c;
int r0,c0;
int visited[MAX][MAX];
const int dr[4] = {1,-1,0,0};
const int dc[4] = {0,0,1,-1};
Node *finalNode;


void initQueue() {
    head = NULL;
    tail = NULL;
}

int isEmptyQueue() {
    return head == NULL && tail == NULL;
}

Node *makeNode(int row, int col, int step, Node *parent) {
    Node * node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->step = step;
    node->parent = parent;
    node->next = NULL;
    return node;
}

// push in queue
void enQueue(Node *node) {
    if(isEmptyQueue()) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

Node* deQueue() {
    if (isEmptyQueue()) return NULL;
    Node *tmp = head;
    head = tmp->next;
    if(head == NULL) tail = NULL; // there is only one el in queue 
    return tmp;
}

// get value from file
void input() {
    FILE *f = fopen("maze.txt","r");
    // initial maze 
    fscanf(f,"%d %d %d %d\n", &r, &c, &r0, &c0);
    // input A
    for (int i = 0; i<r; i++) {
        for (int j = 0; j<c; j++) {
            fscanf(f,"%d ",&A[i][j]);
        }
    }
    // input visited
    for (int i = 0; i<r; i++) {
        for (int j = 0; j<c; j++) {
            visited[i][j] = A[i][j];
        }
    }
    fclose(f);
}

int isInEdge(int row, int col) {
    return row == 0 || row == r || col == 0 || col == c;
}


int main() {
    input();
    initQueue();
    enQueue(makeNode(r0,c0,0,NULL)); 
    // printf("head:(%d, %d)\n", head->row, head->col);
    // printf("tail:(%d, %d)\n", tail->row, tail->col);

    visited[r0][c0] = 1; 

    while (!isEmptyQueue()) {
        // printf("Done\n");
        Node *curNode = deQueue();

        // if (head == NULL) printf("head null\n");
        // else printf("head: (%d, %d)\n", head->row, head->col);

        // if (tail == NULL) printf("null\n");
        // else printf("tail: (%d, %d)\n", tail->row, tail->col);

		printf("POP (%d,%d)\n",curNode->row,curNode->col);

        for (int i=0; i<4; i++) { // down up right left
            int curR = curNode->row + dr[i];
            int curC = curNode->col + dc[i];

            if (visited[curR][curC] == 0) {
                visited[curR][curC] = 1;
                Node *newNode = makeNode(curR, curC, curNode->step+1, curNode);
                // printf("(%d,%d) \n", newNode->row, newNode->col);
                if(isInEdge(curR, curC)) {
                    finalNode = newNode;
                    break;
                } else {
                    // printf("done\n");
                    enQueue(newNode);
                    // if (head == NULL) printf("Null");
                    // printf("(%d,%d) ", head->row, head->col);
                }
            }
        }
        if (finalNode != NULL) break;
    }
    
    Node *tmp = finalNode;
    while (tmp!=NULL) {
        printf("(%d,%d) ", tmp->row, tmp->col);
        tmp = tmp->parent;
    }
    return 0;
}
