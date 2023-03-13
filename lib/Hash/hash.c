#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

struct node {
  char *key;
  int value;
  struct node *next;
};

struct node *hash_table[SIZE];

// bjd2
unsigned int hash(char *str) {
  unsigned int hash = 5381;
  int c;

  while (c = *str++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash % SIZE;
}

// chaining 
void insert(char *key, int value) {
  unsigned int index = hash(key);

  struct node *new_node = (struct node*) malloc(sizeof(struct node));
  new_node->key = strdup(key);
  new_node->value = value;
  new_node->next = hash_table[index];
  hash_table[index] = new_node;
}

int search(char *key) {
  unsigned int index = hash(key);

  struct node *current = hash_table[index];
  while (current != NULL) {
    if (strcmp(current->key, key) == 0)
      return current->value;
    current = current->next;
  }

  return -1;
}

// liner probing
void insert(char *key, int value) {
  unsigned int index = hash(key);
  unsigned int i = 0;

  while (hash_table[(index + i) % SIZE] != NULL) {
    i++;
  }

  struct node *new_node = (struct node*) malloc(sizeof(struct node));
  new_node->key = strdup(key);
  new_node->value = value;
  new_node->next = NULL;

  hash_table[(index + i) % SIZE] = new_node;
}

int search(char *key) {
  unsigned int index = hash(key);
  unsigned int i = 0;

  while (hash_table[(index + i) % SIZE] != NULL) {
    if (strcmp(hash_table[(index + i) % SIZE]->key, key) == 0) {
      return hash_table[(index + i) % SIZE]->value;
    }
    i++;
  }

  return -1;
}


int main() {
  insert("hello", 1);
  insert("world", 2);
  insert("foo", 3);
  insert("bar", 4);

  int value = search("hello");
  printf("Value of hello is %d\n", value);

  value = search("world");
  printf("Value of world is %d\n", value);

  value = search("foo");
  printf("Value of foo is %d\n", value);

  value = search("bar");
  printf("Value of bar is %d\n", value);

  return 0;
}
