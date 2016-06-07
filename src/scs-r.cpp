#include <cstring>

#include "scs-r.h"

int min(int a, int b) {
    if(a < b)
        return a;
    else
        return b;
}

char* overlap(char *str1, char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);

    char* str_overlap = new char[min(len_str1, len_str2)];

    for(int i = 0; i < min(len_str1, len_str2); i++) {
        if(str1[len_str1 - 1 - i] == str2[i]) {
            str_overlap[i] = str2[i];
        }
    }

    return str_overlap;
}

bool factor(char *source, char *factor) {
    char* pointer = strstr(source, factor);

    return pointer == NULL ? true : false;
}
