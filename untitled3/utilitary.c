#include "utilitary.h"

int charCount(char* str1,char* str2) {
    int count = 0;
    int index = 0;
    while (str1[index] != '\0' && str2[index] != '\0' && str1[index] == str2[index]) {
        if (str1[index] == str2[index]) {
            count++;
        }
        index++;
    }
    if (count > 3) count = 3;
    return count;
}



int compareStr(char* str1,char* str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }

        if (*str1 <= *str2) {
            return 0;
        } else {
            return 1; // str1 is greater than str2
        }
    }

