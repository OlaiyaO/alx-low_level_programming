/*
 * File: 2-strlen.c
 * Author: Oniya Olaiya
 * Description: This returns the length of a string passed in.
 *
 */

#include "main.h"
#include <stdio.h>

/**
 * rev_string - Function to swap an integerm.
 *
 * Description: This function is the swaps 2 pointers holding.
 *		ineger values..
 * @s: The first integer to be swaped.
 * Return: void (Success)
 */

void rev_string(char *s)
{
	int i = 0;
	int j = 0;
	char temp;

	while (s[i] != '\0')
	{
		i++;
	}

	i--;

	while (i > j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i--;
		j++;
	}
}
