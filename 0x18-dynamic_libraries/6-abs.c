#include <unistd.h>
#include <ctype.h>
#include "main.h"
/*
 * File: 6-abs.c
 * Author: Oniya Olaiya
 * Description: This program prints a positive integer on the console.
 *		It checks if a number is negative and changes it to positive.
 *
 */


/**
 * _abs - Entry point of the program.
 *
 * Description: This function is takes an integer.
 *
 * @n: The character to be checked.
 * Return: Always 0 on success.
 */

int _abs(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
	return (0);
}
