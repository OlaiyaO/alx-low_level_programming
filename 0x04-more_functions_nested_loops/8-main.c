/*
 * File: 8-main.c
 * Author: Oniya Olaiya
 * Description: This program prints lines to the consol.
 *		It prints '#' and makes them into a line..
 */

#include "main.h"
#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_squares function to-
 *		print 'n' numbers of the '#' character..
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_square(0);
	print_square(2);
	print_square(10);
	return (0);
}
