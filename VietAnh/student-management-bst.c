#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_L 256
#define MAX 100000

//////////////////////////////////////////////////
// Declare variables
typedef struct Node{
    char name[256];
    char email[256];
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* root;

int choice;

void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

Node *makeNewNode(char name[MAX_L], char email[MAX_L]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

//////////////////////////////////////////////////
// find by name

Node *find(Node *root, char name[MAX_L]) {
    if (root == NULL) return NULL;

    if (strcmp(root->name, name) > 0) {
        return find(root->leftChild, name);
    } else if (strcmp(root->name, name) < 0) {
       return find(root->rightChild, name);
    } else return root;
}

//////////////////////////////////////////////////
// print to screen
void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%s %s\n",r->name,r->email);
    inOrder(r->rightChild);
}

void printList(){
    inOrder(root);
    printf("\n");
}

//////////////////////////////////////////////////
// print to file 
void inOrderF(Node* r, FILE* f){
    if(r == NULL) return;
    inOrderF(r->leftChild,f);
    fprintf(f,"%s %s\n",r->name,r->email);
    inOrderF(r->rightChild,f);
}

void processStore(){
    char filename[256];
    printf("Enter file name: "); scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    inOrderF(root,f);
    fclose(f);
}

//////////////////////////////////////////////////
// insert to bst 
Node *insert(Node *root, char name[MAX_L], char email[MAX_L]) {
    if (root == NULL) return makeNewNode(name, email);

    if (strcmp(name, root->name) > 0) {
        root->rightChild = insert(root->rightChild, name, email);
    } else if (strcmp(name, root->name) < 0) {
        root->leftChild = insert(root->leftChild, name, email);
    }
    return root;
}

void processInsert(){
    char name[256], email[256];
    // printf("Enter name and email: \n");
    scanf("%s %s",name,email);
    root = insert(root,name,email);
}

//////////////////////////////////////////////////
// Load data from file and put in bst 

void load(){
    // FILE* f = fopen("studentProfile.txt","r");
    // if(f == NULL) printf("Load data -> file not found\n");
    //     root = NULL;
    // while(!feof(f)){
    //     char name[256], email[256];
    //     fscanf(f,"%s %s",name, email);
    //     root = insert(root,name,email);
    // }
    // fclose(f);

    int numOfProfile;
    scanf("%d", &numOfProfile);
    for (int i = 0; i<numOfProfile; i++) {
        processInsert();
    }
}

//////////////////////////////////////////////////
// remove from bst 
Node* minValueNode(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->leftChild != NULL)
        current = current->leftChild;
 
    return current;
}

Node* removeNode(Node* root, char name[MAX_L])
{
  // Base case: tree is empty
  if (root == NULL) return root;

  // Recursive case: search for the key value
  if (strcmp(root->name, name) > 0)
    root->leftChild = removeNode(root->leftChild, name);
  else if (strcmp(root->name, name) < 0)
    root->rightChild = removeNode(root->rightChild, name);
  else  // Key value found: remove the node
  {
    // Case 1: node has no children
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
      free(root);
      root = NULL;
    }
    // Case 2: node has one child
    else if (root->leftChild == NULL)
    {
    Node* temp = root;
      root = root->rightChild;
      free(temp);
    }
    else if (root->rightChild == NULL)
    {
    Node* temp = root;
      root = root->leftChild;
      free(temp);
    }
    // Case 3: node has two children
    else
    {
      // Find the inorder successor (smallest in the right subtree)
    Node* temp = minValueNode(root->rightChild);

      // Copy the inorder successor's key value to this node
      strcpy(root->name, temp->name);

      // Delete the inorder successor
      root->rightChild = removeNode(root->rightChild, temp->name);
    }
  }

  // Return the updated tree
  return root;
}


void processRemove(){
    char name[256];
    // printf("Enter name: ");
    scanf("%s",name);
    root = removeNode(root,name);
}


//////////////////////////////////////////////////
// printf menu
void printfMenu() {
    printf("----------------------------\n");
    printf("1. Load data from file.\n"); //load()
    printf("2. Find student by name.\n"); // find()
    printf("3. Insert new profile.\n"); // processInsert()
    printf("4. Remove profile by name.\n"); // processRemove()
    printf("5. Store.\n"); // processStore()
    printf("6. Print to screen.\n"); // printList()
    printf("7. Exit\n");
    printf("----------------------------\n");
    printf("Enter your choice: "); scanf("%d", &choice);
    printf("----------------------------\n");

}

int main(){
        while(1){
            // printf("Enter command: ");
            char cmd[256];
            scanf("%s",&cmd);
            if(strcmp(cmd,"Quit")==0){printf("Bye"); break;} 
                else if(strcmp(cmd,"Load")==0) load();
                else if(strcmp(cmd,"Print")==0) printList();
                else if(strcmp(cmd,"Find")==0) {
                        char name[MAX_L];
                        scanf("%s", &name);
                        Node *result = find(root, name);
                        if (result != NULL)
                        printf("%s\n", result->email);
                    }
                else if(strcmp(cmd,"Insert")==0) processInsert();
                else if(strcmp(cmd,"Remove")==0) processRemove();
                else if(strcmp(cmd,"Store")==0) processStore();
        }
        freeTree(root);
        return 0;
    }

// int main() {
    // do {
    //     printfMenu();
    //     switch (choice)
    //     {
    //     case 1: //done 
    //         load();
    //         break;
    //     case 2: //done
    //         char name[MAX_L];
    //         printf("Enter name: "); scanf("%s", &name);
    //         Node *result = find(root, name);
    //         if (result == NULL) printf("Cannot find!");
    //         else printf("Your result: %s %s\n", result->name, result->email);
    //         break;
    //     case 3: // done 
    //         processInsert();
    //         break; 
    //     case 4:
    //         processRemove();
    //         break;         
    //     case 5: // done 
    //         processStore();
    //         break;   
    //     case 6: // done 
    //         printList();
    //         break;   
    //     case 7: // done 
    //         printf("Exit!\n");
    //         break;
    //     default:
    //         printf("Invalid!\n");
    //         break;
    //     }

    // } while(choice != 7);
// }