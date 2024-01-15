#include <unistd.h>
#include <ctype.h>
#include "main.h"
/*
 * File: 4-isalpha.c
 * Author: Oniya Olaiya
 * Description: This program prints a message to the consol.
 *		It checks if a character is upper or lower case.
 *
 */


/**
 * _isalpha - Entry point of the program.
 *
 * Description: This function is takes an integer.
 *
 * @c: The character to be checked.
 * Return: Always 1 if 'c' is uppercase, 0 otherwise
 */

int _isalpha(int c)
{
	if (isalpha(c))
	{
		return (1);
	}
	return (0);
}
