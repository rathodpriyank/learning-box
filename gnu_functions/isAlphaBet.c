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

bool isAlphaBet(char *string)
{
	if ( *string >= 'a' && *string <= 'z' || *string >= 'A' && *string <= 'Z' )
		return true;
	else
		return false;
}
