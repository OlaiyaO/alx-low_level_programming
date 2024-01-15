/*
 * File: 1-isdigit.c
 * Author: Oniya Olaiya
 * Description: This program prints a sign to the consol.
 *		It checks if a number is positive, zero or negative.
 */

/**
 * _isdigit - Entry point of the program.
 *
 * Description: This function is takes a character arguement.
 *
 * @c: The character to be checked.
 * Return: Always 1 if 'c' is a digit and 0 if it is not a digit.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
