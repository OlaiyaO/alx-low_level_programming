#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers
 *               using the Jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index of the value in the array,
 *         or -1 if the value is not present or if the array is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t prev = 0, i, current = 0;

	if (array == NULL)
		return (-1);

	while (array[current] < value && current < size)
	{
		printf("Value checked array[%lu] = [%d]\n", current, array[current]);
		prev = current;
		current += step;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev, current);

	for (i = prev; i <= current && i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
