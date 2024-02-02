#include "hash_tables.h"

/**
 * shash_table_get - Retrieves a value associated with a
 * key from the sorted hash table
 * @ht: The sorted hash table
 * @key: The key to search for
 *
 * Return: The value associated with the key,
 * or NULL if the key couldn't be found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);

		current = current->next;
	}

	return (NULL);
}
