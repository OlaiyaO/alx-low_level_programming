#include <unistd.h>
#include <stdio.h>
#include "main.h"
/*
 * File: 9-times_table.c
 * Author: Oniya Olaiya
 * Description: This program prints the 9 times table
 *
 *
 */


/**
 * main - Entry point of the program.
 *
 * Description: This function requires no parameter to print 9 times tabler.
 *
 *
 * Return: This is a void function and it returns nothing
 */


int main(void)
{
	unsigned long int current, next, current_high;
	unsigned long int current_low, next_high, next_low, i, j;

	current = 1;
	next = 2;
	printf("%lu", current);

	for (i = 1; i < 91; i++)
	{
		printf(", %lu", next);
		next = next + current;
		current = next - current;
	}
	current_high = current / 1000000000;
	current_low = current % 1000000000;
	next_high = next / 1000000000;
	next_low = next % 1000000000;

	for (j = 92; j < 99; ++j)
	{
		printf(", %lu", next_high + (next_low / 1000000000));
		printf("%lu", next_low % 1000000000);
		next_high = next_high + current_high;
		current_high = next_high - current_high;
		next_low = next_low + current_low;
		current_low = next_low - current_low;
	}
	printf("\n");
	return (0);
}
