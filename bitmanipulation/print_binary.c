/*
 * bm.c
 *
 *  Created on: Dec 3, 2016
 *      Author: pj
 */
#include <stdio.h>
#include <stdint.h>
#include "bm.h"

void print_binary(int data, int bits)
{
        int i = 0;
        uint64_t andBit;
        if (bits == _64BIT)
        	andBit = 0x8000000000000000;
        if (bits == _32BIT)
			andBit = 0x80000000;
        else if (bits == _16BIT)
			andBit = 0x8000;
        else
			andBit = 0x80;

        printf("Hex: %8x | Decimal: %10d | Binary is : ", data, data);
        for (i=1; i < bits+1; i++)
        {
                /* determining the bit value*/
                if ((data & andBit) == 0 )
                        printf("0");
                else
                        printf("1");
                /* just doing for spacing */
                if ( i%4 == 0 )
                        printf(" ");
                data = data << 1;
        }
        printf("\n");
}
