#include "hash_tables.h"

/**
 * create_new_node - Creates a new node for the sorted hash table
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */

shash_node_t *create_new_node(const char *key, const char *value)
{
	shash_node_t *new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;

	return (new_node);
}

/**
 * insert_sorted_node - Inserts a node into the sorted linked list of the
 * sorted hash table
 *
 * @ht: The sorted hash table
 * @new_node: The node to insert
 */

void insert_sorted_node(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *current;

	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		current = ht->shead;

		while (current != NULL && strcmp(current->key, new_node->key) < 0)
		{
			current = current->snext;
		}

		if (current == NULL)
		{
			new_node->sprev = ht->stail;
			ht->stail->snext = new_node;
			ht->stail = new_node;
		}
		else
		{
			if (current->sprev != NULL)
				current->sprev->snext = new_node;
			else
				ht->shead = new_node;

			new_node->sprev = current->sprev;
			new_node->snext = current;
			current->sprev = new_node;
		}
	}
}
