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

int m_strlen (char *s)
{
	int i = 0;
	for(i=0; s[i] != '\0'; i++);
	return i;
}
