/*
 ============================================================================
 Name        : main.c
 Author      : Priyank Rathod
 Version     :
 Copyright   : GPLv3
 Description : String examples
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "hashing.h"

int main(void) {
    struct hashTable *hashing = createHashTable(20);
    insertTable(hashing, "key1", "Priyank");
    insertTable(hashing, "key2", "Dharita");
    insertTable(hashing, "key3", "Rajat");
    insertTable(hashing, "key4", "Priyank4");
    insertTable(hashing, "key5", "Dharita5");
    insertTable(hashing, "key6", "Rajat6");
    insertTable(hashing, "key7", "Priyank7");
    insertTable(hashing, "key8", "Dharita8");
    insertTable(hashing, "key9", "Rajat9");
    insertTable(hashing, "key10", "Rajat10");
    insertTable(hashing, "key11", "Rajat11");
    printf("\n");
    printf("Key value is : %s\n", (getTable(hashing, "key4"))->name);
    printf("Key value is : %s\n", (getTable(hashing, "key2"))->name);
    printf("Key value is : %s\n", (getTable(hashing, "key3"))->name);
    printf("Key value is : %s\n", (getTable(hashing, "key1"))->name);
    printf("Key value is : %s\n", (getTable(hashing, "key5"))->name);
	return EXIT_SUCCESS;
}
