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
#include "stack.h"

int main()
{
	struct Stack *myStack = createStack(10);
	char temp[] = "Testing";
	push(myStack, 5);
	push(myStack, 15);
	printf("Poping : %d\n", pop(myStack));
	push(myStack, 25);
	printf("Peek : %d\n", peek(myStack));
	reverse(temp);
	printf("Reverse : %s\n", temp);
	return EXIT_SUCCESS;
}
