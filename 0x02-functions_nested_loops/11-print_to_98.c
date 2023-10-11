#include <unistd.h>
#include <stdio.h>
#include "main.h"
/*
 * File: 11-print_to_98.c
 * Author: Oniya Olaiya
 * Description: This program prints from a given number to 98.
 *		It checks if a number is negative and changes it to positive.
 *
 */


/**
 * print_to_98 - Entry point of the program.
 *
 * Description: This function takes in an integer.
 * @n: The integer to start printing from.
 *
 * Return: The (0).
 */
void print_to_98(int n)
{
	while (n != 98)
	{
		printf("%d, ", n);
		if (n < 98)
		{
			n++;
		}
		else
		{
			n--;
		}
	}
	printf("%d\n", n);
}
