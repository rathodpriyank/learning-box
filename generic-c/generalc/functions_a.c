/*
 * functions.c
 *
 *  Created on: May 10, 2016
 *      Author: Priyank
 */
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

void A1() {             /* print the integers from 0 to 14, one per line */
        printf("%s\n",__func__);
        int i = 0;
        for (i = 0; i < 15; i++)
                printf("%d\n", i);
}

void A2() {             /* print the integers from 1 to 15, one per line */
        printf("%s\n",__func__);
        int i = 0;
        for (i = 0; i < 16; i++)
                printf("%d\n", i);
}

void A3() {             /* print the integers 0, 2, 4, ... , 20 one per line */
        printf("%s\n",__func__);
        int i = 0;
        for (i = 0; i < 21; i+=2)
                printf("%d\n", i);
}

void A4() {             /* print the integers from -7 to +7, one per line */
        printf("%s\n",__func__);
        int i = 0;
        for (i = -7; i < 8; i++)
                printf("%d\n", i);
}

void A5() {             /* print the integers from 15 down to 0, one per line */
        printf("%s\n",__func__);
        int i = 15;
        for (i = 15; i >= 0; i--)
                printf("%d\n", i);
}

void A6() {             /* print the ODD integers from 1 to 99, one per line */
        printf("%s\n",__func__);
        int i = 0;
        for (i = 1; i <= 99; i+=2)
                printf("%d\n", i);
}

void A7() {             /* print the first N odd integers. Ask the user for N. */
        printf("%s\n",__func__);
        int number = 7;
        int i = 1;
        for (i = 1; i < number+1; i+=2)
        {
                printf("%d\n", i);
                number++;
        }
}

void A8() {             /*  add up even, odd and all integers from 0 to N */
        printf("%s\n",__func__);
        int i = 0;
        int number = 10;
        int sumAll = 0;
        int sumOdd = 0;
        int sumEven = 0;
        for (i = 0; i <= number; i++)
        {
                if ((i%2) == 0)
                {
                        sumEven += i;
                }
                else if ((i%2) == 1)
                {
                        sumOdd += i;
                }
                sumAll += i;
        }
        printf("Sum = %d, Sum of Odd = %d, Sum of Even = %d\n", sumAll, sumOdd, sumEven);
}

void A9() {             /* add up even, odd and all integers from 0 to N, except those integers divisible by 3 or 4 */
        printf("%s\n",__func__);
        int i = 0;
        int number = 10;
        int sumAll = 0;
        int sumOdd = 0;
        int sumEven = 0;
        for (i = 0; i <= number; i++)
        {
                if ((i%3) == 0 || (i%4) == 0)
                        continue;
                if ((i%2) == 0)
                {
                        sumEven += i;
                }
                else if ((i%2) == 1)
                {
                        sumOdd += i;
                }
                sumAll += i;
        }
        printf("Sum = %d, Sum of Odd = %d, Sum of Even = %d\n", sumAll, sumOdd, sumEven);
}

void A10() {    /* print the integers from 0 to 24, five per line */
        printf("%s\n",__func__);
        int i = 0;
        int j = 0;
        int count = 0;
        for(i = 0; i < 5; i++)
        {
                for (j = 0; j < 5; j++)
                {
                        printf("%4d", count);
                        count++;
                }
                printf("\n");
        }
}

void A11() {    /* print the ODD integers from 1 to N, five per line */
        printf("%s\n",__func__);
        int i = 0;
        int j = 0;
        int count = 1;
        int N = 53;
        for(i = 1; i <= N; i++)
        {
                for(j = 0; j < 5; j++)
                {
                        printf("%4d", count);
                        if (N == count)
                        {
                                printf("\n");
                                return;
                        }
                        count+=2;
                }
                printf("\n");
        }
}

void A12() {    /* print the ODD integers from start down to finish, seven per line */
        printf("%s\n",__func__);
        int i = 0;
        int start = 147;
        int finish = 59;
        int count = 0;
        for (i = start; i >= finish; i-=2)
        {
                printf("%4d ", i);
                if ( count%7 == 6 )
                        printf("\n");
                count++;
        }
        if (count%7 != 0)
                printf("\n");
}
void A13() { /* print integers from 1 to 100 that are not multiples of 3 or 5 */
        printf("%s\n",__func__);
          int j;
          int count = 0;
          int n = 100;

          for (j=1; j<=n; j++ )
          {
            if ( !(j%3 == 0 || j%5 == 0 ) )
            {
              printf("%3d", j);
              if ( count%10==9 )
                  printf("\n");
              count++ ;
            }
          }
          if ( count%10 != 9 )
                  printf("\n");
}

void A14() { /* on each line k print all the integers in the range 100*k to (100*k+99) that are multiples of 23. */
        printf("%s\n",__func__);
          int j;     /* the current integer */
          int k;     /* the current line number */
          int line;  /* the line the current integer belongs on */

          int maxLine = 11 ; /* number of lines to print */

          k = 0;

          /* generate multiples of 23 */
          for ( j=0; j<= maxLine*100+99; j+=23 )
          {
            /* find the line number using integer division */
            line = j/100 ;

            /* does the number belong on the current line? */
            if ( line == k+1 )
            {
              printf("\n%5d ", j);
              k++ ;
            }
            else
              printf("%5d ", j );
          }
          printf("\n");
}

