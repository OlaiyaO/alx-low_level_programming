/*
 * File: 100-largest_prime.c
 * Author: Oniya Olaiya
 * Description: This program prints the lrgest prime of 612852475143..
 *
 */

#include <stdio.h>
#include <math.h>

/**
 * main - Entry point of the program.
 *
 * Description: This function takes nothing and returns nothing.
 *
 * Return: Nothing after printing fizz_buzz and numbers.
 */
int main(void)
{
	long num = 612852475143;
	long largest_prime = -1;

	long i = 3;

	while (num % 2 == 0)
	{
		largest_prime = 2;
		num /= 2;
	}

	while (i <= sqrt(num))
	{
		while (num % i == 0)
		{
			largest_prime = i;
			num /= i;
		}
		i += 2;
	}
	if (num > 2)
	{
		largest_prime = num;
	}

	printf("%ld\n", largest_prime);
	return (0);
}
