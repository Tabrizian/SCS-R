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

char* reverse(char *str) {

    int len = strlen(str);
    char* reversal = new char[len];

    for(int i = 0; i < strlen(str); i++) {
        reversal[i] = str[len - i - 1];
    }

    return reversal;
}

bool* make_reverse_factor_free(char **strs, int size) {

    bool *mask = new bool[size];

    for(int i = 0; i < size; i++)
        mask[i] = true;

    for(int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++) {
            if(factor(strs[i], strs[j]) || factor(strs[i], reverse(strs[j])))
                mask[j] = false;
            else if(factor(strs[j], strs[i]) || factor(strs[j], reverse(strs[i])))
                mask[i] = false;
        }
    }

    return mask;
}
