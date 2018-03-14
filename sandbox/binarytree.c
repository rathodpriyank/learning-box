#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct bt {
	int data;
	struct bt *left;
	struct bt *right;
} binary_t;

void printTree(binary_t *head) {
	if (head == NULL)
		return;
	printTree(head->left);
	printf("%d ", head->data);
	printTree(head->right);
}

int sizeofBinaryTree(binary_t *head) {
	if (head == NULL)
		return 0;
	return (sizeofBinaryTree(head->left) + sizeofBinaryTree(head->right) + 1);
}

binary_t *minValueNode (binary_t *head) {
	binary_t *temp = head;
	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

binary_t *maxValueNode (binary_t *head) {
	binary_t *temp = head;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

binary_t* insertNode(binary_t *head, int data) {
	if (head == NULL) {
		binary_t *newNode = (binary_t*)malloc(sizeof(binary_t));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	if (head->data < data)
		head->left = insertNode(head->left, data);
	else
		head->right = insertNode(head->right, data);
	return head;
}

binary_t* deleteNode(binary_t *head, int data) {
	if (head == NULL)
		return head;
	if (head->data < data)
		head->left = deleteNode(head->left, data);
	else if (head->data > data)
		head->right = deleteNode(head->right, data);
	else {
		if (head->left == NULL) {
			binary_t *temp = head->right;
			free(head);
			return temp;
		}
		if (head->right == NULL) {
			binary_t *temp = head->left;
			free(head);
			return temp;
		}
		binary_t *temp = minValueNode(head->right);
		head->data = temp->data;
		head->right = deleteNode(head->right, temp->data);
	}
	return head;
}

int maxDepth(binary_t *head) {
	int ldepth = 0;
	int rdepth = 0;
	if (head == NULL)
		return 0;
	ldepth = maxDepth(head->left);
	rdepth = maxDepth(head->right);
	if (ldepth > rdepth)
		return ldepth + 1;
	else
		return rdepth + 1;
}

bool isBST(binary_t *head) {
	if (head == NULL)
		return true;
	if ((head->left != NULL) && (minValueNode(head->left)->data) > head->data)
		return false;
	if ((head->right != NULL) && (minValueNode(head->right)->data) > head->data)
		return false;
	if (!isBST(head->left) || !isBST(head->right))
		return false;
	return true;
}

void mirrorBinaryTree(binary_t *head) {
	if (head == NULL)
		return;
	else {
		binary_t *temp = NULL;
		mirrorBinaryTree(head->left);
		mirrorBinaryTree(head->right);
		temp = head->left;
		head->left = head->right;
		head->right = temp;
	} 
}

void main(){
	binary_t *mynode = NULL;
	mynode = insertNode(mynode, 50);
	mynode = insertNode(mynode, 5);
	mynode = insertNode(mynode, 51);
	mynode = insertNode(mynode, 2);
	mynode = insertNode(mynode, 15);
	mynode = insertNode(mynode, 65);
	mynode = insertNode(mynode, 48);
	printTree(mynode); 	printf("\n");
	printf("Size of tree is : %d\n", sizeofBinaryTree(mynode));
	mynode = deleteNode(mynode, 51);
	printTree(mynode); 	printf("\n");
	printf("Depth of tree is : %d\n", maxDepth(mynode));
	printf("Is Bt a BST? : %d : %d:%d\n", isBST(mynode), false, true);
	mirrorBinaryTree(mynode);
	printTree(mynode); 	printf("\n");
}
