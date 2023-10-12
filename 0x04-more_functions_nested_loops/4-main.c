/*
 * File: 4-main.c
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
 *		It calls the print_numbers function to-
 *		 print all single digits positive numbers-
 *		 except 2 & 4..
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_most_numbers();
	return (0);
}
