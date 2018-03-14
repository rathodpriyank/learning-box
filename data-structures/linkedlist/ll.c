/*
 * ll.c
 *
 *  Created on: Apr 21, 2016
 *      Author: Priyank
 */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "ll.h"

void printList(struct node *head) {
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int sizeofLL(struct node *head_ref) {
	struct node* temp = head_ref;
	int count = 0;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

int searchLL(struct node *head_ref, int data) {
	int count = 0;
	struct node *temp = head_ref;
	while (temp != NULL) {
		if (temp->data == data)
			return count;
		temp = temp->next;
		count++;
	}
	return -1;
}

void addNode(struct node **head_ref, int data) {
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	/* Special case for the head end */
	new_node->data = data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void addNodeToLast(struct node **head_ref, int data) {
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	struct node* temp = (*head_ref);
	// assigning value to new node
	new_node->data = data;
	new_node->next = NULL;

	if (temp == NULL) {
		temp = new_node;
		return;
	} else {
	/* Special case for the head end */
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	return;
}

void removeNode(struct node **head_ref, int data) {
	struct node *temp, *prev;
	temp = *head_ref;
	printList(temp);
	while (temp != NULL) {
		printf("temp data: %d \n", temp->data);
		if (temp->data == data) {
			if (temp == (*head_ref)) {
				(*head_ref) = temp->next;
				free(temp);
				return;
			} else {
				prev->next = temp->next;
				free(temp);
				return;
			}
		} else {
			prev = temp;
			temp = temp->next;
		}
	}
}

void DeleteNode(struct node **p, int a) {
	struct node *head = NULL;
	if (head == NULL) {
		head = *p;
		if (head->data == a) {
			if ((*p)->next == NULL) {
				*p = NULL;
				return;
			}
			*p = (*p)->next;
			free(head);
			head = NULL;
			return DeleteNode(p, a);
		}
	}
	if ((*p)->next == 0)
		return;
	if (a != (*p)->next->data) {
		return DeleteNode(&((*p)->next), a);
	} else {
		struct node* q = (*p)->next;
		(*p)->next = q->next;
		free((q));
		if ((*p)->next != NULL) {
			return DeleteNode(&((*p)->next), a);
		}
	}
	return;
}

void SortLinkList(struct node **head_ref) {
	struct node* a = (*head_ref);
	struct node* b = (*head_ref)->next;
	while (a->next != NULL) {
		if (a->data > b->data) {
			a->data = a->data ^ b->data;
			b->data = a->data ^ b->data;
			a->data = a->data ^ b->data;
		}
		a = a->next;
		b = b->next;
		SortLinkList(&a);
	}
}

void SortedInsert_wData(struct node **head, int data) {
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = data;
	if((*head) == NULL || (*head)->data >= data) {
		newNode->next = (*head);
		(*head) = newNode;
	} else {
		while((*head)->next != NULL) {
			if ((*head)->next->data >= data) {
				if ((*head)->data <= data) {
					newNode = (*head)->next;
					(*head) = newNode;
				}
			}
			(*head) = (*head)->next;
		}
	}
}

void SortedInsert_wNode(struct node **head_ref, struct node *newNode) {
	if (*head_ref == NULL || (*head_ref)->data >= newNode->data) {
		newNode->next = *head_ref;	// assigning newNode next to head_ref
		*head_ref = newNode;		// assigning newNode as head_ref
	}else {
		struct node *current  = *head_ref;
		while (current->next != NULL && current->next->data < newNode->data
									 && current->data > newNode->data) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void reverseLL(struct node **head_ref) {
	struct node* result = NULL;
	struct node* current = *head_ref;
	struct node* next = NULL;

	while (current != NULL) {
		next = current->next;		// copy to next node
		current->next = result;		// moving node to new result node
		result = current;
		current = next;
	}
	*head_ref = result;
}

void reverseLLFromTo(struct node **head_ref, int m, int n) {
	struct node* result = *head_ref;
	struct node* current = *head_ref;
	struct node* next = NULL;
	int i = 0;
	for(i = 0; i < m-1; i++) {
		current = current->next;
	}
	next = current->next;
	for(i = m; i < n; i++) {
		current->next = next->next;
		next->next = result->next;
		result->next = next;
		next = current->next;
	}
	*head_ref = result;
}

void recursiveReverse(struct node **head_ref) {
	struct node* first;
	struct node* second;
	if (*head_ref == NULL)
		return;
	first = *head_ref;
	second = first->next;
	if (second == NULL)
		return;
	recursiveReverse(&second);
	first->next->next = first;
	first->next = NULL;
	*head_ref = second;
}

void DeleteLL(struct node **head_ref)
{
	struct node *current = *head_ref;	// getting real head
	struct node *next;

	while(current != NULL) {
		next = current->next;		// node to next pointer
		free(current);				// removing the node
		current  = next;			// advancing the node to next node
	}
	*head_ref = NULL;			// terminating the *head_ref to reflect the NULL
}

int pop(struct node **head_ref)
{
	struct node* head = *head_ref;
	int result = -1;
	result = head->data;		// assigning the value of data to result
	*head_ref = head->next;		// creating the next node as head_ref
	free(head);					// removing current head;
	return result;
}

void RemoveDuplicates(struct node **head_ref) {
	struct node* current = *head_ref;
	SortLinkList(&current);
	if (current == NULL)
		return;
	while (current->next != NULL) {
		if (current->data == current->next->data) {
			struct node *temp = current->next->next;
			free(current->next);
			current->next = temp;
		}
		else
			current = current->next;
	}
}

