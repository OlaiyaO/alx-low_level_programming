/*
 * File: 2-strncat.c
 * Author: Oniya Olaiya
 */

#include "main.h"
#include <stdio.h>

/**
 * _strcmp- Concatenates tw strings.
 *
 * Description: This function is the entry point for the program.
 *
 * @s1: The first string to be compare..
 * @s2: The Second string to be compared.
 * Return: A pointer to the resulting string 'dest'
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 < *s2)
		return (-1);
	else if (*s1 > *s2)
		return (1);
	return (0);
}
