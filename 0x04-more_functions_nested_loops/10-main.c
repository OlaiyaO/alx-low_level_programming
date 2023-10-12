/*
 * File: 10-main.c
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
	print_triangle(2);
	print_triangle(10);
	print_triangle(1);
	print_triangle(0);
	return (0);
}
