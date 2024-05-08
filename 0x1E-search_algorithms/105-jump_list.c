#include "search_algos.h"
#include <math.h>
#include <stdio.h>

/**
 * jump_list - Searches for a value in a sorted list of integers
 *             using the Jump search algorithm.
 * @list: Pointer to the head of the list to search in.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if not found.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, i;
	listint_t *prev, *current;
	if (list == NULL)
		return (NULL);

	jump = sqrt(size);
	prev = NULL;
	current = list;

	while (current->n < value && current->next != NULL)
	{
		prev = current;
		for (i = 0; i < jump && current->next != NULL; i++)
			current = current->next;

		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}

	printf(
			"Value found between indexes [%lu] and [%lu]\n", prev->index, current->index
			);

	printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
	while (prev->n < value)
	{
		if (prev->next == NULL || prev->index >= current->index)
			return (NULL);

		prev = prev->next;
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
	}

	if (prev->n == value)
		return (prev);

	return (NULL);
}
