#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>

int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int is_positive_integer(char *str);
int *initialize_result(int len_result);
void perform_multiplication(char *num1, char *num2, int *result, int len1, int len2);
char *create_result_string(int *result, int len_result, int leading_zeros);
char *multiply(char *num1, char *num2);
int main(int argc, char *argv[]);
#endif /* MAIN_H */

