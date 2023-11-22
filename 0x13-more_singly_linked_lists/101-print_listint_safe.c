#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t list safely,
 * even if the list is looped.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	size_t count = 0;

	if (head == NULL)
	{
		fprintf(stderr, "Error: NULL head\n");
		exit(98);
	}

	while (head != NULL)
	{
		current = head;
		printf("[%p] %d\n", (void *)head, head->n);
		count++;

		head = head->next;

		if (current <= head)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			break;
		}
	}

	return (count);
}
