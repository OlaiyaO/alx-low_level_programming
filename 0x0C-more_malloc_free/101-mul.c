#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * _strlen - Finds the length of a string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * initializeXArray - Creates an array of chars and initializes it with
 *                   the character 'x'. Adds a terminating null byte.
 * @size: The size of the array to be initialized.
 *
 * Description: If there is insufficient space, the function
 *              exits with a status of 98.
 * Return: A pointer to the array.
 */
char *initializeXArray(int size)
{
	char *array;
	int index;

	array = malloc(sizeof(char) * size);

	if (array == NULL)
	{
		exit(98);
	}

	for (index = 0; index < (size - 1); index++)
	{
		array[index] = 'x';
	}

	array[index] = '\0';

	return (array);
}

/**
 * advancePastZeroes - Iterates through a string of numbers containing
 *                  leading zeroes until it hits a non-zero number.
 * @str: The string of numbers to be iterate through.
 *
 * Return: A pointer to the next non-zero element.
 */
char *advancePastZeroes(char *str)
{
	while (*str && *str == '0')
		str++;

	return (str);
}

/**
 * getDigit - Converts a digit character to a corresponding int.
 * @c: The character to be converted.
 *
 * Description: If c is a non-digit, the function
 *              exits with a status of 98.
 * Return: The converted int.
 */
int getDigit(char c)
{
	int digit = c - '0';

	if (digit < 0 || digit > 9)
	{
		printf("Error\n");
		exit(98);
	}

	return (digit);
}

/**
 * calculateProduct - Multiplies a string of numbers by a single digit.
 * @product: The buffer to store the result.
 * @multiplier: The string of numbers.
 * @digit: The single digit.
 * @zeroes: The necessary number of leading zeroes.
 *
 * Description: If multiplier contains a non-digit, the function
 *              exits with a status value of 98.
 */

void calculateProduct(char *product, char *multiplier, int digit, int zeroes)
{
	int mult_len, num, tens = 0;

	mult_len = _strlen(multiplier) - 1;
	multiplier += mult_len;

	while (*product)
	{
		*product = 'x';
		product++;
	}

	product--;

	while (zeroes--)
	{
		*product = '0';
		product--;
	}

	for (; mult_len >= 0; mult_len--, multiplier--, product--)
	{
		if (*multiplier < '0' || *multiplier > '9')
		{
			printf("Error\n");
			exit(98);
		}

		num = (*multiplier - '0') * digit;
		num += tens;
		*product = (num % 10) + '0';
		tens = num / 10;
	}

	if (tens)
		*product = (tens % 10) + '0';
}

/**
 * addNumbers - Adds the numbers stored in two strings.
 * @finalProduct: The buffer storing the running final product.
 * @nextProduct: The next product to be added.
 * @nextLength: The length of nextProduct.
 */
void addNumbers(char *finalProduct, char *nextProduct, int nextLength)
{
	int num, tens = 0;

	while (*(finalProduct + 1))
		finalProduct++;

	while (*(nextProduct + 1))
		nextProduct++;

	for (; *finalProduct != 'x'; finalProduct--)
	{
		num = (*finalProduct - '0') + (*nextProduct - '0');
		num += tens;
		*finalProduct = (num % 10) + '0';
		tens = num / 10;

		nextProduct--;
		nextLength--;
	}

	for (; nextLength >= 0 && *nextProduct != 'x'; nextLength--)
	{
		num = (*nextProduct - '0');
		num += tens;
		*finalProduct = (num % 10) + '0';
		tens = num / 10;

		finalProduct--;
		nextProduct--;
	}

	if (tens)
		*finalProduct = (tens % 10) + '0';
}

/**
 * main - Multiplies two positive numbers.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Description: If the number of arguments is incorrect or one number
 *              contains non-digits, the function exits with a status of 98.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *finalProduct, *nextProduct;
	int size, index, digit, zeroes = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = advancePastZeroes(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = advancePastZeroes(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}

	size = _strlen(argv[1]) + _strlen(argv[2]);
	finalProduct = initializeXArray(size + 1);
	nextProduct = initializeXArray(size + 1);

	for (index = _strlen(argv[2]) - 1; index >= 0; index--)
	{
		digit = getDigit(*(argv[2] + index));
		calculateProduct(nextProduct, argv[1], digit, zeroes++);
		addNumbers(finalProduct, nextProduct, size - 1);
	}
	for (index = 0; finalProduct[index]; index++)
	{
		if (finalProduct[index] != 'x')
			putchar(finalProduct[index]);
	}
	putchar('\n');

	free(nextProduct);
	free(finalProduct);

	return (0);
}

