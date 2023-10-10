#include <unistd.h>
#include <ctype.h>
#include "main.h"
/*
 * File: 5-sign.c
 * Author: Oniya Olaiya
 * Description: This program prints a sign to the consol.
 *		It checks if a number is positive, zero or negative..
 *
 */


/**
 * print_sign - Entry point of the program.
 *
 * Description: This function is takes an integer.
 *
 * @n: The character to be checked.
 * Return: Always 1 if 'n' is positive, 0 equal to zero and -1 if negative.
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	} else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	_putchar('-');
	return (-1);
	return (0);
}
