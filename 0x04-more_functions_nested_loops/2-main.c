/*
 * File: 2-main.c
 * Author: Oniya Olaiya
 * Description: This program prints 0 to the consol.
 *		It checks if a character is a digit or not.
 */

#include "main.h"
#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the mul function for multiplication.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("%d\n", mul(98, 1024));
	printf("%d\n", mul(-402, 4096));
	return (0);
}
