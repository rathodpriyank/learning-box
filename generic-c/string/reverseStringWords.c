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
			swap(tempString, temp-1);
		}
		/* swap if you find space and then increment the pointer to point next */
		else if(*temp == ' ')
	    {
			swap(tempString, temp-1);
	    	tempString = temp+1;
	    }
	  } /* End of while */

	   /*STEP 2 of the above algorithm */
	reverseString(stringWords);
}
