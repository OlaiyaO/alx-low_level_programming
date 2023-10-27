/*
 * File: 0-main.c
 * Author: Oniya Olaiya
 * Description: This program changes the value pointed to by n.
 *
 */

#include "main.h"
#include <stdio.h>

/**
 * _memset - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_sign function to do the checks.
 * @n: The number of bytes to fill.
 * @b: Constant byte to fill bytes with.
 * @s: The pointer to the memory location.
 * Return: Always 0 (Success)
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	while (n > 0)
	{
		*ptr = b;
		ptr++;
		n--;
	}
	return (s);
}

