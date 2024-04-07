#include "StringUtils.h"
#include "KMP/KMP_Search.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

size_t min(size_t a, size_t b);

void String_toUpper(char *str) {
    while (*str != '\0') {
        *str = (char)toupper(*str);
        str++;
    }
}
void String_toLower(char *str) {
    while (*str != '\0') {
        *str = (char)tolower(*str);
        str++;
    }
}
void String_center(char *target, const char *source, size_t width,
                   char fillchar) {
    size_t strLen = strlen(source);
    if (width <= strLen) {
        strcpy(target, source);
    } else {
        size_t pre = (width - strLen) / 2;
        size_t after = width - strLen - pre;
        for (size_t i = 0; i < pre; i++) {
            target[i] = fillchar;
        }
        strcpy(target + pre, source);
        for (size_t i = 0; i < after; i++) {
            target[i + pre + strLen] = fillchar;
        }
        target[width] = '\0';
    }
}
bool String_startWith(const char *str, const char *prefix) {
    while (*str != '\0') {
        if (*prefix == '\0') {
            return true;
        }
        if (*str == *prefix) {
            str++;
            prefix++;
        } else {
            return false;
        }
    }
    if (*prefix == '\0') {
        return true;
    } else {
        return false;
    }
}
bool String_endWith(const char *str, const char *suffix) {
    size_t strLen = strlen(str);
    size_t suffixLen = strlen(suffix);

    if (suffixLen > strLen) {
        return false;
    } else {
        for (size_t i = 0; i < suffixLen; i++) {
            if (str[strLen - suffixLen + i] == suffix[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
}
void String_lstrip(char *str) {
    char *_str = str;
    while (isspace(*str)) {
        str++;
    }
    if (str == _str) {
        return;
    }
    while (*str != '\0') {
        *_str = *str;
        _str++;
        str++;
    }
    *_str = '\0';
}
void String_rstrip(char *str) {
    char *_str = str;
    while (*str != '\0') {
        str++;
    }
    str--;
    while (str != _str) {
        if (!isspace(*str)) {
            break;
        }
        str--;
    }
    *(str + 1) = '\0';
}
void String_strip(char *str) {
    String_rstrip(str);
    String_lstrip(str);
}
size_t String_replace(const char *str, char *target, const char *oldStr,
                      const char *newStr, size_t count) {
    target[0] = '\0';
    size_t *indexOfOccurence =
        (size_t *)malloc(strlen(str) * sizeof(indexOfOccurence));

    size_t matchedCount = KMPfindAll(str, oldStr, indexOfOccurence);
    size_t oldLen = strlen(oldStr);
    size_t toReplace = (count == 0) ? matchedCount : min(matchedCount, count);

    size_t lastEnd = 0;
    for (size_t i = 0; i < toReplace; i++) {
        if (i == 0) {
            String_pushSlice(target, str, 0, indexOfOccurence[i]);
        } else {
            String_pushSlice(target, str, lastEnd, indexOfOccurence[i]);
        }
        String_push(target, newStr);
        lastEnd = indexOfOccurence[i] + oldLen;
    }
    String_pushSlice(target, str, lastEnd, strlen(str));
    free(indexOfOccurence);
    return toReplace;
}

void String_replaceIndex(const char *str, char *target, const char *replaced,
                         size_t i, size_t j) {
    String_clear(target);
    String_pushSlice(target, str, 0, i);
    String_push(target, replaced);
    String_pushSlice(target, str, j, strlen(str));
}
size_t String_split(const char *str, char sep, char **result, size_t maxSplit) {
    size_t count = 0;
    size_t strLen = strlen(str);
    size_t currentLen = 0;

    char *buffer = (char *)malloc((strlen(str) + 1) * sizeof(char));

    for (size_t i = 0; i < strLen; i++) {
        if (count == maxSplit) {
            return maxSplit;
        }
        if (str[i] != sep) {
            buffer[currentLen] = str[i];
            currentLen++;
        } else {
            if (currentLen != 0) {
                buffer[currentLen] = '\0';
                result[count] = (char *)malloc((currentLen + 1) * sizeof(char));
                strcpy(result[count], buffer);
                currentLen = 0;
                count++;
            }
        }
    }

    if (currentLen != 0) {
        buffer[currentLen] = '\0';
        result[count] = (char *)malloc((currentLen + 1) * sizeof(char));
        strcpy(result[count], buffer);
        count++;
    }

    free(buffer);
    return count;
}
size_t String_splitLines(const char *str, char **result, size_t maxSplit) {
    return String_split(str, '\n', result, maxSplit);
}
void String_truncate(char *str, size_t i) { str[i + 1] = '\0'; }
void String_insert(char *target, const char *a, size_t i) {
    String_insertSlice(target, a, 0, strlen(a), i);
}
void String_insertSlice(char *target, const char *a, size_t aBegin, size_t aEnd,
                        size_t i) {
    size_t targetLen = strlen(target);
    size_t aLen = aEnd - aBegin;

    char *back = (char *)malloc((targetLen - i + 1) * sizeof(char));

    strcpy(back, target + i);

    for (size_t j = aBegin; j < aEnd; j++) {
        target[i + j - aBegin] = a[j];
    }

    // \0 included
    for (size_t j = 0; j <= (targetLen - i); j++) {
        target[i + aLen + j] = back[j];
    }

    free(back);
}

void String_push(char *target, const char *a) {
    String_pushSlice(target, a, 0, strlen(a));
}
void String_pushSlice(char *target, const char *a, size_t aBegin, size_t aEnd) {
    while (*target != '\0') {
        target++;
    }

    for (size_t i = aBegin; i < aEnd; i++) {
        *target = a[i];
        target++;
    }
    *target = '\0';
}
void String_remove(char *target, size_t i, size_t j) {
    size_t targetLen = strlen(target);
    char *back = (char *)malloc((targetLen - j + 1) * sizeof(char));
    strcpy(back, target + j);

    // \0 included
    for (size_t k = 0; k < (targetLen - j + 1); k++) {
        target[i + k] = back[k];
    }

    free(back);
}
size_t String_removeCharacter(char *str, char c) {
    char *_str = str;
    char *buffer = (char *)malloc((strlen(str) + 1) * sizeof(char));
    size_t bufferLen = 0;
    size_t count = 0;

    while (*str != '\0') {
        if (*str != c) {
            buffer[bufferLen] = *str;
            bufferLen++;
        } else {
            count++;
        }
        str++;
    }
    buffer[bufferLen] = '\0';
    strcpy(_str, buffer);

    free(buffer);
    return count;
}
void String_reverse(char *str) {
    char temp = 0;
    for (size_t i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void String_clear(char *str) { str[0] = '\0'; }

// from ascii to int, use strtoxx

bool String_numberToStr(long long number, unsigned base, char *target) {
    char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b',
                    'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    if ((base < 2) || (base > 36)) {
        return false;
    }

    bool sign = false;

    if (number == 0) {
        target[0] = table[0];
        target[1] = '\0';
        return true;
    }

    if (number < 0) {
        sign = true;
        number = -number;
    }

    int buffer[64] = {0};
    int len = 0;

    while (number > 0) {
        buffer[len] = (int)(number % base);
        number /= base;
        len++;
    }

    if (sign) {
        target[0] = '-';
        for (int i = 0; i < len; i++) {
            target[len - i] = table[buffer[i]];
        }
        target[len + 1] = '\0';
    } else {
        for (int i = 0; i < len; i++) {
            target[len - i - 1] = table[buffer[i]];
        }
        target[len] = '\0';
    }

    return true;
}

inline size_t min(size_t a, size_t b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
