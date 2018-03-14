/*
 * gnu_functions.c
 *
 *  Created on: Dec 10, 2016
 *      Author: pj
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "gnu_functions.h"

int freq_finder(char *string, char *word)
{
	int i = 0;
	int count = 0;
	for ( i = 0; string[i] != '\0'; i++)
	{
		if (*word == string[i])
			count++;
	}
	return count;
}
