#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "KMP_Search.h"

char *_KMPfindNext(char *s, const char *substr, const size_t *next);

void generateNext(const char *substr, size_t *next) {
    size_t nextToCompare = 0;
    size_t currentMatchedLen = 0;
    next[0] = 0;

    if (substr[0] == '\0') {
        return;
    }

    nextToCompare = 1;

    while (substr[nextToCompare] != '\0') {
        char expectedNext = substr[currentMatchedLen];
        if (expectedNext == substr[nextToCompare]) {
            next[nextToCompare] = currentMatchedLen + 1;
            nextToCompare++;
            currentMatchedLen++;
        } else {
            if (currentMatchedLen > 0) {
                currentMatchedLen = next[currentMatchedLen - 1];
            } else {
                next[nextToCompare] = 0;
                nextToCompare++;
            }
        }
    }
}

char *KMPfindNext(char *s, const char *substr) {
    size_t substrLen = strlen(substr);
    size_t *next = (size_t *)malloc(substrLen * sizeof(size_t));
    generateNext(substr, next);
    char *ret = _KMPfindNext(s, substr, next);
    free(next);
    return ret;
}

size_t KMPfindAll(const char *s, const char *substr, size_t *indexOfOccurence) {
    size_t substrLen = strlen(substr);
    size_t *next = (size_t *)malloc(substrLen * sizeof(size_t));
    size_t count = 0;
    generateNext(substr, next);
    size_t i = 0;
    size_t j = 0;

    while (s[i] != '\0') {
        if (s[i] == substr[j]) {
            i++;
            j++;
            if (j == substrLen) {
                indexOfOccurence[count] = i - substrLen;
                count++;
                size_t toMove = substrLen - next[substrLen - 1];
                i = i - substrLen + toMove;
                j = 0;
            }
        } else {
            if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
    }

    free(next);
    return count;
}

char *_KMPfindNext(char *s, const char *substr, const size_t *next) {
    size_t i = 0;
    size_t j = 0;
    size_t substrLen = strlen(substr);

    while (s[i] != '\0') {
        if (s[i] == substr[j]) {
            i++;
            j++;
            if (j == substrLen) {
                return &s[i - substrLen];
            }
        } else {
            if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
    }

    return NULL;
}