void A15() { /*  For each integer N from 1 to 100 compute and print the sum 1+2+...+N */
        printf("%s\n",__func__);
        int N = 100;   /* line number */
        int sum=0;     /* Sum */
        int j;         /* values 1..100 to add to the sum */

        printf( "N \t Sum\n");
        for (j=1; j<=N; j++)
        {
        sum += j;
        printf("%d \t %d\n", j, sum );
          }
}

void A16() { /*  print N by M block of stars */
        printf("%s\n",__func__);
        int row = 7;
        int col = 21;
        int i = 0;
        int j = 0;
        for (i = 0; i < row; i++)
        {
                for(j = 0; j < col; j++)
                {
                        printf("*");
                }
                printf("\n");
        }
}

void A17() { /* print a diagonal line of stars */
        printf("%s\n",__func__);
        int i = 0;
        int j = 0;
        int n = 15;
        for(i = 0; i < n; i++ )
        {
                for(j = 0; j < i; j++)
                {
                        printf(".");
                }
                printf("*\n");
        }
}
void A18() { /* Write a main() program that prints a wedge of stars. Print n stars in row 0,
                         (n-1) stars in row 1, (n-2) stars in row 2, and so on. Here is what this looks like: */
        printf("%s\n",__func__);
        int i = 0, j = 0, n = 17;
        for(i = 0; i < n; i++)
        {
                for(j = 0; j < n-i; j++)
                {
                        printf("*");
                }
                printf("\n");
        }
}

void A19() { /* Write a main() program that prints a wedge of stars. Print n stars in row 0,
                        (n-1) stars in row 1, (n-2) stars in row 2, and so on. But now, pad the left side of
                        each line with spaces so that each line consists of n characters. Here is what this looks like: */
        printf("%s\n",__func__);
        int i, j;
        int n = 15;
        for(i = 0; i < n; i++)
        {
                for(j = 0; j < i; j++)
                        printf(" ");
                for(; j < n; j++)
                        printf("*");
                printf("\n");
        }
}

void A20() {    /* print a triange of stars, one star in the first row, three on the second . . . for 12 rows */
        printf("%s\n",__func__);
        int i, row, space, stars;
        int n = 12;
        for(row = 0; row < n; row++)
        {
                stars = 2*row + 1;
                space = (2*n-1-stars)/2;
                for(i = 0; i < space; i++)
                        printf(".");
                for(i = 0; i < stars; i++)
                        printf("*");
                for(i = 0; i < space; i++)
                        printf(".");
                printf("\n");
        }
        printf("\n");
}

void A21() {            /* print a pine tree of stars */
        printf("%s\n",__func__);
        int i, row, space, stars;
        int n = 12;
        for(row = 0; row < n; row++)
        {
                stars = 2*row + 1;
                space = (2*n-1-stars)/2;
                for(i = 0; i < space; i++)
                        printf(".");
                for(i = 0; i < stars; i++)
                        printf("*");
                for(i = 0; i < space; i++)
                        printf(".");
                printf("\n");
        }
          stars = 2*(n/8)+1;
          space = (2*n-1-stars)/2;
          for ( row=0; row<n/3; row++ )
          {
            for ( i=0; i<space; i++ )
              printf(".");
            for ( i=0; i<stars; i++ )
              printf("*");
            for ( i=0; i<space; i++ )
              printf(".");
            printf("\n");
          }
        printf("\n");
}

void A22() { }
void A23() { }
void A24() { }
void A25() { }
void A26() { }
void A27() { }
void A28() { }
void A29() { }
void A30() { }
void A31() { /* function to print a line of N stars */
        printf("%s\n",__func__);
        int i = 0;
        int n = 10;
        for(i = 0; i < n; i++)
                printf("*");
        printf("\n");
}
void A32() { /* Write center(char ch, int count, int length)
                        which prints count number of characters in the center of a line of length characters.
                         Make the other characters of the line blank (or dot, for debugging purposes.)
                         Here is the output for center('*', 5, 13) */
        printf("%s\n",__func__);
        int i = 0;
        int l = 13;
        int c = 5;
        for(i = 0; i < l/3; i++)
                printf(".");
        for(i = 0; i < c; i++)
                printf("*");
        for(i = 0; i < l/3; i++)
                printf(".");
        printf("\n");
}

void A33() { /* Write a function that prints a block of R rows of C stars. If R is 5 and C is 7 the function prints: */
        printf("%s\n",__func__);
        int i = 0;
        int j = 0;
        int R = 5;
        int C = 7;
        for(i = 0; i < R; i++)
        {
                for(j = 0; j < C; j++)
                        printf("*");
                printf("\n");
        }
        printf("\n");
}
void A34() {
        printf("%s\n",__func__);
}

void A35() { }
void A36() { }
void A37() { }
void A38() { }
void A39() { }
void A40() { }
