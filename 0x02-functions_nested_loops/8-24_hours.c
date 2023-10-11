#include <unistd.h>
#include <ctype.h>
#include "main.h"
/*
 * File: 8-24_hours.c
 * Author: Oniya Olaiya
 * Description: This program prints the hours and minutes of the time of a day
 *		It checks if a number is negative and changes it to positive.
 *
 */


/**
 * jack_bauer - Entry point of the program.
 *
 * Description: This function takes in an integer.
 *
 *
 * Return: This is a void function and it returns nothing
 */

void jack_bauer(void)
{
	int hours = 0;

	while (hours < 24)
	{
		int minutes = 0;

		while (minutes < 60)
		{
			_putchar((hours / 10) + '0');
			_putchar((hours % 10) + '0');
			_putchar(':');
			_putchar((minutes / 10) + '0');
			_putchar((minutes % 10) + '0');
			_putchar('\n');

			minutes++;
		}
		hours++;
	}
}
