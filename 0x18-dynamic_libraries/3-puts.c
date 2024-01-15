#include "main.h"
#include <stdio.h>

/**
 * _puts - Function to swap an integerm.
 *
 * Description: This function is the swaps 2 pointers holding.
 *		ineger values..
 * @s: The first integer to be swaped.
 * Return: void (Success)
 */

void _puts(char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}
	_putchar('\n');
}
