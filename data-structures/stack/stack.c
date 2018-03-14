/*
 * stack.c
 *
 *  Created on: Apr 21, 2016
 *      Author: Priyank
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "stack.h"

int isEmpty(struct Stack *stack) {
	return (stack->top == (stack->capacity - 1));
}

struct Stack* createStack(int capacity) {
	struct Stack* stack = malloc (sizeof(struct Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = malloc(sizeof(int) * capacity);
	stack->arr = malloc(sizeof(char) * capacity);
	return stack;
}

void push (struct Stack *stack, int data) {
	if (isEmpty(stack)) {
		return;
	}
	stack->array[++stack->top] = data;
}

void pushChar (struct Stack *stack, char data) {
	if (isEmpty(stack)) {
		return;
	}
	stack->arr[++stack->top] = data;
}

int pop (struct Stack *stack) {

	if (isEmpty(stack)){
		return -1;
	}
	return stack->array[stack->top--];
}

char popChar (struct Stack *stack) {
	if (isEmpty(stack)){
		return -1;
	}
	return stack->arr[stack->top--];
}

int peek (struct Stack *stack) {
	if (isEmpty(stack)){
		return -1;
	}
	return stack->array[stack->top];
}

void reverse (char string[]) {
	int n = 0, i = 0;
	while(string[n] != '\0'){
		n++;
	}
	struct Stack *tempStack = createStack(n+1);
	for (i = 0; i < n; i++) {
		pushChar(tempStack, string[i]);
	}
	for (i = 0; i < n; i++) {
		string[i] = popChar(tempStack);
	}
}
