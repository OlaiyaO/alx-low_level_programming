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
	unsigned int positive_number = n;

	if (n < 0)
	{
		_putchar('-');
		positive_number = -positive_number;
	}

	if (positive_number / 10 != 0)
	{
		print_number(positive_number / 10);
	}
	_putchar((positive_number % 10) + '0');
}
