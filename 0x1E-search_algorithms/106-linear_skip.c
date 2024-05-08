#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where value is located, or NULL.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current_node;

	if (list == NULL)
		return (NULL);

	current_node = list;

	do {
		list = current_node;
		current_node = current_node->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)current_node->index, current_node->n);
	} while (current_node->express && current_node->n < value);

	if (current_node->express == NULL)
	{
		list = current_node;
		while (current_node->next)
			current_node = current_node->next;
	}

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)current_node->index);

	while (list != current_node->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
