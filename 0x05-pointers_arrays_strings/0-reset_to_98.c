/*
 * File: 0-main.c
 * Author: Oniya Olaiya
 * Description: This program changes the value pointed to by n.
 *
 */

#include "main.h"
#include <stdio.h>

/**
 * reset_to_98 - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_sign function to do the checks.
 * @n: The pointer parameter.
 *
 * Return: Always 0 (Success)
 */

void reset_to_98(int *n)
{
	int num = 98;
	*n = num;
}
