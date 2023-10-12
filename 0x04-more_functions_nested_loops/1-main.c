/*
 * File: 1-main.c
 * Author: Oniya Olaiya
 * Description: This program prints 1 or 0 to the consol.
 *		It checks if a character is a digit or not..
 */

#include "main.h"
#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_sign function to do the checks.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c;

	c = '0';

	printf("%c: %d\n", c, _isdigit(c));

	c = 'a';

	printf("%c: %d\n", c, _isdigit(c));
	return (0);
}
