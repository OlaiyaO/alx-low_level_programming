#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 * Return: Pointer to the created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(size * sizeof(shash_node_t *));

	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The hash table
 * @key: The key string
 * Return: The value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current && strcmp(current->key, key) != 0)
		current = current->next;

	return (current ? current->value : NULL);
}

/**
 * shash_table_print - Prints the sorted hash table
 * @ht: The hash table
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	current = ht->shead;
	printf("{");
	while (current)
	{
		printf("'%s': '%s'", current->key, current->value);

		if (current->snext)
			printf(", ");
		current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order
 * @ht: The hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	current = ht->stail;
	printf("{");
	while (current)
	{
		printf("'%s': '%s'", current->key, current->value);

		if (current->sprev)
			printf(", ");
		current = current->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes the sorted hash table
 * @ht: The hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current, *tmp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current)
		{
			tmp = current;
			current = current->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}

/**
 * insert_into_array - Inserts a new node into the hash table array
 * @ht: The hash table
 * @index: The index where the node should be inserted
 * @key: The key string
 * @value: The value string
 *
 * Return: 1 if successful, 0 otherwise
 */

int insert_into_array(
		shash_table_t *ht,
		unsigned long int index,
		const char *key,
		const char *value
		)
{
	shash_node_t *new_node;

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);

	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);

	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

/**
 * update_sorted_list - Updates the sorted linked list
 * @ht: The hash table
 * @current: The current node in the sorted linked list
 * @new_node: The new node to be inserted
 *
 * Return: 1 if successful, 0 otherwise
 */

int update_sorted_list(
		shash_table_t *ht,
		shash_node_t *current,
		shash_node_t *new_node
		)
{
	if (!current)
	{
		new_node->sprev = ht->stail;
		new_node->snext = NULL;

		if (ht->stail)
			ht->stail->snext = new_node;
		else
			ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		new_node->sprev = current->sprev;
		new_node->snext = current;

		if (current->sprev)
			current->sprev->snext = new_node;
		else
			ht->shead = new_node;
		current->sprev = new_node;
	}

	return (1);
}

/**
 * shash_table_set - Sets a key-value pair in the hash table
 * @ht: The hash table
 * @key: The key string
 * @value: The value string
 *
 * Return: 1 if successful, 0 otherwise
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	current = ht->shead;
	while (current && strcmp(current->key, key) < 0)
		current = current->snext;

	if (!insert_into_array(ht, index, key, value))
		return (0);

	new_node = ht->array[index];
	if (!update_sorted_list(ht, current, new_node))
		return (0);

	return (1);
}
