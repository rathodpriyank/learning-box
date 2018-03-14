/*
 * stack.h
 *
 *  Created on: Apr 21, 2016
 *      Author: Priyank
 */

#ifndef HASHING_H_
#define HASHING_H_

/* structural node */
struct Stack {
    int top;
    unsigned capacity;
    int* array;
    char* arr;
};

int isEmpty(struct Stack *stack);
struct Stack* createStack(int capacity);
void push (struct Stack *stack, int data);
void pushChar (struct Stack *stack, char data);
int pop (struct Stack *stack);
char popChar (struct Stack *stack);
int peek (struct Stack *stack);
void reverse (char string[]);

#endif /* HASHING_H_ */
