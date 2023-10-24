
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
	char *s = "hello";
	char *f;

	f = _strchr(s, 'l');

	if (f != NULL)
	{
		printf("%s\n", f);
	}
	return (0);
}
