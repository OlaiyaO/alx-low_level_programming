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
	long int a = 1, b = 2, next;
	int count = 0;

	while (count < 50)
	{
		if (count == 49)
		{
			printf("%ld\n", a);
		}
		else
		{
			printf("%ld, ", a);
		}
		next = a + b;
		a = b;
		b = next;
		count++;
	}
	return (0);
}
