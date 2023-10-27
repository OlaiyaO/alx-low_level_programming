/*
 * File: 1-main.c
 * Author: Oniya Olaiya
 * Description: This program changes the value pointed to by n.
 *
 */

#include "main.h"
#include <stdio.h>

/**
 * _memcpy - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_sign function to do the checks.
 * @n: The number of bytes to fill.
 * @dest: The destination memory location.
 * @src: The source memory location.
 * Return: Always 0 (Success)
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

