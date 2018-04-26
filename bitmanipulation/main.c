/*
 ============================================================================
 Name        : main.c
 Author      : Priyank Rathod
 Version     :
 Copyright   : GPLv3
 Description : Bit Manipulation example
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "bm.h"

int main(void)
{
        int option = -1;
        int data = -1;
        int bit_size = 32;
        uint64_t reg_value   	= 0x12345678;
        int mask                = 0x0101;
        int value               = 16;
        int pos                 = 4;

        while (1)
        {
			data = -1;
			printf("--------------------------\n");
			printf("0.  Set bit size \n");
			printf("1.  Print binary value of any decimal \n");
			printf("2.  setBitField of register \n");
			printf("3.  Flipbit \n");
			printf("4.  leftRotateShift \n");
			printf("5.  rightRotateShift \n");
			printf("6.  setBit \n");
			printf("7.  clearBit \n");
			printf("8.  toggleBit \n");
			printf("9.  checkBit \n");
			printf("10. changeNBit \n");
			printf("11. reverseBits \n");
			printf("12. swapBits \n");
			printf("13. swapping payload \n");
			printf("14. Swap bits in pairs \n");
			printf("99. Exit the program \n");
			printf("----------------------\n");
			printf("Enter the option : ");
			scanf("%d", &option);
			switch(option)
			{
				case 0:	printf("Set bit size : [e.g. 8, 16, 32, 64] : ");
						scanf("%d", &bit_size);
						break;
				case 1:	printf("Enter the value to print in binary : ");
						scanf("%d", &value);
						print_binary(value, bit_size);
						break;
				case 2:	printf("Enter the register : ");
						scanf("%x", &reg_value);
						printf("Enter the mask value : ");
						scanf("%d", &mask);
						printf("Enter the shift value : ");
						scanf("%d", &value);
						printf("Enter the mask position : ");
						scanf("%d", &pos);
						PRINT_HEAD(reg_value);
						print_binary(reg_value, bit_size);
						PRINT_HEAD(setBitField);
						setBitField(&reg_value, mask, value, pos);
						print_binary(reg_value, bit_size);
						break;
				case 3:	printf("Enter the integer to flip bits : ");
						scanf("%d", &data);
						PRINT_HEAD(Flipbit);
						print_binary(Flipbit(data), bit_size);
						break;
				case 4:	printf("Enter the value to left shift (rotate) : ");
						scanf("%d", &data);
						printf("Enter the shift position : ");
						scanf("%d", &pos);
						PRINT_HEAD(leftRotateShift);
						print_binary(leftRotateShift(data,pos,bit_size), bit_size);
						break;
				case 5:	printf("Enter the value to right shift (rotate) : ");
						scanf("%d", &data);
						printf("Enter the shift position : ");
						scanf("%d", &pos);
						PRINT_HEAD(rightRotateShift);
						print_binary(rightRotateShift(data,pos,bit_size), bit_size);
						break;
				case 6:	printf("Enter the value for setting bit : ");
						scanf("%d", &data);
						printf("Which bit position to set? : ");
						scanf("%d", &pos);
						PRINT_HEAD(setBit);
						print_binary(setBit(data,pos), bit_size);
						break;
				case 7:	printf("Enter the value for clearing bit : ");
						scanf("%d", &data);
						printf("Which bit position to clear? : ");
						scanf("%d", &pos);
						PRINT_HEAD(clearBit);
						print_binary(clearBit(data,pos), bit_size);
						break;
				case 8:	printf("Enter the value for toggeling bit : ");
						scanf("%d", &data);
						printf("Which bit position to toggle? : ");
						scanf("%d", &pos);
						PRINT_HEAD(toggleBit);
						print_binary(toggleBit(data,pos), bit_size);
						break;
				case 9:	printf("Enter the value for Checking bit : ");
						scanf("%d", &data);
						printf("Which bit position to check? : ");
						scanf("%d", &pos);
						PRINT_HEAD(checkBit);
						printf("checking bit is : %d\n", checkBit(data,pos));
						break;
				case 10:	printf("Enter the value for bit : ");
							scanf("%d", &data);
							printf("Which bit position to change ? : ");
							scanf("%d", &pos);
							printf("What bit position to set [e.g. 1 or 0]? : ");
							scanf("%d", &value);
							PRINT_HEAD(changeNBit);
							print_binary(changeNBit(data,pos,value),bit_size);
							break;
				case 11:	printf("Enter the value for reversing bits : ");
							scanf("%d", &data);
							printf("1. Fast performer or 2. Slow performer ");
							scanf("%d", &value);
							PRINT_HEAD(reverseBits);
							if (value == 1)
								print_binary(reverseBits(data, bit_size), bit_size);
							else
								print_binary(reverseBits_5Steps(data),bit_size);
							break;
				case 12:	printf("Enter the value for swapping bits : ");
							scanf("%d", &data);
							printf("How many bit position to change ? : ");
							scanf("%d", &pos);
							PRINT_HEAD(swapBits);
							print_binary(swapBits(data, pos), bit_size);
							break;
				case 13:	printf("Enter the register : ");
							scanf("%x", &reg_value);
							printf("Swapped value is : 0x%"PRIx64"\n", payload_swap(reg_value, bit_size));
							break;
				case 14:	printf("Enter the value for swapping bits : ");
							scanf("%d", &data);
							print_binary(data, bit_size);
							printf("Swapped value is : %d\n", swapBitsinPair (data));
							print_binary(swapBitsinPair (data), bit_size);
							break;
				 case 99:	return EXIT_SUCCESS;
				 default:	printf("selected the default option\n");
							break;
			} // switch case
		} //while loop
	return EXIT_SUCCESS;
}
