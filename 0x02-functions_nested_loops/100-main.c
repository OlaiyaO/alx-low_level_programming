/*
 * File: 9-main.c
 * Author: Oniya Olaiya
 * Description: This program prints the 9 times table.
 *
 */

#include "main.h"

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the times_table function .
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	print_times_table(3);
	_putchar('\n');
	print_times_table(5);
	_putchar('\n');
	print_times_table(98);
	_putchar('\n');
	print_times_table(12);
	return (0);
}
