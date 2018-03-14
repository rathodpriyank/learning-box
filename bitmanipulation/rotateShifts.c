/*
 * bm.c
 *
 *  Created on: Dec 3, 2016
 *      Author: pj
 */
#include <stdio.h>
#include <stdint.h>
#include "bm.h"

int leftRotateShift(unsigned int n, int d, int s)
{
    return (n << d) | n >> (s - d);
}

int rightRotateShift(unsigned int n, int d, int s)
{
    return (n >> d) | n << (s - d);
}
