#ifndef MAIN_H
#define MAIN_H

/**
 * _putchar - Writes a character to stdout
 * this file contains all the function prototype for the directory.
 * @c: The character to be written
 *
 */

int _putchar(char c);

char *create_array(unsigned int size, char c);

char *_strdup(char *str);

char *str_concat(char *s1, char *s2);

int **alloc_grid(int width, int height);

void free_grid(int **grid, int height);
#endif
