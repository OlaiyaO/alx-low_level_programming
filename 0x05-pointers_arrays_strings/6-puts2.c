/*
 * File: 2-strlen.c
 * Author: Oniya Olaiya
 * Description: This returns the length of a string passed in.
 *
 */

#include "main.h"
#include <stdio.h>

/**
 * puts2 - Function to swap an integerm.
 *
 * Description: This function is the swaps 2 pointers holding.
 *		ineger values..
 * @str: The first integer to be swaped.
 * Return: void (Success)
 */

void puts2(char *str)
{
	int i = 0;
	int j;

	while (str[i] != '\0')
	{
		i++;
	}

	for (j = 0; j < i; j += 2)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
