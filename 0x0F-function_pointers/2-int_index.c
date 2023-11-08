#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array.
 * @array: Array of integers to search in.
 * @size: Size of the array.
 * @cmp: Pointer to a function that compares integers.
 *
 * Return: Index of the first matching element, or -1 if not found.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
			{
				return (i);
			}
		}
	}
	return (-1);
}
