/*
 * File: 6-main.c
 * Author: Oniya Olaiya
 * Description: This program prints an absolute value to the screen.
 *		It takes a number and converts it to it's absolute value..
 */

#include "main.h"

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the __abs function to do the checks.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int r;

	r = _abs(-1);

	_putchar(r + '0');
	_putchar('\n');

	r = _abs(0);

	_putchar(r + '0');
	_putchar('\n');

	r = _abs(1);

	_putchar(r + '0');
	_putchar('\n');

	r = _abs(-98);

	_putchar(r + '0');
	_putchar('\n');

	return (0);
}
