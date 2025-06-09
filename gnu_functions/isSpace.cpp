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

bool isSpace(char *string)
{
	if ( *string == ' ' )
		return true;
	else
		return false;
}

int main() {
	char test[] = " ";
	printf("isSpace(\" \") = %d\n", isSpace(test));
	char test2[] = "a";
	printf("isSpace(\"a\") = %d\n", isSpace(test2));
	return 0;
}
