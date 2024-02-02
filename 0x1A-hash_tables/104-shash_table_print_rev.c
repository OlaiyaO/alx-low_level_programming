#include "hash_tables.h"

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order
 * @ht: The sorted hash table
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->stail;

	while (current != NULL)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->sprev != NULL)
			printf(", ");
		current = current->sprev;
	}

	printf("}\n");
}
