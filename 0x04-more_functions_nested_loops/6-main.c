/*
 * File: 6-main.c
 * Author: Oniya Olaiya
 * Description: This program prints lines to the consol.
 *		It prints '_' and makes them into a line..
 */

#include "main.h"
#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_lines function to-
 *		print 'n' numbers of the underscore character..
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_line(0);
	print_line(2);
	print_line(10);
	print_line(-4);
	return (0);
}
