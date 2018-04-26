/*
 * bm.c
 *
 *  Created on: Dec 3, 2016
 *      Author: pj
 */
#include <stdio.h>
#include <stdint.h>
#include "bm.h"

int swapBits(int a, int pos)
{
	if (4 == pos)
		a = (a & 0xf0) >> pos | (a & 0x0f) << pos;
	else if (8 == pos)
		a = (a & 0xff00) >> pos | (a & 0x00ff) << pos;
	else if (16 == pos)
		a = (a & 0xffff0000) >> pos | (a & 0x0000ffff) << pos;
	else
		a = -1;
	return a;
}

int swapBitsinPair (int x) {
	return ((x & 0xAA) >> 1) | ((x & 0x55) << 1);
}

uint64_t payload_swap(uint64_t p, int bits)
{
    uint64_t nibbleSwappedVal = 0;
    int pos = 4;
	if (bits == 64)
		nibbleSwappedVal = ((p >> pos) & 0x0f0f0f0f0f0f0f0f) | ((p & 0x0f0f0f0f0f0f0f0f) << pos);
	else if (bits == 32)
		nibbleSwappedVal = ((p >> pos) & 0x0f0f0f0f) | ((p & 0x0f0f0f0f) << pos);
	else if (bits == 16)
		nibbleSwappedVal = ((p >> pos) & 0x0f0f) | ((p & 0x0f0f) << pos);
	else if (bits == 8)
		nibbleSwappedVal = ((p >> pos) & 0x0f) | ((p & 0x0f) << pos);
    return nibbleSwappedVal;
}
