/*
 * gnu_functions.h
 *
 *  Created on: Dec 10, 2016
 *      Author: pj
 */

#ifndef GNU_FUNCTIONS_H_
#define GNU_FUNCTIONS_H_
#include <stdbool.h>
void* aligned_malloc(size_t required_bytes, size_t alignment);
void aligned_free(void *m);
int freq_finder(char *string, char *word);
bool isAlphaBet(char *string);
void m_strcpy(char *s, char *d);
int m_strlen (char *s);
void m_memcpy(void *dest, void *src, size_t n);
int m_strcmp(char *src1, char *src2);

#endif /* GNU_FUNCTIONS_H_ */
