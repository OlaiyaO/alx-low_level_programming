/*
 * File: 1-main.c
 * Author: Oniya Olaiya
 * Description: This program changes the value pointed to by n.
 *
 */

#include "main.h"
#include <stdio.h>

/**
 * _strpbrk - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_sign function to do the checks.
 * @s: The destination memory location.
 * @accept: The source memory location.
 * Return: Always 0 (Success)
 */

char *_strpbrk(char *s, char *accept)
{
	char *a = accept;
	
	if (*s == '\0')
		return (NULL);
	
	while (*a)
	{
		if (*s == *a)
			return (s);
		a++;
	}
	return (_strpbrk(s + 1, accept));
}
