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
    insertTable(hashing, 0, "Rajat0", 43);
    insertTable(hashing, 1, "Priyank", 25);
    insertTable(hashing, 2, "Dharita", 12);
    insertTable(hashing, 3, "Rajat", 65);
    insertTable(hashing, 4, "Priyank4", 445);
    insertTable(hashing, 5, "Dharita5", 123);
;
    printf("\n");
    printHashTable(hashing);
    
    printf("\n");
    printf("Search value is : %s\n", (search(hashing, 3))->name);
	delete(hashing, 2);
	printHashTable(hashing);
	return EXIT_SUCCESS;
}
