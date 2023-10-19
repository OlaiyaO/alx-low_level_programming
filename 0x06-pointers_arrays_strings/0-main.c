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
	char s1[98] = "Hello ";
	char s2[] = "World!\n";
	char *ptr;

	printf("%s\n", s1);
	printf("%s", s2);

	ptr = _strcat(s1, s2);

	printf("%s", s1);
	printf("%s", s2);
	printf("%s", ptr);
	return (0);
}
