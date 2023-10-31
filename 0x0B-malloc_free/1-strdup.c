#include "main.h"
#include <string.h>
#include <stdlib.h>
/**
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL if it fails
 */
char *_strdup(char *str)
{
	char *duplicate;
	int length;

	if (str == NULL)
		return (NULL);

	length = strlen(str) + 1;
	duplicate = (char *)malloc(length * sizeof(char));

	if (duplicate == NULL)
		return (NULL);

	strcpy(duplicate, str);
	return (duplicate);
}

