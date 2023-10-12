/*
 * File: 4-print_numbers.c
 * Author: Oniya Olaiya
 * Description: This program prints integers to the console..
 *
 */
#include "main.h"
/**
 * print_most_numbers - Entry point of the program.
 *
 * Description: This function takes nothing and returns nothing..
 *
 * Return: Nothing after printing the numbers from 0 - 9 except 2 and 4.
 */
void print_most_numbers(void)
{
	int number = 0;

	while (number <= 9)
	{
		if (number != 2 && number != 4)
		{
			_putchar(number + '0');
		}
		number++;
	}
	_putchar('\n');
}
