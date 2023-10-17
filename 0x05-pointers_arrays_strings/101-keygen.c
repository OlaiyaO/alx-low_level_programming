/*
 * File: 100-main.c
 * Author: Oniya Olaiya
 * Description: This program prints the result of _atoid.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_sign function to do the checks.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int password[100];
	int i, sum, n;

	sum = 0;

	srand(time(NULL));

	for (i = 0; i < 100; i++)
	{
		password[i] = rand() % 78;
		sum += (password[i] + '@');

		if ((2772 - sum) < 78)
		{
			n = 2772 - sum - 32;
			sum += n;
			putchar(n + 32);

		}
	}
	return (0);
}
