/*
 * File: 7-main.c
 * Author: Oniya Olaiya
 * Description: This program prints lines to the consol.
 *		It prints '\' and makes them into a line..
 */

#include "main.h"
#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_diagonal function to-
 *		print 'n' numbers of the back slash character.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_diagonal(0);
	print_diagonal(2);
	print_diagonal(10);
	print_diagonal(-4);
	return (0);
}
