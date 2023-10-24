
 /*
 * File: 2-main.c
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
	char *f = "oleh";
	unsigned int n;

	n = _strspn(s, f);

	printf("%u\n", n);
	return (0);
}
