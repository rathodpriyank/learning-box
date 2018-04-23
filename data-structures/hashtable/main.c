/*
 ============================================================================
 Name        : main.c
 Author      : Priyank Rathod
 Version     :
 Copyright   : GPLv3
 Description : hashtable examples
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(void) {
    struct hashTable *hashing = createHashTable(20);
    insertTable(hashing, 0, 43);
    insertTable(hashing, 1, 25);
    insertTable(hashing, 2, 12);
    insertTable(hashing, 3, 65);
    insertTable(hashing, 4, 45);
    insertTable(hashing, 5, 23);
;
    printf("\n");
    printHashTable(hashing);
    
    printf("\n");
	delete(hashing, 2);
	printHashTable(hashing);
	return EXIT_SUCCESS;
}
