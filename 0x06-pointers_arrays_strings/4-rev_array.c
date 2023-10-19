/*
 * File: -strncat.c
 * Author: Oniya Olaiya
 */

#include "main.h"
#include <stdio.h>

/**
 * reverse_array - reverses array of integers.
 *
 * Description: This function reverses the content-
 *		of an array of integers.
 *
 * @n: The number of elements in the array
 * @a: The array of integers.
 * Return: It returns nothing;
 */

void reverse_array(int *a, int n)
{
	int i = 0;
	int temp;

	while (i < n / 2)
	{
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
		i++;
	}
}
