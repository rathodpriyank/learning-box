/*
 * gnu_functions.h
 *
 *  Created on: Dec 10, 2016
 *      Author: pj
 */

#ifndef GNU_FUNCTIONS_H_
#define GNU_FUNCTIONS_H_

#include <cstddef>  // for size_t
#include <cstdbool> // for bool

#ifdef __cplusplus
extern "C" {
#endif

void* aligned_malloc(size_t required_bytes, size_t alignment);
void aligned_free(void* m);
int freq_finder(const char* string, const char* word);
bool isAlphaBet(const char* string);
void m_strcpy(char* s, const char* d);
int m_strlen(const char* s);
void m_memcpy(void* dest, const void* src, size_t n);
int m_strcmp(const char* src1, const char* src2);

#ifdef __cplusplus
}
#endif

#endif /* GNU_FUNCTIONS_H_ */
