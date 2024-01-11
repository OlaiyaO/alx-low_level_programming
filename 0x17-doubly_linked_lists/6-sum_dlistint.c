#include "lists.h"

/**
 * sum_dlistint - Return the sum of all elements in a doubly linked list
 * @head: Pointer to the head of the doubly linked list
 * Return: Sum of all elements
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	int sum = 0;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
