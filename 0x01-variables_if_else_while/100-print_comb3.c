/*
 * Author: Oniya Olaiya
 * Description: This program prints a message to the console.
 *              it serves as an example of using the .
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *              It prints a message to the console using the
 *              `putchar` function.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;

	while (i <= 9)
	{
		int j = i + 1;

		while (j <= 9)
	{
		putchar('0' + i);
		putchar('0' + j);
		if (i != 8 || j != 9)
		{
			putchar(',');
			putchar(' ');
		}
		j++;
	}
		i++;
	}
	putchar('\n');
	return (0);
}

