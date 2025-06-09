#include <stdio.h>
#include <stdint.h>

uint32_t ChangeEndianness(uint32_t u32Value)
{
	uint32_t u32Result = 0;
	u32Result |= (u32Value & 0x000000FF) << 24;
	u32Result |= (u32Value & 0x0000FF00) << 8;
	u32Result |= (u32Value & 0x00FF0000) >> 8;
	u32Result |= (u32Value & 0xFF000000) >> 24;
	return u32Result;
}

int checkEndiness (int a) {
    char *b = (char*) &a; 
    if (*b) 
       printf("Little \n");
    else
		printf("Big\n");
	return 0;
}

// int main(int argc, char *argv[]) {
// 	int a = 10;
// 	checkEndiness(a);
// 	a = ChangeEndianness(a);
// 	checkEndiness(a);
// 	return 0;
// }

