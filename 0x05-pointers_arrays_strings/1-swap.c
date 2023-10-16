/*
 * File: 1-swap.c
 * Author: Oniya Olaiya
 * Description: This swaps the values stored in 2 pointers.
 *
 */

#include "main.h"
#include <stdio.h>

/**
 * swap_int - Function to swap an integerm.
 *
 * Description: This function is the swaps 2 pointers holding.
 *		ineger values..
 * @a: The first integer to be swaped.
 * @b: the Second integer to be swaped
 * Return: void (Success)
 */

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
