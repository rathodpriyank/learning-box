/*
 ============================================================================
 Name        : string.c
 Author      : Priyank Rathod
 Version     :
 Copyright   : GPLv3
 Description : String functions
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "stringfunc.h"

void swapString(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin = *end;
    *end = temp;
    *begin++;
    *end--;
  }
}

void swap(char *start, char *end) {
	char temp;
	temp = *start;
	*start = *end;
	*end = temp;
}

void reverseString(char *string)
{
	if (string == NULL)
		return;
	
	char *start = string;
	char *end = start + strlen(string) - 1;
	while ( end > start)
	{
		swap(start, end);
		// movind start and end points.
		start++;
		end--;
	}
}

void reverseStringWords(char *stringWords)
{
	char *tempString = stringWords;
	char *temp = stringWords;

	while(*temp)
	  {
		/* Increment the pointer first to check for space */
		temp++;
		/* swap if you find null*/
		if (*temp == '\0')
		{
			swapString(tempString, temp-1);
		}
		/* swap if you find space and then increment the pointer to point next */
		else if(*temp == ' ')
	    {
			swapString(tempString, temp-1);
	    	tempString = temp+1;
	    }
	  } /* End of while */

	   /*STEP 2 of the above algorithm */
	reverseString(stringWords);
}

void main() {
	char string[128] = "This is a string for the testing";
	
	reverseStringWords(string);
	printf("Reverse Words are : %s\n", string);
}
