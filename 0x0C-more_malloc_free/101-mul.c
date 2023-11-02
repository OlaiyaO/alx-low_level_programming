#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_digit - Checks if a string is a valid digit
 * @str: The string to check
 *
 * Return: 1 if it's a digit, 0 otherwise
 */

int is_digit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * _calloc - Allocate memory for an array using calloc
 * @nmemb: Number of elements
 * @size: Size of each element
 *
 * Return: Pointer to the allocated memory, or NULL if allocation fails
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = calloc(nmemb, size);

	if (ptr == NULL)
		return (NULL);

	return (ptr);
}

/**
 * multiply - Multiplies two positive numbers
 * @num1: The first number
 * @num2: The second number
 *
 * Return: A pointer to the result
 */

int *multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j;
	int *result, carry = 0, temp;
	int n1, n2;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result = _calloc(len1 + len2, sizeof(int));

	if (result == NULL)
		exit(98);

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		j = len2 - 1;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';

			temp = n1 * n2 + result[i + j + 1] + carry;
			result[i + j + 1] = temp % 10;
			carry = temp / 10;
		}
		result[i + j + 1] = carry;
	}

	for (i = 0; result[i] == 0 && i < len1 + len2; i++)
		continue;

	return (result);
}

/**
 * main - Multiplies two positive numbers
 * @argc: The number of command line arguments
 * @argv: An array of command line argument strings
 *
 * Return: 0 on success, 98 on failure
 */

int main(int argc, char *argv[])
{
	int i;
	int *result;

	result = NULL;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	result = multiply(argv[1], argv[2]);

	for (i = 0; result[i]; i++)
		_putchar(result[i] + '0');
	_putchar('\n');
	free(result);

	return (0);
}

