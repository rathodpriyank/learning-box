/*
 * functions.c
 *
 *  Created on: May 11, 2016
 *      Author: Priyank
 */
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

void C01() {  /* print each element in an array of ints, one per line */
        printf("%s\n", __func__);
        int x[] = {0, 9, 23, -6, 5, 2, 71, 45, -9, 3 };
        int length = sizeof(x)/sizeof(x[0]);
        int i = 0;
        printf("index\tvalue\n");
        printf("-----\t -----\n");
        for(i = 0; i < length; i++)
                printf("%4d:\t%4d \n", i, x[i]);
}

void C02() {    /* print each element in an array of ints, 10 elements per line. */
        printf("%s\n", __func__);
        int x[] = { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
                         11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                         21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                         31, 32, 33, 34, 35, 36, 37, 38, 39, 40 };
        int length = sizeof(x)/sizeof(x[0]);
        int i = 0;
        printf("index\tvalue\n");
        printf("-----\t -----\n");
        for(i = 0; i < length+1; i++)
        {
                printf("%4d", x[i]);
                if (i%10 == 9)
                        printf("\n");
        }
}

void C03() { }

void C04() { }

void C05() { }

void C06() { }

void C07() { }

void C08() { }

void C09() { }

void C10() { }
