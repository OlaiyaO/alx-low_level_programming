#include "lists.h"

/**
 * get_dnodeint_at_index - Return the nth node of a doubly linked list
 * @head: Pointer to the head of the doubly linked list
 * @index: Index of the node to return (starting from 0)
 * Return: Address of the node at the specified index, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int i = 0;

	while (current != NULL)
	{
		if (i == index)
			return (current);

		current = current->next;
		i++;
	}

	return (NULL);
}
