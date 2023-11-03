#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * str_length - Calculate the length of a string
 * @str: Input pointer to the string
 * Return: Length of the string
 */

int str_length(char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}

	return (length);
}

/**
 * allocate_memory - Allocates memory for an array using malloc
 * @element_size: Size of each element
 * @num_elements: Number of elements to allocate
 * Return: Pointer to the allocated memory
 */

void *allocate_memory(unsigned int element_size, unsigned int num_elements)
{
	unsigned int i;
	char *ptr;

	if (element_size == 0 || num_elements == 0)
		return (NULL);

	if (element_size >= UINT_MAX / num_elements || num_elements >= UINT_MAX / element_size)
		return (NULL);

	ptr = (char *)malloc(element_size * num_elements);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < element_size * num_elements; i++)
		ptr[i] = 0;

	return ((void *)ptr);
}

/**
 * add_arrays - Adds two arrays of integers
 * @product_array: Pointer to the array with numbers from product
 * @sum_array: Pointer to the array with numbers from total sum
 * @array_length: Length of both arrays
 * Return: void
 */

void add_arrays(int *product_array, int *sum_array, int array_length)
{
	int i = 0, last_index = array_length - 1, carry = 0, sum;

	while (i < array_length)
	{
		sum = carry + product_array[last_index] + sum_array[last_index];
		sum_array[last_index] = sum % 10;
		carry = sum / 10;
		i++;
		last_index--;
	}
}

/**
 * is_digit - Checks if a character is a digit
 * @c: Input character to check
 * Return: 0 (failure), 1 (success)
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return 1;

	printf("Error\n");
	return (0);
}

/**
 * multiply_numbers - Multiplies two numbers, prints result
 * @smaller_num: Factor 1 (the smaller of the two numbers)
 * @smaller_num_length: Length of factor 1
 * @larger_num: Factor 2 (the larger of the two numbers)
 * @larger_num_length: Length of factor 2
 * @result_length: Length of result arrays
 * Return: 0 (failure), 1 (success)
 */

int *multiply_numbers(char *smaller_num, int smaller_num_length, char *larger_num, int larger_num_length, int result_length)
{
	int i = 0, smaller_index = smaller_num_length - 1;
	int larger_index, product, carry, digit;
	int *product_array, *sum_array;

	sum_array = allocate_memory(sizeof(int), result_length);

	while (i < smaller_num_length)
	{
		product_array = allocate_memory(sizeof(int), result_length);
		larger_index = larger_num_length - 1;
		digit = (result_length - 1 - i);

		if (!is_digit(smaller_num[smaller_index]))
			return (NULL);

		carry = 0;

		while (larger_index >= 0)
		{
			if (!is_digit(larger_num[larger_index]))
				return (NULL);

			product = (smaller_num[smaller_index] - '0') * (larger_num[larger_index] - '0');
			product += carry;
			product_array[digit] += product % 10;
			carry = product / 10;
			digit--;
			larger_index--;
		}

		add_arrays(product_array, sum_array, result_length);
		free(product_array);
		i++;
		smaller_index--;
	}

	return (sum_array);
}

/**
 * print_result - Prints the result array
 * @result_array: Pointer to an integer array with numbers to add
 * @result_length: Length of the result array
 * Return: void
 */

void print_result(int *result_array, int result_length)
{
	int i = 0;

	while (result_array[i] == 0 && i < result_length)
	{
		i++;
	}

	if (i == result_length)
	{
		putchar('0');
	}

	while (i < result_length)
	{
		putchar(result_array[i++] + '0');
	}

	putchar('\n');
}

/**
 * main - Multiplies two input numbers of large lengths and prints the result or an error
 * @argc: Input count of arguments
 * @argv: Input array of string arguments
 * Return: 0 (Success)
 */

int main(int argc, char **argv)
{
	int smaller_num_length, larger_num_length, result_length, temp;
	int *result_array;
	char *smaller_num, *larger_num;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	smaller_num_length = str_length(argv[1]);
	larger_num_length = str_length(argv[2]);
	result_length = smaller_num_length + larger_num_length;

	if (smaller_num_length < larger_num_length)
	{
		smaller_num = argv[1];
		larger_num = argv[2];
	}
	else
	{
		smaller_num = argv[2];
		larger_num = argv[1];
		temp = larger_num_length;
		larger_num_length = smaller_num_length;
		smaller_num_length = temp;
	}

	result_array = multiply_numbers(smaller_num, smaller_num_length, larger_num, larger_num_length, result_length);

	if (result_array == NULL)
		exit(98);

	print_result(result_array, result_length);
	return (0);
}

