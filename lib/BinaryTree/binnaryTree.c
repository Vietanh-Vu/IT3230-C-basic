#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	int id; //identifying value
	struct Node *leftChild;
	struct Node *rightChild;
} Node;
Node *root;

void initTree() {
	root == NULL;
}

Node *makeNode(int id){
	Node *p = (Node*)malloc(sizeof(Node));
	p->id = id;
	p->leftChild = NULL;
	p->rightChild = NULL;
	return p;
}

////////////////////////////////////////////
// tim nut 
Node *find(Node *r, int id) { //tim con tro va return con tro tim duoc
	if (r == NULL) return NULL; //neu r rong return null
	if (r->id == id) return r;
	//De quy ham find de tim leftChild
	Node *p = find(r->leftChild, id);
	if(p!=NULL) return p; //return p neu p ton tai
	return find(r->rightChild,id); //neu p khong ton tai chuyen sang xet con ben phai cua r, va dung tiep de quy ham find
}

void processFind() {
	int id;
	printf("Nhap ID cua node can tim : "); scanf("%d", &id);
	Node *p = find(root, id);
	if (p == NULL) printf("%d not found\n", id);
	else printf("%d found\n", id); 
}

////////////////////////////////////////////
// them con trai vao mot nut
void addLeftChild(int u, int left) {
	Node *p = find(root, u);
	if (p == NULL) {
    	printf("%d not found", u);	
    	return;
	}
	if (p->leftChild != NULL) {
	    printf("%d already have left child\n", u);	
		return;	
	}
	p->leftChild = makeNode(left);
}

//////////////////////////////////////////
// them con phai vao mot nut 
void addRightChild(int u, int right) {
	Node *p = find(root, u);
	if (p == NULL) 
	{
		printf("%d not found", u); return;
	}
	if (p->rightChild != NULL) {
	    printf("%d already have right child\n", u); return;	
	}
	p->rightChild = makeNode(right);
}

void load(char *filename) {
	FILE *f = fopen(filename, "r"); //mo file
	root = NULL; //reset root
	while(1) {
		int u;
		fscanf(f,"%d", &u); //scan u 
		if(u == -2) break;
		if(root == NULL) root = makeNode(u); //makeNode neu empty tree
		int l,r;
		fscanf(f,"%d %d", &l, &r);
		if(l > -1) addLeftChild(u,l);
		if(r > -1) addRightChild(u,r);
	}
	fclose(f);
}

void processLoad() {
	char s[100]; 
	printf("Nhap ten file : ");
	scanf("%s", s);
	load(s);
}



void Print(Node *r) {
	if (r == NULL) return;
	else {
		printf("%d ", r->id);
		if (r->leftChild == NULL) printf("-1 ");
		else printf("%d ", r->leftChild->id);
		if (r->rightChild == NULL) printf("-1 ");
		else printf("%d ", r->rightChild->id);
		printf("\n");
		Print(r->leftChild);
		Print(r->rightChild);
	}
}

void PrintF(Node *r, FILE *f) {
	if (r == NULL) return;
	else {
		fprintf(f, "%d ", r->id);
		if (r->leftChild == NULL) fprintf(f, "-1 ");
		else fprintf(f, "%d ", r->leftChild->id);
		if (r->rightChild == NULL) fprintf(f, "-1 ");
		else fprintf(f, "%d ", r->rightChild->id);
		fprintf(f,"\n");
		PrintF(r->leftChild, f);
		PrintF(r->rightChild, f);
	}
}


/////////////////////////////////////////////
// in ra cac nut la 
void printLeaves(Node *r) {
	if (r==NULL) return;
	if(r->leftChild == NULL & r->rightChild ==NULL) {
		printf("%d ", r->id);
	}
	printLeaves(r->leftChild);
	printLeaves(r->rightChild);
} 

void processPrintLeaves() {
	printLeaves(root);
	printf("\n");
}

///////////////////////////////////////////////
// so nut cua cay 
int count(Node *r) {
	if(r == NULL) return 0;
	return 1 + count(r->leftChild) + count(r->rightChild);
}

void processCount(){
	printf("Count = %d\n", count(root));
}

///////////////////////////////////////////////
// tim do cao cua mot nut 
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *node) {
    if (node == NULL) {
        return 0;
    }

    int left_height = height(node->leftChild);
    int right_height = height(node->rightChild);

    return 1 + max(left_height, right_height);
}

void processHeight(){
	int id; scanf("%d", &id);
	Node *p = find(root,id);
	if(p == NULL) printf("Not found %d\n", id);
    else printf("Height of leaf %d is %d\n", id, Height(p));
}

///////////////////////////////////////////////
// check balance
int isBalanced(Node* root)
{
    if (root == NULL)
        return 0;
    int lh = isBalanced(root->leftChild);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->rightChild);
    if (rh == -1)
        return -1;
 
    if (abs(lh - rh) > 1)
        return -1;
    else
        return lh > rh ? lh + 1 : rh + 1;
}

void processStore() {
	char name[256];
	scanf("%s",name);
	FILE *f = fopen(name, "w");
	PrintF(root,f);
	fprintf(f, "-2");
	fclose(f);
}

//////////////////////////////////////////////////
// tim do sau cua 1 nut
int depth(TreeNode* root, TreeNode* node, int level) {
    if (root == NULL) {
        return -1;
    }
    
    if (root == node) {
        return level;
    }
    
    int left_depth = depth(root->left, node, level + 1);
    int right_depth = depth(root->right, node, level + 1);
    
    if (left_depth == -1) {
        return right_depth;
    }
    
    return left_depth;
}

///////////////////////////////////////////////
// xoa cay 
void freeNode(Node *r) {
	if(r==NULL) return;
	freeNode(r->leftChild);
	freeNode(r->rightChild);
	free(r); r = NULL;
}

int main() {
    initTree();
    while(1){
    printf("Enter command: ");
    char cmd[256];
    scanf("%s",cmd);
    if(strcmp(cmd,"Quit")==0) break;
    else if(strcmp(cmd,"Load")==0) processLoad();
    else if(strcmp(cmd,"AddLeftChild") == 0) {
    	int u, l;
		printf("Parent ID : "); scanf("%d", &u);
		printf("LeftChild ID : "); scanf("%d", &l);
		addLeftChild(u, l);
	}
	else if(strcmp(cmd,"AddRightChild") == 0) {
    	int u, r;
		printf("Parent ID : "); scanf("%d", &u);
		printf("RightChild ID : "); scanf("%d", &r);
		addRightChild(u, r);
	}
    else if(strcmp(cmd,"Find")==0) processFind();
    else if(strcmp(cmd,"Print")==0) Print(root);
    else if(strcmp(cmd,"Count")==0) processCount();
    else if(strcmp(cmd,"Height")==0) processHeight();
    else if(strcmp(cmd,"Leaves")==0) processPrintLeaves();
    else if(strcmp(cmd,"Store")==0) processStore();
	}
}