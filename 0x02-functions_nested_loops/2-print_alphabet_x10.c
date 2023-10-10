#include <unistd.h>
#include "main.h"
/*
 * File: 2-print_alphabet_x10.c
 * Author: Oniya Olaiya
 * Description: This program prints a message to the consol.
 *		It prints the alphabets in lower case using the `putchar` function.
 *
 */


/**
 * print_alphabet_x10 - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It contains nested while loop.
 *
 * Return: Always 0 (Success)
 */

void print_alphabet_x10(void)
{
	int count = 0;

	while (count < 10)
	{
		char letter = 'a';

		while (letter <= 'z')
		{
			_putchar(letter);
			letter++;
		}
		_putchar('\n');
		count++;
	}
}
