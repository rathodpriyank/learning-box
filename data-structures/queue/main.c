/*
 ============================================================================
 Name        : main.c
 Author      : Priyank Rathod
 Version     :
 Copyright   : GPLv3
 Description : queue examples
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
	struct Queue *myqueue = createQueue(10);
	push(myqueue, 5);
	push(myqueue, 15);
	push(myqueue, 25);
	
	printf("Front is : %d\n", front(myqueue));
	printf("pop : %d\n", pop(myqueue));
	printf("Front is : %d\n", front(myqueue));
	
	return EXIT_SUCCESS;
}
