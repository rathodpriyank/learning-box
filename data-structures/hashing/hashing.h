/*
 * ll.h
 *
 *  Created on: Apr 21, 2016
 *      Author: Priyank
 */

#ifndef HASHING_H_
#define HASHING_H_

/* structural node */
struct node {
    char *key;
    char *name;
    struct node *next;
};

struct hashTable {
    int size;
    struct node **table;
};

unsigned int hashing(struct hashTable *h, char *key);
struct hashTable *createHashTable(int size);
void insertTable(struct hashTable *h, char *key, char *name);
struct node *getTable(struct hashTable *h, char *key);

#endif /* HASHING_H_ */
