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
	int i = 0;

	if (n < 0 || n > 15)
		return;
	while (i <= n)
	{
		int j = 0;

		while (j <= n)
		{
			int result = i * j;

			if (j != 0)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (result < 10)
			{
				_putchar(' ');
				_putchar(' ');
				_putchar(' ');
				_putchar(result + '0');
			} else if (result < 100)
			{
				_putchar(' ');
				_putchar(' ');
				_putchar((result / 10) + '0');
				_putchar((result % 10) + '0');
			} else
			{
				_putchar((result / 100) + '0');
				_putchar(((result / 10) % 10) + '0');
				_putchar((result % 10) + '0');
			}
			j++;
		}
		_putchar('\n');
		i++;
	}
}
