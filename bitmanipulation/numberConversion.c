/*
 * bm.c
 *
 *  Created on: Dec 3, 2016
 *      Author: pj
 */
#include <stdio.h>
#include <stdint.h>
#include "bm.h"


long intconversion (char buffer[])
{
	int value = -1;
	printf("%x %x %x %x\n", buffer[0], buffer[1], buffer[2], buffer[3]);
//	buffer[0] = (value >> 24) & 0xFF;
//	buffer[1] = (value >> 16) & 0xFF;
//	buffer[2] = (value >> 8) & 0xFF;
//	buffer[3] = value & 0xFF;
	return value;
}

long floatconversion (char buf[])
{
    int hex = (buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3]);
    float f = *(float *)&hex;
    return hex;
}
