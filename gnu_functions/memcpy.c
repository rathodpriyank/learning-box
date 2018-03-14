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

void m_memcpy(void *dest, void *src, size_t n)
{
	int i=0;
	// Typecast src and dest addresses to (char *)
	// By using void* it can be casted to any format of variable
	char *csrc = (char *)src;
	char *cdest = (char *)dest;
   // Copy contents of src[] to dest[]
   for (i=0; i<n; i++)
       cdest[i] = csrc[i];
}
