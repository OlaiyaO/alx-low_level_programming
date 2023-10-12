/*
 * File: 9-fizz_buzz.c
 * Author: Oniya Olaiya
 * Description: This program prints integers and strings to the console.
 *
 */
#include "main.h"
#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Description: This function takes nothing and returns nothing.
 *
 * Return: Nothing after printing fizz_buzz and numbers.
 */
int main(void)
{
	int fizz_buzz = 1;

	while (fizz_buzz <= 100)
	{
		if (fizz_buzz % 3 == 0)
		{
			printf("Fizz");
		} else if (fizz_buzz % 15 == 0)
		{
			printf("FizzBuzz");
		} else if (fizz_buzz % 5 == 0)
		{
			printf("Buzz");
		} else
		{
			printf("%d", fizz_buzz);
		}
		if (fizz_buzz < 100)
		{
			printf(" ");
		}
		fizz_buzz++;
	}
	printf("\n");
	return (0);
}
