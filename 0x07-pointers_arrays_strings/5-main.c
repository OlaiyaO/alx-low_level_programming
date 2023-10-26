
 /*
 * File: 5-main.c
 * Author: Oniya Olaiya
 */

#include "main.h"
#include <stdio.h>

/**
 * main - prints buffer in hexa
 *
 * Return: Nothing.
 */
int main(void)
{
	char *s = "hello, world";
	char *f = "world";
	char *t;

	t = _strstr(s, f);
	printf("%s\n", t);
	return (0);
}
