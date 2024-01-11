#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * str_copy - Copy a string to a newly allocated memory.
 * @str: The string to be copied.
 *
 * Return: A pointer to the newly allocated copy, or NULL on failure.
 */

char *str_copy(const char *str)
{
	if (str)
	{
		char *copy = malloc(strlen(str) + 1);

		if (copy)
			strcpy(copy, str);
		return (copy);
	}
	return (NULL);
}

/**
 * new_dog - Create a new dog structure with copied name and owner.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: A pointer to the newly created dog structure, or NULL on failure.
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog = malloc(sizeof(dog_t));

	if (!new_dog)
		return (NULL);

	new_dog->name = str_copy(name);
	new_dog->age = age;
	new_dog->owner = str_copy(owner);

	if (!new_dog->name || !new_dog->owner)
	{
		free(new_dog->name);
		free(new_dog->owner);
		free(new_dog);
		return (NULL);
	}

	return (new_dog);
}
