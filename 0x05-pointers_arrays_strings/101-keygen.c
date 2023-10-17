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
	int sum = 0;
	int n;

	srand(time(NULL));

	while (sum < 2772 - 122)
	{
		n = rand() % 122 + 1;
		putchar(n);
		sum += n;
	}
	n = 2772 - sum;
	putchar(n);
	return (0);
}
