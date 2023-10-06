/*
 * File: 5-printf.c
 * Author: Oniya Olaiya
 * Description: This program prints a message to the console
 *		it serves as an example of using the `printf` function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *              It prints a message to the console using the `printf` function.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	printf("Last digit of %d is %d", n, abs(n) % 10);

	if (abs(n) % 10 > 5)
		printf(" and is greater than 5\n");
	else if (abs(n) % 10 == 0)
		printf(" and is 0\n");
	else
		printf(" and is less than 6 and not 0\n");

	return (0);
}

