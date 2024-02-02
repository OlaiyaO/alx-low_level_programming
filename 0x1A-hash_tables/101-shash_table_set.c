#include "hash_tables.h"

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
		current = current->next;
	}

	new_node = create_new_node(key, value);
	if (new_node == NULL)
		return (0);

	insert_sorted_node(ht, new_node);
	ht->array[index] = new_node;

	return (1);
}
