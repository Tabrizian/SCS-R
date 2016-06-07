#ifndef SCS_R_H
#define SCS_R_H

char* overlap(char *str1, char *str2);
bool factor(char *source, char *factor);
bool* make_reverse_factor_free(char **strs, int size);
char* reverse(char *str);
int size_mask(bool *mask, int size);

int greedy_r(char **strs, int size);
#endif
