/*
 * hashtable.h
 *
 *  Created on: Apr 21, 2016
 *      Author: Priyank
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

/* structural node for char && int */
struct node {
    int key;
    int data;
    char *name;
    struct node *next;
};

struct hashTable {
    int size;
    struct node **table;
};


unsigned int hashing(struct hashTable *h, int key);
void printHashTable(struct hashTable *h);
struct hashTable *createHashTable(int size);
void insertTable(struct hashTable *h, int key, int data);
struct node *getTable(struct hashTable *h, int key);
struct node *search (struct hashTable *h, int key);
void delete (struct hashTable *h, int key);
#endif /* HASHTABLE_H_ */
