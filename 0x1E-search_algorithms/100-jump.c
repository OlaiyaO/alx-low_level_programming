#include "search_algos.h"
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
	int block_size, block_index, jump_index, prev_index;

	if (array == NULL || size == 0)
		return (-1);

	block_size = (int)sqrt((double)size);
	block_index = 0;
	prev_index = jump_index = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", jump_index, array[jump_index]);

		if (array[jump_index] == value)
			return (jump_index);
		block_index++;
		prev_index = jump_index;
		jump_index = block_index * block_size;
	} while (jump_index < (int)size && array[jump_index] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev_index, jump_index);

	for (; prev_index <= jump_index && prev_index < (int)size; prev_index++)
	{
		printf("Value checked array[%d] = [%d]\n", prev_index, array[prev_index]);
		if (array[prev_index] == value)
			return (prev_index);
	}

	return (-1);
}
