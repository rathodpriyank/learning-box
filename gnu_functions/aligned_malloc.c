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

void* aligned_malloc(size_t required_bytes, size_t alignment)
{
    void* m1; // original block
    void** m2; // aligned block
	/* 	void** returns the void*. Converting void* to and from
		other pointer types is allowed because a double-pointer
		is still a pointer. */
    int offset = alignment - 1 + sizeof(void*);
    if ((m1 = (void*)malloc(required_bytes + offset)) == NULL)
    {
       return NULL;
    }
    m2 = (void**)(((size_t)(m1) + offset) & ~(alignment - 1));
	/* ~(alignment - 1) is used to provide the guarantees for the alignment.
		For example if alignment is 16, then subtract 1 to get 15,
		then negating it makes 0xFF..FF0. This mask is required to
		satisfy the alignment for any returned pointer from malloc(). */
    m2[-1] = m1;
	/* Need to perform this, as alloc generally allocates one more
		space to store the length of the allocated memory, which
		needs to be updated in the new location, which can be used
		while performing all the memory allocated */
    return m2;
}

void aligned_free(void *m)
{
    free(((void**)m)[-1]);
	/* 	As explained above, the free is pointing to the one location
		advance, so that it can free all the memory which was being
		allocated in the allocation	*/
}
