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

void m_strcpy(char* s, const char* d)
{
	while ((*s++ = *d++) != '\0');
}

int main() {
    char src[] = "copy me";
    char dest[32];
    m_strcpy(dest, src);
    printf("m_strcpy: %s\n", dest);
    return 0;
}

