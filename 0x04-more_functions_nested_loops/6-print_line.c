/*
 * File: 6-print_line.c
 * Author: Oniya Olaiya
 * Description: This program prints integers to the console.
 *
 */
#include "main.h"
/**
 * print_line - Entry point of the program.
 *
 * Description: This function takes nothing and returns nothing.
 * @n: Number of times '_' character is printed
 * Return: Nothing after printing 'n' numbers of underscore..
 */
void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	} else
	{
		int underscore = 0;

		while (underscore < n)
		{
			_putchar('_');
			underscore++;
		}
		_putchar('\n');
	}
}
