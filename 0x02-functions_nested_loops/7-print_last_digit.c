#include <unistd.h>
#include <ctype.h>
#include "main.h"
/*
 * File: 7-print_last_digit.c
 * Author: Oniya Olaiya
 * Description: This program prints the last digit of number suppled to it..
 *		It checks if a number is negative and changes it to positive.
 *
 */


/**
 * print_last_digit - Entry point of the program.
 *
 * Description: This function takes in an integer.
 *
 * @n: The character to be checked.
 * Return: Always returns the last_digit on success.
 */

int print_last_digit(int n)
{
	int last_digit = n % 10;

	if (last_digit < 0)
	{
		last_digit *= -1;
	}
	_putchar('0' + last_digit);
	return (last_digit);
}
