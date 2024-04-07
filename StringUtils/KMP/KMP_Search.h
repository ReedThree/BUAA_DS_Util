#ifndef __KMP_SEARCH_H
#define __KMP_SEARCH_H

#include <stddef.h>

void generateNext(const char *substr, size_t *next);
char *KMPfindNext(char *s, const char *substr);
size_t KMPfindAll(const char *s, const char *substr, size_t *indexOfOccurence);
#endif
