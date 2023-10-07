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
	int j;

	while (i < 100)
	{
		j = i + 1;

		while (j < 100)
		{
			putchar((i / 10) + '0');
			putchar((i % 10) + '0');
			putchar(' ');
			putchar((j / 10) + '0');
			putchar((j % 10) + '0');

			if (i != 98 || j != 99)
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

