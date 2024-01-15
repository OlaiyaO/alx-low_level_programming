/*
 * File: 1-main.c
 * Author: Oniya Olaiya
 * Description: This program changes the value pointed to by n.
 *
 */

#include "main.h"
#include <stdio.h>

/**
 * _strchr - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_sign function to do the checks.
 * @s: The destination memory location.
 * @c: The source memory location.
 * Return: Always 0 (Success)
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	if (c == '\0')
	{
		return (s);
	}
	return (NULL);
}

