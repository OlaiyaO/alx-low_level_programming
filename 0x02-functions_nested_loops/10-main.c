/*
 * File: 10-main.c
 * Author: Oniya Olaiya
 * Description: This program prints the sum of two numbers.
 *
 */

#include "main.h"

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the times_table function .
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	int n;

	n = add(89, 9);
	_putchar('0' + n);
	_putchar('\n');
	return (0);
}
