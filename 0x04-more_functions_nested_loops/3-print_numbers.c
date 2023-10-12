/*
 * File: 3-print_numbers.c
 * Author: Oniya Olaiya
 * Description: This program prints integers to the console..
 *
 */
#include "main.h"
/**
 * print_numbers - Entry point of the program.
 *
 * Description: This function takes nothing and returns nothing..
 *
 * Return: Nothing after printing the numbers from 0 - 9.
 */
void print_numbers(void)
{
	int number = 0;

	while (number <= 9)
	{
		_putchar(number + '0');
		number++;
	}
	_putchar('\n');
}
