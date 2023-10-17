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

	for (count = 1; count <= 98; count++)
	{
		if (count == 1)
		{
			printf("%ld, %lu", a, b);
		}
		else
		{
			next = a + b;
			printf(", %lu", next);
			a = b;
			b = next;
		}
	}
	printf("/n");
	return (0);
}
