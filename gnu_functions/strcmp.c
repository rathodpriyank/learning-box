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

int m_strcmp(char *src1, char *src2)
{
    int i=0;
    while((*src1!='\0') || (*src2!='\0'))
    {
        if(*src1 > *src2)
            return 1;
        if(*src1 < *src2)
            return -1;
        src1++;
        src2++;
    }
    return 0;
}

