/*
 * ll.h
 *
 *  Created on: Apr 21, 2016
 *      Author: Priyank
 */

#ifndef LL_H_
#define LL_H_

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

// linked list related declarations
void printList(struct node *head);
int sizeofLL(struct node *head_ref);
int searchLL(struct node *head_ref, int data);
void addNode (struct node **head_ref, int data);
void addNodeToLast(struct node **head_ref, int data);
void removeNode(struct node **head_ref, int data);
void SortLinkList(struct node **head_ref);
void SortedInsert (struct node **head_ref, int data);
void reverseLL(struct node **head_ref);
void reverseLLFromTo(struct node **head_ref, int m, int n);
void recursiveReverse(struct node **head_ref);
void DeleteLL(struct node **head_ref);
int pop(struct node **head_ref);
void RemoveDuplicates(struct node **head_ref);
#endif /* LL_H_ */
