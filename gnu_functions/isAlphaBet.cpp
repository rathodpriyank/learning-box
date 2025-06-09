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

bool isAlphaBet(const char* string)
{
	if ((*string >= 'a' && *string <= 'z') || (*string >= 'A' && *string <= 'Z'))
		return true;
	else
		return false;
}

int main() {
    const char* test = "A";
    printf("isAlphaBet(\"A\") = %d\n", isAlphaBet(test));
    const char* test2 = "1";
    printf("isAlphaBet(\"1\") = %d\n", isAlphaBet(test2));
    return 0;
}
