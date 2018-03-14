/*
 * bm.h
 *
 *  Created on: Aug 2, 2016
 *      Author: priyank
 */

#ifndef BM_H_
#define BM_H_

#define PRINT_HEAD(x)  printf("%-20s | ", #x);

#define _64BIT 64
#define _32BIT 32
#define _16BIT 16
#define _8BIT   8

void print_binary(int data, int bits);
void setBitField(uint64_t* reg, int mask, int value, int pos);
unsigned int Flipbit(unsigned int number);
int leftRotateShift(unsigned int n, int d, int s);
int rightRotateShift(unsigned int n, int d, int s);
long intconversion (char buffer[]);
long floatconversion (char buf[]);
int setBit(int d, int e);
int clearBit(int d, int e);
int toggleBit(int d, int e);
int checkBit(int d, int e);
int countSetBits(int val);
int changeNBit(int bit, int pos, int loc);
int reverseBits(int a, int bits);
int reverseBits_5Steps(int n);
int swapBits(int a, int pos);
uint64_t payload_swap(uint64_t p, int bits);
#endif /* BM_H_ */
