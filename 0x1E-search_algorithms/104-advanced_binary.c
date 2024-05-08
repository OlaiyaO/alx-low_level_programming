#include "search_algos.h"

/**
 * binary_recursive_search - Searches for a value in an array of intigers
 *                           using the binary search algorithm recursively.
 * @arr: Input array.
 * @size: Size of the array.
 * @target: Value to search for.
 *
 * Return: Index of the number if found, otherwise -1.
 */
int binary_recursive_search(int *arr, size_t size, int target)
{
	size_t middle = size / 2;
	size_t i;

	if (arr == NULL || size == 0)
		return (-1);

	printf("Searching in array");
	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", arr[i]);
	printf("\n");

	if (middle && size % 2 == 0)
		middle--;

	if (target == arr[middle])
	{
		if (middle > 0)
			return (binary_recursive_search(arr, middle + 1, target));
		return ((int)middle);
	}

	if (target < arr[middle])
		return (binary_recursive_search(arr, middle + 1, target));

	middle++;
	return (
			binary_recursive_search(arr + middle, size - middle, target) + middle
	       );
}

/**
 * advanced_binary - Calls the binary_recursive_search function
 *                          to return the index of the number if found.
 * @arr: Input array.
 * @size: Size of the array.
 * @target: Value to search for.
 *
 * Return: Index of the number if found, otherwise -1.
 */
int advanced_binary(int *arr, size_t size, int target)
{
	int result;

	result = binary_recursive_search(arr, size, target);

	if (result >= 0 && arr[result] != target)
		return (-1);

	return (result);
}
