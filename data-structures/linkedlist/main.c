/*
 ============================================================================
 Name        : main.c
 Author      : Priyank Rathod
 Version     :
 Copyright   : GPLv3
 Description : String examples
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main(void) {
	int option = -1;
	int testArray[] = { 25, 10, 23, 20, 7, 5, 35 };
	int i = 0;
	int data = -1;
	int data0 = -1;

	/* Creating the linked list */
	struct node* head = NULL;

	for (i = 0; i < sizeof(testArray) / sizeof(int); i++)
		addNode(&head, testArray[i]);
	printList(head);

	while (1) {
		printf("--------------------------\n");
		printf("1. Get size of Link List \n");
		printf("2. Add node to Link List \n");
		printf("3. Add node to last in Link List \n");
		printf("4. Sort and Insert node in Link List \n");
		printf("5. Remove node from Link List \n");
		printf("6. Sort the Link List \n");
		printf("7. Search Link List \n");
		printf("8. Reverse Link List \n");
		printf("9. Remove duplicate nodes\n");
		printf("10. Reverse Link list from m to n nodes \n");
		printf("99. Exit the program \n");
		printf("----------------------\n");
		printf("Current Link List : ");
		printList(head);
		printf("----------------------\n");

		printf("Enter the option : ");
		scanf("%d", &option);

		switch (option) {
		case 1:
			printf("Current size of Linked List is : %d \n", sizeofLL(head));
			break;
		case 2:
			printf("Enter the node value : ");
			scanf("%d", &data);
			addNode(&head, data);
			printf("Added node to the linked list \n");
			break;
		case 3:
			printf("Enter the node value : ");
			scanf("%d", &data);
			addNodeToLast(&head, data);
			break;
		case 4:
			printf("Enter the node value : ");
			scanf("%d", &data);
			SortedInsert_wData(&head, data);
			break;
		case 5:
			printf("Enter the removal node : ");
			scanf("%d", &data);
			removeNode(&head, data);
			//DeleteNode(&head, data);
			printf("Removed node from the linked list \n");
			break;
		case 6:
			SortLinkList(&head);
			break;
		case 7:
			printf("Enter Search value : ");
			scanf("%d", &data);
			int location = searchLL(head, data);
			if (location == -1)
				printf("No entry found \n");
			else
				printf("Location of entry is : %d\n", location);
			break;
		case 8:
			recursiveReverse(&head);
			printList(head);
			break;
		case 9:
			RemoveDuplicates(&head);
			printList(head);
			break;
		case 10:
			printf("Enter Starting and Ending index : ");
			scanf("%d %d", &data, &data0);
			reverseLLFromTo(&head, data, data0);
			printList(head);
			break;
		case 99:
			return EXIT_SUCCESS;
		default:
			printf("selected the default option\n");
			break;
		}
	}
	return EXIT_SUCCESS;
}
