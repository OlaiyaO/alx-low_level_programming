/*
 * File: 2-strlen.c
 * Author: Oniya Olaiya
 * Description: This returns the length of a string passed in.
 *
 */

#include "main.h"
#include <stdio.h>

/**
 * _strlen - Function to swap an integerm.
 *
 * Description: This function is the swaps 2 pointers holding.
 *		ineger values..
 * @s: The first integer to be swaped.
 * Return: void (Success)
 */

int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
