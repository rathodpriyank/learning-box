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

void reverseString(char *string)
{
	if (string == NULL)
		return;

	char temp;
	char *start = string;
	char *end = start + strlen(string) - 1;
	while ( end > start)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		// movind start and end points.
		start++;
		end--;
	}
}
