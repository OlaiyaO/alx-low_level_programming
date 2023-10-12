/*
 * File: -main.c
 * Author: Oniya Olaiya
 * Description: This program prints numbers to the consol.
 *		It numbers from 0 to 9.
 */

#include "main.h"
#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_number function to-
 *		print any number passed to it..
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_number(98);
	_putchar('\n');
	print_number(402);
	_putchar('\n');
	print_number(1024);
	_putchar('\n');
	print_number(0);
	_putchar('\n');
	print_number(-98);
	_putchar('\n');
	return (0);
}
