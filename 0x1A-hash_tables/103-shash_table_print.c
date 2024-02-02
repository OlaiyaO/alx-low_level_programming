#include "hash_tables.h"

/**
 * shash_table_print - Prints the sorted hash table
 * @ht: The sorted hash table
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->shead;

	while (current != NULL)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->snext != NULL)
			printf(", ");
		current = current->snext;
	}

	printf("}\n");
}
