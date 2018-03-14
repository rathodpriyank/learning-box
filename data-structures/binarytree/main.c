/*
 ============================================================================
 Name        : main.c
 Author      : Priyank Rathod
 Version     :
 Copyright   : GPLv3
 Description : Binary Tree example
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "bt.h"

int main(void) {
	int option = -1;
	int arr[] = { 40, 3, 4, 6, 10, 20 };
	int i = 0;
	int data = -1;
	int result = -1;
	/* Creating the Binary Tree */
	struct node* head = NULL;

	for (i = 0; i < sizeof(arr) / sizeof(int); i++)
		head = insertNode(head, arr[i]);

	while (1) {
		printf("--------------------------\n");
		printf("0. Print Binary Tree \n");
		printf("1. Get size of Binary Tree \n");
		printf("2. Add node to Binary Tree \n");
		printf("3. Find the Maximum Depth of Tree \n");
		printf("4. Delete the key \n");
		printf("5. Get Minimum Value \n");
		printf("6. Get Maximum Value \n");
		printf("7. Check if list if BST \n");
		printf("8. Mirror the tree \n");
		printf("9. Exit the program \n");
		printf("----------------------\n");
		printf("Current Binary Tree : ");
		printTree(head, INORDER);
		printf("\n----------------------\n");

		printf("Enter the option : ");
		scanf("%d", &option);

		switch (option) {
		case 0:	printf("Enter the Order of print: [i.e. 1 = INORDER, 2 = PREORDER, 3 = POSTORDER] : ");
				scanf("%d", &data);
				printf("Sorting order result : ");
				if (data == 1)
					printTree(head, INORDER);
				else if (data == 2)
					printTree(head, PREORDER);
				else if (data == 3)
					printTree(head, POSTORDER);
				else
					printf("Wrong option selected\n");
				printf("\n");
				break;
		case 1:
				printf("Current size of Binary Tree is : %d \n", sizeofBT(head));
				break;
		case 2:	printf("Enter the node value : ");
				scanf("%d", &data);
				head = insertNode(head, data);
				printf("Added node to the Binary Tree \n");
				break;
		case 3:	printf("Maximum Depth of Binary Tree is : %d \n", maxDepth(head));
				break;
		case 4:	printf("Enter the node value to delete: ");
				scanf("%d", &data);
				head = deleteNode(head, data);
				printf("Removed node from the Binary Tree \n");
				break;
		case 5:	printf("Minimum value from the tree is : %d\n", (minValueNode(head))->data);
				break;
		case 6:	printf("Maximum value from the tree is : %d\n", (maxValueNode(head))->data);
				break;
		case 7:	if(isBST(head))
					printf("The tree is not binary search tree\n");
				else
					printf("The tree is binary search tree\n");
				break;
		case 8:	printf("Mirrored tree is here\n");
				mirrorBT(head);
				printTree(head, INORDER);
				break;
		case 9:
			return EXIT_SUCCESS;
		default:
			printf("selected the default option\n");
			break;
		}
	}
	return EXIT_SUCCESS;
}
