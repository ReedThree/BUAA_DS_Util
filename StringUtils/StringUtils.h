#ifndef __STRING_UTILS_H
#define __STRING_UTILS_H

#include <stdbool.h>
#include <stddef.h>

void String_toUpper(char *str);
void String_toLower(char *str);
void String_center(char *target, const char *source, size_t width,
                   char fillchar);
bool String_startWith(const char *str, const char *prefix);
bool String_endWith(const char *str, const char *suffix);
void String_lstrip(char *str);
void String_rstrip(char *str);
void String_strip(char *str);
// set count to 0 to replace all
size_t String_replace(const char *str, char *target, const char *oldStr,
                      const char *newStr, size_t count);
void String_replaceIndex(const char *str, char *target, const char *replaced,
                         size_t i, size_t j);
// Not need to alloc for result[i] before call, manual free of result[i] is
// required!
size_t String_split(const char *str, char sep, char **result, size_t maxSplit);
// Not need to alloc for result[i] before call, manual free of result[i] is
// required!
size_t String_splitLines(const char *str, char **result, size_t maxSplit);
// [str[0], str[6]] will be preserved.
void String_truncate(char *str, size_t i);
// Make sure target has enough space! target[i] will be a[0]
void String_insert(char *target, const char *a, size_t i);
// Make sure target has enough space!
void String_insertSlice(char *target, const char *a, size_t aBegin, size_t aEnd,
                        size_t i);
// Make sure target has enough space!
void String_push(char *target, const char *a);
// Make sure target has enough space!
void String_pushSlice(char *target, const char *a, size_t aBegin, size_t aEnd);
void String_remove(char *target, size_t i, size_t j);
// return counts of c
size_t String_removeCharacter(char *str, char c);
void String_reverse(char *str);

void String_clear(char *str);
// 全进制转换
bool String_numberToStr(long long number, unsigned base, char *target);
#endif
