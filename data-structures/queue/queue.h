/*
 * stack.h
 *
 *  Created on: Apr 21, 2016
 *      Author: Priyank
 */

#ifndef QUEUE_H_
#define QUEUE_H_

/* structural node */
struct Queue {
    int front;
    int rear;
    int size;
    unsigned capacity;
    int* arr;
};

struct Queue *createQueue(unsigned cap);
int isFull(struct Queue *queue);
int isEmpty (struct Queue *queue);
void push (struct Queue *queue, int data);
int pop (struct Queue *queue);
int front (struct Queue *queue);
int rear (struct Queue *queue);

#endif /* QUEUE_H_ */
