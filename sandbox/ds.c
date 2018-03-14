#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ds.h"

int g_sampleArray[] = {50, 5, 85, 65, 15, 75, 25, 100, 105, 38, 30};
int g_lengthArray = sizeof(g_sampleArray)/sizeof(g_sampleArray[0]);
    
void linkedlist() {
    linkedlist_t *myll = NULL;
	int i = 0;
	int option = -1;
	int data = -1;
	for(i = 0; i < g_lengthArray; i++)
		addNode(&myll, g_sampleArray[i]);
	
	while (1) {
		printf(" ------------------------------------ \n");
		printf("\t Linked List options \n");
		printf(" ------------------------------------ \n");
		printf("1. Print the current Linked List \n");
		printf("2. Append the ndoe to Linked List \n");
		printf("3. Pop the First node \n");
		printf("4. Remove the desired node \n");
		printf("9. Return to previous screen \n");
		printf(" ------------------------------------ \n");
		printf("Choose an option : ");
		scanf("%d", &option);
		printf(" ------------Response ---------------- \n");
		switch(option) {
			case 1:	printLL(myll);
					break;
			case 2:	printf("Enter the value to append : ");
					scanf("%d", &data);
					appendNode(&myll, data);
					break;
			case 3:	printf("Lastly added node is : %d\n", pop(myll));
					break;
			case 4:	printf("Enter the value : ");
					scanf("%d", &data);
					removeData(&myll, data);
					break;
			case 9:	return;
					break;
			default:	printf("Default option, not doing anything\n");
					break;
		}
	}
    return;
}

void binarytree() {
    int i = 0;
    int option = -1;
    int data = -1;
    binarytree_t *mybt = NULL;
    for(i = 0; i < g_lengthArray; i++)
        mybt = addLeaf(mybt, g_sampleArray[i]);
    
    while(1) {
        printf(" ------------------------------- \n");
        printf("\tBinary Tree options \n");
        printf(" ------------------------------- \n");
        printf("1. Print the tree Inorder \n");
        printf("2. Print the tree Preorder \n");
        printf("3. Print the tree Postorder \n");
        printf("4. Add leaf \n");
        printf("5. Get Maximum Depth \n");
        printf("6. Get Minimum Value \n");
        printf("7. Get Maximum Value \n");
        printf("9. Return to previous screen \n");
        printf(" ------------------------------- \n");
        printf("Choose an option : ");
        scanf("%d", &option);
        printf(" ----------- Response ------------ \n");
        switch (option) {
            case 1: printBT(mybt, INORDER);
                    printf("\n");
                    break;
            case 2: printBT(mybt, PREORDER);
                    printf("\n");
                    break;
            case 3: printBT(mybt, POSTORDER);
                    printf("\n");
                    break;
            case 4: printf("Enter the value to Tree : ");
                    scanf("%d", &data);
                    mybt = addLeaf(mybt, data);
                    break;
            case 5: printf("Size of max Depth is : %d \n", getMaxDepth(mybt));
                    break;
            case 6: printf("Minimum Value is : %d \n", getValue(mybt, MAX)->data);
                    break;
            case 7: printf("Maximum Value is : %d \n", getValue(mybt, MIN)->data);
                    break;
            case 9: return;
                    break;
            default:printf("Choose the correct option \n");
                    break;
        }
    }
    return;
}

int main() {
    int option = -1;   
    while (1) {
        printf(" Data Structure Options \n");
        printf("1. Go to Linked List \n");
        printf("2. Go to Binary Tree \n");
        printf("9. Exit .... \n");
        printf("Enter the option : ");
        scanf("%d", &option);
        
        switch(option) {
            case 1: printf(" Switching to Linked List \n");
                    linkedlist();
                    break;
            case 2: printf(" Switching to Linked List \n");
                    binarytree();
                    break;
            case 9:
                    return EXIT_SUCCESS;
            default:
                    printf("default option, not doing anything\n");
                    break;
        }
    }
}
