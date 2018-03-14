#include <stdio.h>
#include <stdlib.h>

typedef struct ll {
	int data;
	struct ll *next;
} linkedlist_t;

typedef struct bt {
	int data;
	struct bt *left;
	struct bt *right;
} binarytree_t;

typedef enum order{
	INORDER = 0,
	PREORDER = 1,
	POSTORDER = 2,
} ord_t;

typedef enum value {
	MIN = 0,
	MAX,
} value_t;
// linked list definations
void printLL(linkedlist_t *node);
void addNode(linkedlist_t **node, int data);
void appendNode(linkedlist_t **node, int data);
int pop (linkedlist_t *node);
void removeData (linkedlist_t **node, int data);

// binary tree definations
void printBT (binarytree_t *node, ord_t type);
binarytree_t *addLeaf (binarytree_t *node, int data);
int getMaxDepth (binarytree_t *node);
binarytree_t *getValue (binarytree_t *node, value_t val);
