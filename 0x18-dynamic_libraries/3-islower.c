#include <unistd.h>
#include <ctype.h>
#include "main.h"
/*
 * File: 3-islower.c
 * Author: Oniya Olaiya
 * Description: This program prints a message to the consol.
 *		It checks if a character is upper or lower case.
 *
 */


/**
 * _islower - Entry point of the program.
 *
 * Description: This function is takes an integer.
 *		It contains nested while loop.
 * @c: The character to be checked.
 * Return: Always 1 if 'c' is lowercase, 0 otherwise
 */

int _islower(int c)
{
	if (islower(c))
	{
		return (1);
	}
	return (0);
}
