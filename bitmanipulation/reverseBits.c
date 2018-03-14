/*
 * bm.c
 *
 *  Created on: Dec 3, 2016
 *      Author: pj
 */
#include <stdio.h>
#include <stdint.h>
#include "bm.h"

int reverseBits(int n, int bits)
{
	int out, i;
	for (out = 0, i = 0; i < bits; ++i)
		out |= ((n >> i) & 1) << (bits - i - 1);
	return out;
}

int reverseBits_5Steps(int n)
{
	// swap odd and even bits of the bits
	n = ((n >> 1) & 0x55555555) | ((n & 0x55555555) << 1);
	// swap consecutive pairs of the bits
	n = ((n >> 2) & 0x33333333) | ((n & 0x33333333) << 2);
	// swap nibbles of the bits
	n = ((n >> 4) & 0x0F0F0F0F) | ((n & 0x0F0F0F0F) << 4);
	// swap bytes of the bits
	n = ((n >> 8) & 0x00FF00FF) | ((n & 0x00FF00FF) << 8);
	// swap 2-byte long pairs of the bits
	n = ( n >> 16             ) | ( n               << 16);
	return n;
}
