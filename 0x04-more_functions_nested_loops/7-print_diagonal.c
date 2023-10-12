/*
 * File: 7-print_diagonal.c
 * Author: Oniya Olaiya
 * Description: This program prints integers to the console.
 *
 */
#include "main.h"
/**
 * print_diagonal - Entry point of the program.
 *
 * Description: This function takes nothing and returns nothing.
 * @n: Number of times '\' character is printed
 * Return: Nothing after printing 'n' numbers of underscore..
 */
void print_diagonal(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	} else
	{
		int backslash = 0;

		while (backslash < n)
		{
			int spaces = 0;

			while (spaces < backslash)
			{
				_putchar(' ');
				spaces++;
			}
			_putchar('\\');
			_putchar('\n');
			backslash++;
		}
	}
}
