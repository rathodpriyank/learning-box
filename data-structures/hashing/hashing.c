/*
 * hashing.c
 *
 *  Created on: Apr 21, 2016
 *      Author: Priyank
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hashing.h"

unsigned int hashing(struct hashTable *h, char *key) {
    int i = 0;
    unsigned int hashValue = -1;
    for(i = 0; i < 32; i++) {
        hashValue = hashValue << 8;
        hashValue ^= key[i];
    }
    return (hashValue % h->size);
}

struct hashTable *createHashTable(int size) {
    int i = 0;
    struct hashTable *hash = (struct hashTable*)malloc(sizeof(struct hashTable));
    if (hash == NULL)
        return NULL;
    if (size < 1)
        return NULL;
    else
        hash->size = size;
    hash->table = malloc(sizeof(struct node) * hash->size);
    for(i = 0; i < size; i++)
        hash->table[i] = NULL;
    return hash;
}

struct node *addNode(char *key, char *name) {
	struct node *addNode = (struct node*) malloc (sizeof(struct node));
	addNode->key = strdup(key);
	addNode->name = strdup(name);
	addNode->next = NULL;
	return addNode;
}

void insertTable(struct hashTable *h, char *key, char *name) {
    unsigned int hkey = hashing(h, key);
    printf("Setting hkey value : %d\n", hkey);
    struct node *temp = h->table[hkey];
    struct node *newSet = NULL;
    struct node *last = NULL;
    while(temp != NULL && temp->key != NULL && strcmp(key, temp->key) > 0) {
    	last = temp;
    	temp = temp->next;
    }
    if (temp != NULL && temp->key != NULL && strcmp(key, temp->key) == 0) {
		 free(temp->name);
		 temp->name = strdup(name);
	 } else {
		 struct node *newSet = addNode(key, name);
		 if (temp == h->table[hkey]) {
			 newSet->next = temp;
			 h->table[hkey] = newSet;
		 } else if (temp == NULL) {
			 last->next = newSet;
		 } else {
			 newSet->next = temp;
			 last->next = newSet;
		 }
	 }
}

struct node *getTable(struct hashTable *h, char *key){
    unsigned int hkey = hashing(h, key);
    printf("Getting hkey value : %d\n", hkey);
    struct node *data = (struct node*) malloc (sizeof(struct node*));
    data = h->table[hkey];
        while(data != NULL && data->key != NULL) {
            if(strcmp(key, data->key) == 0)
                return data;
            data = data->next;
    }
    return data;
}
