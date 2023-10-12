/*
 * File: 5-more_numbers.c
 * Author: Oniya Olaiya
 * Description: This program prints integers to the console.
 *
 */
#include "main.h"
/**
 * more_numbers - Entry point of the program.
 *
 * Description: This function takes nothing and returns nothing.
 *
 * Return: Nothing after printing the numbers from 0 - 14 ten timse..
 */
void more_numbers(void)
{
	int times = 0;

	while (times < 10)
	{
		int number = 0;

		while (number <= 14)
		{
		if (number > 9)
		{
			_putchar((number / 10) + '0');
		}
		_putchar((number % 10) + '0');

		if (number == 14)
		{
			_putchar('\n');
		}
		number++;
		}
		times++;
	}
}
