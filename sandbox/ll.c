#include "ds.h"

void printLL (linkedlist_t *node) {
	if (node == NULL)
		return;
	else { 
		while (node != NULL) {	
			printf("%d ", node->data);
			node = node->next;
		}
		printf("\n");
	}
}

// Adding node to the first node and replacing head
void addNode(linkedlist_t **node, int data) {
	linkedlist_t *newNode = (linkedlist_t *) malloc (sizeof(linkedlist_t));
	newNode->data = data;
	newNode->next = (*node);
	(*node) = newNode;
}

// Adding node to last node
void appendNode(linkedlist_t **node, int data) {
	linkedlist_t *newNode = (linkedlist_t *)malloc(sizeof(linkedlist_t));
	newNode->data = data;
	newNode->next = NULL;
	linkedlist_t *tempNode = (*node);
	if (tempNode == NULL) {
		tempNode = newNode;
	} else {
		while (tempNode->next != NULL) {
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;
	}
}

// Removing the very first node
int pop (linkedlist_t *node) {
	int value = -1;
	linkedlist_t *temp = node;
	value = temp->data;
	node = temp->next;
	free(temp);
	return value;
}

// removes the node contains the particular data
void removeNode (linkedlist_t **node, int data) {
	linkedlist_t *tempNode = (*node);
	linkedlist_t *prevNode;
	if (tempNode == NULL)
		return;
	else {
		while(tempNode != NULL) {
			if (tempNode->data == data) {
				(*node) = tempNode->next;
				free(tempNode);
				return;
			} else {
				prevNode->next = tempNode->next;
				free(tempNode);
				return;	
		}
		prevNode = tempNode;
		tempNode = tempNode->next;
		}
	}
}

void removeData(linkedlist_t **head, int data) {
	linkedlist_t *tempNode = (*head);
	linkedlist_t *prevNode;

	while (tempNode != NULL) {
		if(tempNode->data == data) {
			if (tempNode == (*head)) {
				(*head) = tempNode->next;
				free(tempNode);
				return;
			} else {
				prevNode->next = tempNode->next;
				free(tempNode);
				return;
			}
		} else {
			prevNode = tempNode;
			tempNode = tempNode->next;
		}
	}
}
