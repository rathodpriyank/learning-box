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

int m_strlen(const char* s)
{
	int len = 0;
	while(*s++) len++;
	return len;
}

int main() {
    const char* str = "length test";
    printf("m_strlen(\"%s\") = %d\n", str, m_strlen(str));
    return 0;
}
