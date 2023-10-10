/*
 * File: 4-puts.c
 * Author: Oniya Olaiya
 * Description: This program prints a message to the consol.
 *		It serves as an example of using the `puts` function.
 */

#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It prints a message to the console using the `puts` function.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char str[] = "_putchar\n";
	int i = 0;

	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
	return (0);
}
