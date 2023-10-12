/*
 * File: 101-print_number.c
 * Author: Oniya Olaiya
 * Description: This program prints integers to the console..
 *
 */
#include "main.h"
/**
 * print_number - Entry point of the program.
 *
 * Description: This function takes an int and returns nothing..
 * @n: The number to be printed.
 * Return: Nothing after printing the number.
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10 != 0)
	{
		print_number(n / 10);
	}
	_putchar((n % 10) + '0');
}
