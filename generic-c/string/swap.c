/*
 ============================================================================
 Name        : string.c
 Author      : Priyank Rathod
 Version     :
 Copyright   : GPLv3
 Description : String functions
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "stringfunc.h"

void swap(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}
