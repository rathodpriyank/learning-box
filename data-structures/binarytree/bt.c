/*
 * bt.c
 *
 *  Created on: May 13, 2016
 *      Author: Priyank
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bt.h"

node_t* insertNode(node_t *head, int data) {
	/* Step1: check if head is NULL, add the data to the root node */
	if (head == NULL) {
		struct node *new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = data;
		new_node->left = NULL;
		new_node->right = NULL;
		return new_node;
	}
	/* Step2: if the root node is not null, check the data of the root node w.r.t new data
	 *	1. if data is less than root data, put new data to left.
	 *	2. if data is greater than the head data, put new data to the right.
	 */
	if (data < head->data)
		head->left = insertNode(head->left, data);
	else if (data > head->data)
		head->right = insertNode(head->right, data);
	/* Step3: return the head */
	return head;
}

node_t* deleteNode(node_t *head, int data) {
	/* Step1: check if head is NULL, add the data to the root node */
	if (head == NULL)
		return head;
	/* Step2: check if data is less than head data, go left, else go to right
	 *  else, check the left is null, if yes, assign right node to temp
	 *  else, check the right is null, if yes, assign left node to temp
	 *  if both of above cases are not true, find the minimum value from right node
	 *  and assign that node to the temp node and remove the right node.
	 */
	if (data < head->data)
		head->left = deleteNode(head->left, data);
	else if (data > head->data)
			head->right = deleteNode(head->right, data);
	else {
		if (head->left == NULL) {
			node_t *temp = head->right;
			free(head);
			return temp;
		}
		if (head->right == NULL) {
			node_t *temp = head->left;
			free(head);
			return temp;
		}
		node_t * temp = minValueNode(head->right);
		head->data = temp->data;
		head->right = deleteNode(head->right, temp->data);
	}
	return head;
}

int sizeofBT(node_t *head) {
	int count = 0;
	/* Step1: check if head is NULL, return 0, as there are no nodes */
	if (head == NULL) {
		return 0;
	} else {
		/* Step2: as there are nodes, hence we are in else part,
		 * 1. Count all nodes on left,
		 * 2. Count all nodes on right,
		 * 3. Add additional 1 for the root node to the count;
		*/
		count = (sizeofBT(head->left) + sizeofBT(head->right) + 1);
	}
	/* Step3: Return the count value */
	return count;
}

void printTree(node_t *head, order_t ord) {
	/* Step1: check if head is NULL, return 0, as there are no nodes */
	if (head == NULL) {
		return;
	}
	/* Step2: Based on the order print the nodes */
	if (ord == INORDER) {
		/* algorithm for in-order is : left, root, right */
		printTree(head->left, ord);
		printf("%d -", head->data);
		printTree(head->right, ord);
	} else if (ord == PREORDER) {
		/* algorithm for in-order is : root, left, right */
		printf("%d -", head->data);
		printTree(head->left, ord);
		printTree(head->right, ord);
	} else if (ord == POSTORDER) {
		/* algorithm for in-order is : left, right, root */
		printTree(head->left, ord);
		printTree(head->right, ord);
		printf("%d -", head->data);
	}
}

int maxDepth(node_t *head) {
	int leftDepth = 0;
	int rightDepth = 0;
	/* Step1: check if head is NULL, return 0, as there are no nodes
	 * else, go to find left depth, return from there with value related to leftDepth
	 * then, go to find right depth, return from there with value related to rightDepth
	 * Add both and add additional 1 to the value of the greater depth.
	 */
	if (head == NULL)
		return (0);
	else
	{
		leftDepth = maxDepth(head->left);
		rightDepth = maxDepth(head->right);
	}
	if (leftDepth > rightDepth)
		return (leftDepth + 1);
	else
		return (rightDepth + 1);
}

node_t *minValueNode(node_t *head) {
	struct node* current = head;
		while (current->left != NULL) {
			current = current->left;
		}
		return current;
}

node_t *maxValueNode(node_t *head) {
	struct node* current = head;
	while (current->right != NULL) {
		current = current->right;
	}
	return current;
}

bool isBST(node_t *head) {
	if (head == NULL)
		return true;
	// check all left nodes are having lesser value w.r.t. their nodes
	if ((head->left != NULL) && (minValueNode(head->left)->data) > head->data)
		return false;
	// check all right nodes are having higher value w.r.t. their nodes
	if ((head->right != NULL) && (maxValueNode(head->right)->data) > head->data)
		return false;
	// check both left and right nodes for the same
	if (!isBST(head->left) || !isBST(head->right))
		return false;
	return true;
}

void mirrorBT(node_t *head) {
	if (head == NULL)
		return NULL;
	else {
		node_t *temp = NULL;
		mirrorBT(head->left);
		mirrorBT(head->right);
		temp = head->left;
		head->left = head->right;
		head->right = temp;
	}
}
