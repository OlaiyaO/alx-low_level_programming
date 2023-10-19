/*
 * File: -strncat.c
 * Author: Oniya Olaiya
 */

#include "main.h"
#include <stdio.h>

/**
 * infinite_add - prints a number to the console.
 *
 * Description: This function capitalizes an array of characters.
 *
 * @n1: The first string.
 * @n2: The second string.
 * @r: A pointer of type char to r..
 * @size_r: The size of r buffer..
 * Return: nothing.
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, carry = 0;
	int i = 0, k = 0;

	while (n1[len1])
		len1++;

	while (n2[len2])
		len2++;

	if (len1 + 1 >= size_r || len2 + 1 >= size_r)
		return (0);

	while (len1 > 0 || len2 > 0 || carry)
	{
		int num1 = (len1 > 0) ? n1[--len1] - '0' : 0;
		int num2 = (len2 > 0) ? n2[--len2] - '0' : 0;
		int sum = num1 + num2 + carry;

		carry = sum / 10;

		r[k++] = (sum % 10) + '0';
	}
	r[k] = '\0';

	for (i = 0, k--; i < k; i++, k--)
	{
		char temp = r[i];

		r[i] = r[k];
		r[k] = temp;
	}
	return (r);
}


