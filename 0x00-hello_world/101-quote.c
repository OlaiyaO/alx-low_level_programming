/*
 * File:101-quotes.c
 * Author: Oniya Olaiya
 * Description: This program prints a message to the console.
 *	      It serves as an example of using the `write` function.
 */

#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It prints a message to the console using the `write` function.
 * Return: Displays 1 to indicate success.
 */
int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);
}
