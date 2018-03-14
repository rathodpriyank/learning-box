/*
 * bt.h
 *
 *  Created on: May 13, 2016
 *      Author: Priyank
 */

#ifndef BT_H_
#define BT_H_
#include <stdbool.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
} node_t;

typedef enum {
	INORDER,
	PREORDER,
	POSTORDER,
} order_t;

int sizeofBT(node_t *head_ref);
void printTree(node_t *head, order_t ord);
struct node* insertNode(node_t *head, int data);
node_t *minValueNode(node_t *head);
node_t *maxValueNode(node_t *head);
bool isBST(node_t *head);
void mirrorBT(node_t *head);

#endif /* BT_H_ */
