#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "gnu_functions.h"

int main(void)
{
        int option = -1;
        int data = -1;
        int data0 = -1;
        int *mem = NULL;
    	char String[32];
    	char Word[32];
    	char c;
    	bool result;

        while (1)
        {
        		memset(String, '\0', sizeof(String));
        		memset(String, '\0', sizeof(Word));
                printf("--------------------------\n");
                printf("1. Aligned Memory \n");
                printf("2. Free aligned memory \n");
                printf("3. Find frequency of character from string \n");
                printf("4. Find alphabet or special character \n");
                printf("5. String copy \n");
                printf("6. String length \n");
                printf("7. Memcpy of string \n");
                printf("8. String Compare \n");
                printf("99. Exit the program \n");
                printf("----------------------\n");

                printf("Enter the option : ");
                scanf("%d", &option);

                switch(option)
                {
                case 1: printf("Enter allocation [e.g. memory-size align-value]: ");
                		scanf("%d %d", &data, &data0);
                		mem = aligned_malloc (data, data0);
                		printf ("Memory size %d: Memory allocation size %d : %p\n", data, data0, mem);
                		break;
                case 2: printf("Freeing the allocation \n");
                		aligned_free (mem);
                		printf ("Freeing : %p\n", mem);
                        break;
                case 3:	printf("Enter a string and word [e.g. String char] : ");
                		scanf("%s %c", String, &c);
                		data = freq_finder(String, &c);
                		printf("Word %c is %d times in a %s string\n", c, data, String);
                		data = -1;
                		break;
                case 4:	printf("Enter the character: ");
                		scanf("%c", &c);
                		if (isAlphaBet(&c))
                				printf("%c is alphabet\n", c);
                			else
                				printf("%c is not alphabet\n", c);
                		break;
                case 5:	printf("Enter the String to copy: ");
        				scanf("%s", String);
        				m_strcpy(String,Word);
        				printf("Copied the string from %p to %p, %s \n", String, Word, Word);
        				break;
                case 6:	printf("Enter the String to Count: ");
                		scanf("%s", String);
                		printf ("Length of string is : %d \n" ,m_strlen(String));
                		break;
                case 7:	printf("Enter the memory to copy: ");
						scanf("%s", Word);
						m_memcpy(String,Word, sizeof(String));
						printf("Copied the string from %p to %p, %s \n", String, Word, String);
						break;
                case 8:
						printf("Enter the First String : ");
						scanf("%s", String);
						printf("Enter the Second String : ");
						scanf("%s", Word);
						result = m_strcmp(String, Word);
						if (result)
								printf("%s and %s are not same\n", String, Word);
							else
								printf("%s and %s are same\n", String, Word);
						break;
                case 99:
                		return EXIT_SUCCESS;
                default:
                		printf("selected the default option\n");
                		break;
                }
        }
        return EXIT_SUCCESS;
}
