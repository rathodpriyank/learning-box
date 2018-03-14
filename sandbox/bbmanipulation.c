#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void printb(int data) {
    int i = 0;
    uint64_t andBit = 0x80000000;
    uint64_t bits = 32;
    printf("Hex: %8x | Decimal: %10d | Binary is : ", data, data);
    for (i=1; i <= bits; i++)
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

bool checkBit(int data, int pos) {
	int cbit  = (data >> pos) & 1;
	return cbit;
}

void setBit(int* data, int pos) {
	*data = *data | (1 << pos);
}

void clearBit(int *data, int pos) {
	*data = *data & ~(1 << pos);
}

void toggleBit(int* data, int pos) {
	*data = *data ^ (1 << pos);
}

bool powerofTwo(int v) {
	return (v && !(v & (v - 1)));
}

int countSetBits(int x) {
	int count = 0;
	for(count=0; x != 0; x >>=1)
		count = count + (x & 1);
	return count;
}

void leftRotate(int *data, int pos) {
	*data = (*data << pos) | (*data ) >> (32 - pos);
}

void rightRotate(int *data, int pos) {
	*data = (*data >> pos) | (*data) << (32 - pos);
}

struct pack_bits {
	int f1:3;
} packedBits;

void main() {
	struct pack_bits b;
    int x = 5;
    int y = 25;
    int min = y ^ ((x ^ y) & -(x < y));
    int max = x ^ ((x ^ y) & -(x < y));
    printf("min value : %d | max value : %d\n", min, max);
    printb(max);
	printf("Bit is %s\n", checkBit(max, 3) ? "Set" : "Unset");
	setBit(&max, 16);
	printb(max);
	clearBit(&max, 3);
	printb(max);
	toggleBit(&max, 15);
	toggleBit(&max, 21);
	leftRotate(&max, 5);
	rightRotate(&max, 4);
	printb(max);
	printf("Power of Two %s\n", powerofTwo(max) ? "Yes" : "No");
	printf("Power of Two %s\n", powerofTwo(16) ? "Yes" : "No");
	printf("Set bits are : %d\n", countSetBits(max));
	b.f1 = 6;
	printf("value of f1 is : %d\n", b.f1);
	printb(b.f1);
}
