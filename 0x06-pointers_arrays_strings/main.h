#ifndef MAIN_H
#define MAIN_H

/**
 * _putchar - Writes a character to stdout
 * this file contains all the function prototype for the directory.
 * @c: The character to be written
 *
 */

void _putchar(char c);

char *_strcat(char *dest, char *src);

char *_strncat(char *dest, char *src, int n);

char *_strncpy(char *dest, char *src, int n);

int _strcmp(char *s1, char *s2);

void reverse_array(int *a, int n);

char *string_toupper(char *);

char *cap_string(char *);

char *leet(char *);

char *rot13(char *str);
#endif
