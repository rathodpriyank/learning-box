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

int m_strcmp(const char* src1, const char* src2)
{
    while(*src1 && *src2 && *src1 == *src2)
    {
        src1++;
        src2++;
    }
    return *src1 - *src2;
}

int main() {
    const char* a = "abc";
    const char* b = "abc";
    const char* c = "abcd";
    printf("m_strcmp(\"abc\", \"abc\") = %d\n", m_strcmp(a, b));
    printf("m_strcmp(\"abc\", \"abcd\") = %d\n", m_strcmp(a, c));
    return 0;
}

