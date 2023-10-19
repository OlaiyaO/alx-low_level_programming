/*
 * File: -strncat.c
 * Author: Oniya Olaiya
 */

#include "main.h"
#include <stdio.h>

/**
 * print_number - prints a number to the console.
 *
 * Description: This function capitalizes an array of characters.
 *
 * @n: The number that is printed.
 * Return: nothing.
 */

void print_number(int n)
{
	unsigned int absoluteValue, digit, divisor;

	if (n < 0)
	{
		_putchar('-');
		absoluteValue = -n;
	}

	else
	{
		absoluteValue = n;
	}

	digit = absoluteValue;
	divisor = 1;

	while (digit > 9)
	{
		digit /= 10;
		divisor *= 10;
	}

	while (divisor >= 1)
	{
		_putchar(((absoluteValue / divisor) % 10) + '0');
		divisor /= 10;
	}
}
