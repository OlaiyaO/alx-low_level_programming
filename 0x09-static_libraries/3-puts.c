/*
 * File: 2-strlen.c
 * Author: Oniya Olaiya
 * Description: This returns the length of a string passed in.
 *
 */

#include "main.h"
#include <stdio.h>

/**
 * _puts - Function to swap an integerm.
 *
 * Description: This function is the swaps 2 pointers holding.
 *		ineger values..
 * @str: The first integer to be swaped.
 * Return: void (Success)
 */

void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
