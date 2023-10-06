/*
 * File: 2-print_alphabet.c
 * Author: Oniya Olaiya
 * Description: This program prints a message to the console.
 *              it serves as an example of using the `putchar` function.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *              It prints a message to the console using the
 *              `putchar` function.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char lowercase = 'a';
	char uppercase = 'A';

	while (lowercase <= 'z')
	{
		putchar(lowercase);
		lowercase++;
	}
	while (uppercase <= 'Z')
	{
		putchar(uppercase);
		uppercase++;
	}
	putchar('\n');
	return (0);
}
