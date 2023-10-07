/*
 * Author: Oniya Olaiya
 * Description: This program prints a message to the console.
 *		it serves as an example of using the
 *		`putchar` function.
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It prints a message to the console using the
 *		`putchar` function.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number = 0;

	while (number < 10)
	{
		putchar('0' + number);
		if (number == 9)
		{
			number++;
		} else
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
