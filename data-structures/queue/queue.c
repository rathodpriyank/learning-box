/*
 * queue.c
 *
 *  Created on: Apr 21, 2016
 *      Author: Priyank
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "queue.h"

struct Queue *createQueue(unsigned cap) {
	struct Queue *queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->capacity = cap;
	queue->size = 0;
	queue->front = 0;
	queue->rear = cap - 1;
	queue->arr = (int*) malloc(sizeof(int)*queue->capacity);
}	

int isFull(struct Queue *queue) {
	return (queue->size == queue->capacity);
}

int isEmpty (struct Queue *queue) {
	return (queue->size == 0);
}

void push (struct Queue *queue, int data) {
	if (isFull(queue)) 
		return;
	queue->rear += 1;
	queue->rear %= queue->capacity;
	queue->arr[queue->rear] = data;
	queue->size += 1;
}

int pop (struct Queue *queue) {
	if (isFull(queue)) 
		return -1;
	int data = queue->arr[queue->front];
	queue->front += 1;
	queue->front %= queue->capacity;
	queue->size -= 1;
	return data;
}

int front (struct Queue *queue) {
	if (isEmpty(queue))
		return -1;
	return (queue->arr[queue->front]);
}

int rear (struct Queue *queue) {
	if (isEmpty(queue)) 
		return -1;
	return (queue->arr[queue->rear]);
}
