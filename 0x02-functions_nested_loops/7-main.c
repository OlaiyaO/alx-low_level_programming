/*
 * File: 6-main.c
 * Author: Oniya Olaiya
 * Description: This program prints an absolute value to the screen.
 *		It takes a number and converts it to it's absolute value.
 */

#include "main.h"

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_last_digit function to the last digit.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	int r;

	print_last_digit(98);
	print_last_digit(0);

	r = print_last_digit(-1024);

	_putchar('0' + r);
	_putchar('\n');
	return (0);
}
