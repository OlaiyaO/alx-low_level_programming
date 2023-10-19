/*
 * File: -strncat.c
 * Author: Oniya Olaiya
 */

#include "main.h"
#include <stdio.h>

/**
 * is_separator - checks for a separator withing text.
 *
 * Description: This function capitalizes an array of characters.
 *
 * @c: The character that is checked.
 * Return: It returns 1 if a separator exists and 0 otherwise;
 */

int is_separator(char c)
{
	int i;
	char separators[] = " \t\n,;.!?\"(){}";

	for (i = 0; separators[i] != '\0'; i++)
	{
		if (c == separators[i])
		{
			return (1);
		}
	}
	return (0);
}


/**
 * cap_string - capitalizes the first string after a separator..
 *
 * Description: This function capitalizes an array of characters.
 *
 * @str: The array of characters considered.
 * Return: the address of a character array.
 */
char *cap_string(char *str)
{
	int i;
	int capitalize_next = 1;

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (is_separator(str[i]))
		{
			capitalize_next = 1;
		}
		else if (capitalize_next && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			capitalize_next = 0;
		}
		else
		{
			capitalize_next = 0;
		}
	}
	return (str);
}
