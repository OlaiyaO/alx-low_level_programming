#include "search_algos.h"

/**
 * _binary_search - Binary search implementation with modified variable names.
 * @array: A pointer to the first element of the array to search.
 * @left_idx: The starting index of the [sub]array to search.
 * @right_idx: The ending index of the [sub]array to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 */
int _binary_search(int *array, size_t left_idx, size_t right_idx, int value)
{
	size_t index;

	if (array == NULL)
		return (-1);

	while (right_idx >= left_idx)
	{
		printf("Searching in array: ");
		for (index = left_idx; index < right_idx; index++)
			printf("%d, ", array[index]);
		printf("%d\n", array[index]);

		index = left_idx + (right_idx - left_idx) / 2;
		if (array[index] == value)
			return (index);
		if (array[index] > value)
			right_idx = index - 1;
		else
			left_idx = index + 1;
	}

	return (-1);
}

/**
 * exponential_search - Exponential search implementation with modified
 *			variable names.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, right_idx;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	right_idx = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right_idx);
	return (_binary_search(array, i / 2, right_idx, value));
}
