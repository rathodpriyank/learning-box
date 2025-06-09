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
#include <cstring>  // for strstr

int freq_finder(const char* string, const char* word)
{
	int count = 0;
	const char* p = string;
	while ((p = strstr(p, word)) != nullptr) {
		count++;
		p++;
	}
	return count;
}

int main() {
	const char* str = "hello world, hello AI";
	const char* word = "hello";
	int count = freq_finder(str, word);
	printf("freq_finder(\"%s\", \"%s\") = %d\n", str, word, count);
	return 0;
}
