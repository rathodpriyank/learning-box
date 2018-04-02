/*
 * hashtable.c
 *
 *  Created on: Apr 21, 2016
 *      Author: Priyank
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hashtable.h"

unsigned int hashing(struct hashTable *h, int key) {
    return (key % h->size);
}

void printHashTable(struct hashTable *h) {
	int i = 0;
	
   for(i = 0; i< h->size; i++) {
	
      if(h->table[i] != NULL)
         printf(" (%d,%s,%d)",h->table[i]->key, h->table[i]->name, h->table[i]->data);
      else
         printf(" ~~ ");
   }
   printf("\n");
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

struct node *addNode(int key, char *name, int data) {
	struct node *addNode = (struct node*) malloc (sizeof(struct node));
	addNode->key = key;
	addNode->data = data;
	addNode->name = strdup(name);
	addNode->next = NULL;
	return addNode;
}

void insertTable(struct hashTable *h, int key, char *name, int data) {
    unsigned int hkey = hashing(h, key);
    printf("Setting hkey value : %d\n", hkey);
    struct node *temp = h->table[hkey];
    struct node *newSet = NULL;
    struct node *last = NULL;
    while(temp != NULL && temp->key != 0 && (key == temp->key)) {
    	last = temp;
    	temp = temp->next;
    }
    if (temp != NULL && temp->key != 0 && (key == temp->key)) {
		 free(temp->name);
		 temp->name = strdup(name);
		 temp->data = data;
	 } else {
		 struct node *newSet = addNode(key, name, data);
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

struct node *getTable(struct hashTable *h, int key){
    unsigned int hkey = hashing(h, key);
    printf("Getting hkey value : %d\n", hkey);
    struct node *data = (struct node*) malloc (sizeof(struct node*));
    data = h->table[hkey];
        while(data != NULL && data->key != 0) {
            if(key == data->key)
                return data;
            data = data->next;
    }
    return NULL;
}

struct node *search (struct hashTable *h, int key) {
	int hkey = hashing(h, key);
	
	while(h->table[hkey] != NULL) {
		if (h->table[hkey]->key == key) {
			return h->table[hkey];
		}
		h->table[hkey] = h->table[hkey]->next;
	}
}


void delete (struct hashTable *h, int key) {
	int hkey = hashing(h, key);
	while(h->table[hkey] != NULL) {
		if (h->table[hkey]->key == key) {
			struct node* temp = h->table[hkey];
			printf("Removing : %s\n", temp->name);
			h->table[hkey]->name = NULL;
			h->table[hkey]->key = -1;
			h->table[hkey]->data = -1;
			return;
		}
		h->table[hkey] = h->table[hkey]->next;
	}
}
