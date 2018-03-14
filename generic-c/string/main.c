/*
 ============================================================================
 Name        : main.c
 Author      : Priyank Rathod
 Version     :
 Copyright   : GPLv3
 Description : Linked List example
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "stringfunc.h"

int main(void) {
        int option = -1;
        char string[128];

        while (1)
        {
                printf("--------------------------\n");
                printf("1. Sort ASCII String \n");
                printf("2. Reverse ASCII String \n");
                printf("3. Reverse Sentence\n");
                printf("9. Exit the program \n");
                printf("----------------------\n");
                printf("Enter the option : ");
                scanf("%d", &option);

                switch(option)
                {
                case 1:	printf("Enter the string : " );
                		scanf("%s", string);
                		sortASCIIString(string);
                		printf("Sorted string : %s\n", string);
                		break;
                case 2:	printf("Enter the string : " );
        				scanf("%s", string);
        				reverseString(string);
        				printf("Reversed string : %s\n", string);
        				break;
                case 3:	printf("Enter the Sentence : " );
                		scanf(" %[^\n]s", string);
						reverseStringWords(string);
						printf("Reversed string : %s\n", string);
						break;
                case 9:
                		return EXIT_SUCCESS;
                default:
						printf("selected the default option\n");
						break;
                }
        }
        return EXIT_SUCCESS;
}
