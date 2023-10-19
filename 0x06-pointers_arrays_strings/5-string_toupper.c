/*
 * File: -strncat.c
 * Author: Oniya Olaiya
 */

#include "main.h"
#include <stdio.h>

/**
 * string_toupper - capitalizes an array of characters
 *
 * Description: This function capitalizes an array of characters.
 *
 * @str: The array of characters.
 * Return: It returns nothing;
 */

char *string_toupper(char *str)
{
	int i;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	}
	return (str);
}
