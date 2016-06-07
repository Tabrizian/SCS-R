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
        } else {
            str_overlap[i] = '\0' ;
            break;
        }

    }


    return str_overlap;
}

bool factor(char *source, char *factor) {
    char* pointer = strstr(source, factor);

    return pointer == NULL ? false : true;
}

char* reverse(char *str) {

    int len = strlen(str);
    char* reversal = new char[len + 1];

    for(int i = 0; i < strlen(str); i++) {
        reversal[i] = str[len - i - 1];
    }

    reversal[strlen(str)] = '\0';
    return reversal;
}

bool* make_reverse_factor_free(char **strs, int size) {

    bool *mask = new bool[size];

    for(int i = 0; i < size; i++)
        mask[i] = true;

    for(int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++) {
            if(mask[i] && mask[j]) {
                if(factor(strs[i], strs[j]) || factor(strs[i], reverse(strs[j])))
                    mask[j] = false;
                else if(factor(strs[j], strs[i]) || factor(strs[j], reverse(strs[i])))
                    mask[i] = false;
            }
        }
    }

    return mask;
}

int size_mask(bool *mask, int size) {
    int num = 0;
    for(int i = 0; i < size; i++)
        if(mask[i]) num++;
    return num;
}

char* concat(char *str1, char *str2) {
    char *concated = new char[strlen(str1)+ strlen(str2)];

    strcpy(concated, str1);

    int i = 0;
    for(; i < strlen(str2); i++) {
        if(concated[strlen(str1) - 1 - i] != str2[i]) {
            break;
        }
    }

    for(int j = 0; i <= strlen(str2); i++, j++) {
        concated[strlen(str1) + j] = str2[i];
    }

    return concated;
}

int find_max_over_lap(char *str1, char *str2) {

    char *tmp = new char[strlen(str2) + 1];
    strcpy(tmp, str2);
    int str2_len = strlen(str2);
    for (int i = str2_len - 1; i >= 0; --i) {
        tmp[i] = '\0';
        if(strstr(str1, tmp) != NULL)
            return strlen(tmp);
    }

    return 0;
}

int find_max_overlap(bool *mask, char **strs, int size, int *k, int *l) {
    int current_max_overlap = 0;
    for (int i = 1; i < size; ++i) {

        for (int j = 0; j < i; ++j) {


            if(mask[i] && mask[j]) {

                if(find_max_over_lap(strs[i],strs[j]) > current_max_overlap)
                    current_max_overlap = find_max_over_lap(strs[i],strs[j]);
            }

        }
    }
    return current_max_overlap;
}

int greedy_r(char **strs, int size) {
    bool *mask = make_reverse_factor_free(strs, size);

    int k = -1, l = -1;
    while(size_mask(mask, size) > 1) {
        int max = find_max_overlap(mask, strs, size, &k, &l);
        mask[l] = false;
        strs[k] = concat(strs[k], strs[l]);
    }

    if(k == -1) {
        for (int i = 0; i < size; ++i) {
            if(mask[i])
                return i;
        }
    }

    return k;
}
