#include "search_algos.h"
#include <stdio.h>
/**
 * interpolation_search - Searches for a value in an array of integers
 *                        using the Interpolation search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index of the value in the array,
 *         or -1 if the value is not present or if the array is NULL.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, low, high;
	double factor;

	if (array == NULL)
		return (-1);

	low = 0;
	high = size - 1;

	while (size)
	{
		factor = (double)(high - low) / (array[high] - array[low]);
		factor *= (value - array[low]);

		pos = (size_t)(low + factor);
		printf("Value checked array[%d]", (int)pos);

		if (pos >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[pos]);
		}

		if (array[pos] == value)
			return ((int)pos);

		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;

		if (low == high)
			break;
	}

	return (-1);
}
