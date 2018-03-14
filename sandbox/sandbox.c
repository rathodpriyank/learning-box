#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t payload_nibble_swap(uint64_t p, int pos, int bits)
{
    uint64_t nibbleSwappedVal = 0;
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

void main()
{
	uint64_t x = 0x0123456789ABCDEF;
	printf("val = 0x%" PRIx64 "\n", x);
	printf("x updated value is 0x%" PRIx64 "\n", payload_nibble_swap(x, 4, 64));
}

