#include "StringUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[] = "rOCK And sTone!";
    String_toUpper(str);
    puts(str);
    String_toLower(str);
    puts(str);

    char *temp = (char *)malloc(100U * sizeof(char));
    String_center(temp, str, 6, '$');
    puts(temp);
    String_center(temp, str, 21, '$');
    puts(temp);
    String_center(temp, str, 22, '$');
    puts(temp);

    char str2[] = "Rock and stone!";

    if (String_startWith(str2, "Rock")) {
        printf("%d:Success!Rock and stone!\n", 1);

    } else {
        printf("%d:Failed!\n", 2);
    }

    if (!String_startWith(str2, "rock")) {
        printf("%d:Success!Rock and stone!\n", 3);
    } else {
        printf("%d:Failed!\n", 4);
    }

    if (String_startWith(str2, str2)) {
        printf("%d:Success!Rock and stone!\n", 5);
    } else {
        printf("%d:Failed!\n", 6);
    }

    if (!String_startWith(str2, "Rock and stone!XXXXXXXXXXX")) {
        printf("%d:Success!Rock and stone!\n", 7);
    } else {
        printf("%d:Failed!\n", 8);
    }

    if (String_endWith(str2, "stone!")) {
        printf("%d:Success!Rock and stone!\n", 9);
    } else {
        printf("%d:Failed!\n", 10);
    }

    if (!String_startWith(str2, "Stone")) {
        printf("%d:Success!Rock and stone!\n", 11);
    } else {
        printf("%d:Failed!\n", 12);
    }

    if (String_startWith(str2, str2)) {
        printf("%d:Success!Rock and stone!\n", 13);
    } else {
        printf("%d:Failed!\n", 14);
    }

    if (!String_startWith(str2, "XXXXXXXRock and stone!")) {
        printf("%d:Success!Rock and stone!\n", 15);
    } else {
        printf("%d:Failed!\n", 16);
    }

    char str3[] = "   \t Rock and stone!     \t ";
    char buffer[1000] = {0};

    strcpy(buffer, str3);

    String_lstrip(buffer);
    if (strcmp(buffer, "Rock and stone!     \t ") == 0) {
        printf("%d:Success!Rock and stone!\n", 17);
    } else {
        printf("%d:Failed!\n", 18);
    }

    strcpy(buffer, str3);
    String_rstrip(buffer);
    if (strcmp(buffer, "   \t Rock and stone!") == 0) {
        printf("%d:Success!Rock and stone!\n", 19);
    } else {
        printf("%d:Failed!\n", 20);
    }

    strcpy(buffer, str3);
    String_strip(buffer);
    if (strcmp(buffer, "Rock and stone!") == 0) {
        printf("%d:Success!Rock and stone!\n", 21);
    } else {
        printf("%d:Failed!\n", 22);
    }

    strcpy(buffer, "  \t\t  ");
    String_strip(buffer);
    if (strcmp(buffer, "") == 0) {
        printf("%d:Success!Rock and stone!\n", 23);
    } else {
        printf("%d:Failed!\n", 24);
    }

    const char rs[] = "Rock and stone!";

    String_replace(rs, buffer, "stone", "rock", 0);

    printf("%d:%s\n", 25, buffer);

    const char threeRs[] = "Rock and stone!Rock and stone!Rock and stone!";
    String_replace(threeRs, buffer, "stone", "rock", 2);
    printf("%d:%s\n", 26, buffer);

    String_replace(rs, buffer, "xxxxx", "rock", 0);
    printf("%d:%s\n", 27, buffer);

    String_replaceIndex(rs, buffer, "rock", 9, 14);
    printf("%d:%s\n", 28, buffer);

    String_replaceIndex(rs, buffer, "EXPAND$rock$EXPAND", 9, 14);
    printf("%d:%s\n", 29, buffer);

    char skip[] = "A|D|B|C";
    char **result = (char **)malloc(10 * sizeof(char *));
    size_t count = String_split(skip, '|', result, 100);

    for (size_t i = 0; i < count; i++) {
        printf("%d:%s\n", 30, result[i]);
    }

    for (size_t i = 0; i < count; i++) {
        free(result[i]);
    }

    free(result);

    char str4[] = "Rock and stone!\nWe are rich!\nXXXX\n";
    result = (char **)malloc(10 * sizeof(char *));
    count = String_splitLines(str4, result, 100);
    for (size_t i = 0; i < count; i++) {
        printf("%d:%s\n", 31, result[i]);
    }

    for (size_t i = 0; i < count; i++) {
        free(result[i]);
    }

    free(result);

    strcpy(buffer, str4);
    String_truncate(buffer, 6);
    printf("%d:%s\n", 32, buffer);

    strcpy(buffer, rs);
    String_insert(buffer, "XXXXX", 5);
    printf("%d:%s\n", 33, buffer);

    strcpy(buffer, rs);
    String_insertSlice(buffer, "You can do big things with a small team!", 11,
                       21, 5);
    printf("%d:%s\n", 34, buffer);

    strcpy(buffer, rs);
    String_push(buffer, "You can do big things with a small team!");
    String_push(buffer, "Always deliver more than expected!");
    printf("%d:%s\n", 35, buffer);

    String_pushSlice(buffer, "Work hard! Stay determined!", 5, 9);
    printf("%d:%s\n", 36, buffer);
    strcpy(buffer, rs);
    String_remove(buffer, 5, 8);
    printf("%d:%s\n", 37, buffer);
    strcpy(buffer,
           "Worse than failing is to never have tried in the first place!");
    String_removeCharacter(buffer, 'e');
    printf("%d:%s\n", 38, buffer);

    strcpy(buffer, "Dig together - or dig your own grave!");
    String_reverse(buffer);
    printf("%d:%s\n", 39, buffer);

    String_clear(buffer);
    printf("%d:%s\n", 40, buffer);

    String_numberToStr(0, 16, buffer);

    printf("%d:%s\n", 41, buffer);

    String_numberToStr(0xFAAAAFFFF, 16, buffer);
    printf("%d:%s\n", 42, buffer);

    String_numberToStr(926192, 36, buffer);
    printf("%d:%s\n", 43, buffer);

    long long r = strtoll("stone", NULL, 36);

    String_numberToStr(r, 36, buffer);

    printf("%d:%s\n", 44, buffer);

    free(temp);

    return 0;
}
