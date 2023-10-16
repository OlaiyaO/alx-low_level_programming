/*
 * File: 0-main.c
 * Author: Oniya Olaiya
 * Description: This program prints signs to the consol.
 *		It prints + for positive, 0 for zero and - for negative numbers.
 */

#include "main.h"
#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_sign function to do the checks.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n;
	
	n = 402;
	printf("n=%d\n", n);
	reset_to_98(&n);
	printf("n=%d\n", n);
	return (0);
}
