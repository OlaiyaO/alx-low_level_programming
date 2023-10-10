/*
 * File: 3-main.c
 * Author: Oniya Olaiya
 * Description: This program prints a message to the consol.
 *		It checks if an alphabet is in lower or upper case..
 */

#include "main.h"

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the _islower function to do the checks.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int r;

	r = _islower('H');
	_putchar(r + '0');
	r = _islower('o');
	_putchar(r + '0');
	r = _islower(108);
	_putchar(r + '0');
	_putchar('\n');
	return (0);
}
