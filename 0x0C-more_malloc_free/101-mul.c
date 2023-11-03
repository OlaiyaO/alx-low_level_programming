#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * is_positive_integer - Checks if a string is a valid positive integer
 * @str: The string to check
 *
 * Return: (1) if it's a positive integer, (0) otherwise
 */

int is_positive_integer(char *str)
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
 * initialize_result - Initialize and allocate memory for the result array
 * @len_result: Length of the result array
 * Return: A pointer to the initialized result array
 */

int *initialize_result(int len_result)
{
	int i;
	int *result = (int *)malloc(sizeof(int) * len_result);

	if (result == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len_result; i++)
	{
		result[i] = 0;
	}

	return (result);
}

/**
 * perform_multiplication - Multiply two numbers
 *	and store the result in result array
 * @num1: The first number
 * @num2: The second number
 * @result: The result array
 * @len1: Length of num1
 * @len2: Length of num2
 */

void perform_multiplication(char *num1, char *num2,
		int *result, int len1, int len2)
{
	int i, j;

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int product = (num1[i] - '0') * (num2[j] - '0');
			int sum = product + result[i + j + 1];

			result[i + j] += sum / 10;
			result[i + j + 1] = sum % 10;
		}
	}
}

/**
 * create_result_string - Create the result string from the result array
 * @result: The result array
 * @len_result: Length of the result array
 * @leading_zeros: Number of leading zeros
 * Return: A pointer to the result string
 */

char *create_result_string(int *result, int len_result, int leading_zeros)
{
	int i;
	char *result_str = (char *)malloc(len_result - leading_zeros + 1);

	if (result_str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len_result - leading_zeros; i++)
	{
		result_str[i] = result[i + leading_zeros] + '0';
	}

	result_str[len_result - leading_zeros] = '\0';

	return (result_str);
}


/**
 * multiply - Multiplies two positive numbers
 * @num1: The first number
 * @num2: The second number
 *
 * Return: The result of the multiplication
 */

char *multiply(char *num1, char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len_result = len1 + len2;
	int *result;
	char *result_str;
	int leading_zeros = 0;

	if (len1 == 0 || len2 == 0)
		return (NULL);

	result = initialize_result(len_result);

	if (result == NULL)
		return (NULL);

	perform_multiplication(num1, num2, result, len1, len2);

	while (leading_zeros < len_result - 1 && result[leading_zeros] == 0)
		leading_zeros++;

	result_str = create_result_string(result, len_result, leading_zeros);

	if (result_str == NULL)
	{
		free(result);
		return (NULL);
	}

	free(result);

	return (result_str);
}

/**
 * main - Entry point for the multiplication program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, 98 on failure
 */

int main(int argc, char *argv[])
{
	char *num1 = argv[1];
	char *num2 = argv[2];
	char *result = multiply(num1, num2);
	int i;

	if (argc != 3 || !is_positive_integer(argv[1])
		|| !is_positive_integer(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (98);
	}

	if (result == NULL)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (98);
	}

	for (i = 0; result[i] != '\0'; i++)
	{
		_putchar(result[i]);
	}

	_putchar('\n');
	free(result);

	return (0);
}

