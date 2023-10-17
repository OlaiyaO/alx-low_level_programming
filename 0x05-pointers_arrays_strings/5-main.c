/*
 * File: 1-main.c
 * Author: Oniya Olaiya
 * Description: This program prints swaps on the console.
 *		It a and ba before and after swapping.
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
	char s[10] = "My School";

	printf("%s\n", s);
	rev_string(s);
	printf("%s\n", s);
	return (0);
}
