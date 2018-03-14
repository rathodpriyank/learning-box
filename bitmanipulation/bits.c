/*
 * bm.c
 *
 *  Created on: Dec 3, 2016
 *      Author: pj
 */
#include <stdio.h>
#include <stdint.h>
#include "bm.h"

int checkBit(int bit, int pos)
{
	int bitCheck;
	return bitCheck = (bit >> pos) & 1;
}

int changeNBit(int bit, int pos, int value)
{
	return bit ^= (-value ^ bit) & ( 1 << pos);
}

int clearBit(int bit, int pos)
{
	return bit &= ~(1 << pos);
}

int countSetBits(int val)
{
	int count;
	for (count = 0; val; val >>= 1)
		count += val & 1;
	return count;
}

unsigned int Flipbit(unsigned int number)
{
	return number^(0xFFFFFFFF);
}

int setBit(int bit, int pos)
{
	return bit |= (1 << pos);
}

void setBitField(uint64_t* reg, int mask, int value, int pos)
{
	int clearMask = 0xFFFF0000;
	int tempMask = mask;
	int i;
	for(i = 0; i < pos - 3; ++i) {
		clearMask = (clearMask << 4) | 0xF;
	}
	tempMask = mask << pos;
	clearMask = clearMask | tempMask;
	*reg = (*reg & clearMask);
}

int toggleBit(int bit, int pos)
{
	return bit ^= (1 << pos);
}
