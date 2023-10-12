/*
 * File: 10-print_triangle.c
 * Author: Oniya Olaiya
 * Description: This program prints triangle with hash and space..
 *
 */
#include "main.h"
/**
 * print_triangle - Entry point of the program.
 *
 * Description: This function takes nothing and returns nothing.
 * @n: Number of times '#' character is printed
 * Return: Nothing after printing 'n' numbers of squares.
 */
void print_triangle(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	} else
	{
		int times = 0;

		while (times < n)
		{
			int hash = 0;

			while (hash < n)
			{
				if (hash < n - times - 1)
				{
					_putchar(' ');
				} else
				{
				_putchar('#');
				}
				hash++;
			}
			_putchar('\n');
			times++;
		}
	}
}
