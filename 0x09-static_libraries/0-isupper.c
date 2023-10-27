/*
 * File: 0-isupper.c
 * Author: Oniya Olaiya
 * Description: This program prints a either 1 or 0 to the console.
 *		It checks if a letter is in upper or lower case.
 *
 */


/**
 * _isupper - Entry point of the program.
 *
 * Description: This function is takes an integer.
 *
 * @c: The character to be checked.
 * Return: Always 1 if c is in lower case and 0 if in upper case.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}
