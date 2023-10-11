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
 * times_table - Entry point of the program.
 *
 * Description: This function requires no parameter to print 9 times tabler.
 *
 *
 * Return: This is a void function and it returns nothing
 */
void times_table(void)
{
	int row = 0;

	while (row <= 9)
	{
		int column = 0;

		while (column <= 9)
		{
			int product = row * column;

			if (column > 0)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (product < 10)
			{
				_putchar(' ');
			} else
			{
				_putchar((product / 10) + '0');
			}
			_putchar((product % 10) + '0');

			column++;
		}
		_putchar('\n');
		row++;
	}
}
