/*
 * File: 100-main.c
 * Author: Oniya Olaiya
 * Description: This program prints the result of _atoid.
 */

#include "main.h"
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
	int i;

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		char random_char = rand() % 93 + 33;

		_putchar(random_char);
	}
	_putchar('\n');
	return (0);
}
