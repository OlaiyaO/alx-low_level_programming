/*
 * File: -strncat.c
 * Author: Oniya Olaiya
 */

#include "main.h"
#include <stdio.h>

/**
 * leet - capitalizes the first string after a separator..
 *
 * Description: This function capitalizes an array of characters.
 *
 * @str: The array of characters considered.
 * Return: the address of a character array.
 */

char *leet(char *str)
{
	int i;
	int j;
	char leet_dict[] = "aAeEoOtTlL";
	char leet_values[] = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; leet_dict[j] != '\0'; j++)
		{
			if (str[i] == leet_dict[j])
			{
				str[i] = leet_values[j];
				break;
			}
		}
	}
	return (str);
}

