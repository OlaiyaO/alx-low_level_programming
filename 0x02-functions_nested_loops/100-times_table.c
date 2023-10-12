#include <unistd.h>
#include <ctype.h>
#include "main.h"
/*
 * File: 9-times_table.c
 * Author: Oniya Olaiya
 * Description: This program prints the 9 times table
 *
 *
 */


/**
 * print_times_table - Entry point of the program.
 *
 * Description: This function requires no parameter to print 9 times tabler.
 * @n: The n'th times table
 *
 * Return: This is a void function and it returns nothing
 */
void print_times_table(int n)
{
	int row = 0;

	if (n < 0 || n > 15)
		return;
	while (row <= n)
	{
		int column = 1;

		_putchar('0');

		while (column <= n)
		{
			int result = row * column;

			_putchar(',');
			_putchar(' ');

			if (result < 100)
				_putchar(' ');
			if (result < 10)
				_putchar(' ');

			if (result > 9 && result < 100)
			{
				_putchar((result / 10) + '0');
			}
			else if (result > 99)
			{
				_putchar((result/ 100) + '0');
				_putchar(((result / 10)) % 10 + '0');

			}
			column++;
		}
		_putchar('\n');
		row++;
	}
}
