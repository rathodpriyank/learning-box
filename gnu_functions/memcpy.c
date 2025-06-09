/*
 * gnu_functions.c
 *
 *  Created on: Dec 10, 2016
 *      Author: pj
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdbool.h>
#include "gnu_functions.h"
#include <stdint.h>  // Add this for uintptr_t

 bool is_4byte_aligned(void* p) {
    if ((uintptr_t)p % sizeof(int) == 0)
        return true;
    else
        return false;
}

void memcpy0(void *dest, void *src, int size) {
	int i = 0;
	char *source = (char *) src;
	char *destination = (char *) dest;
	int length = (size / sizeof(int));

	for(i = 0; i < length; i++)
	{
		*((int*)destination) = *((int*)source);
		destination +=  sizeof(int);
		source += sizeof(int);
	}

	length = (size % sizeof(int));
	for(i = 0; i < length; i++) {
		*(destination) = *(source);
		destination++;
		source++;
	}
}

void memcpy1(void *dest, void *src, int size) {
	volatile char *source, *destination;
	while(size-- > 0) {
    *destination++ = *source++;
	}
}

void memcpy2(void *dest, void *src, int size) {
	char *source = (char *) src;
	char *destination = (char *) dest;
	while (size) {
		*destination = *source;
		destination++;
		source++;
		size--;
	}
}

void memcpy3(void *dest, void *src, int size) {
	int i = 0;
	char *source = (char *) src;
	char *destination = (char *) dest;
	for(i = 0; i < size; i++)
	destination[i] = source[i];
}

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
