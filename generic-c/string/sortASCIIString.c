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

void sortASCIIString(char *string)
{
	char temp;
	int j, i;
	int n = strlen(string);
    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (string[i] > string[j])
            {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
    printf("\n");
}

