/*
 * File: 8-print_square.c
 * Author: Oniya Olaiya
 * Description: This program prints integers to the console.
 *
 */
#include "main.h"
/**
 * print_square - Entry point of the program.
 *
 * Description: This function takes nothing and returns nothing.
 * @n: Number of times '#' character is printed
 * Return: Nothing after printing 'n' numbers of squares.
 */
void print_square(int n)
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
				_putchar('#');
				hash++;
			}
			_putchar('\n');
			times++;
		}
	}
}
