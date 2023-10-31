#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of a program
 * @ac: The number of arguments
 * @av: An array of argument strings
 *
 * Return: Pointer to a new string containing the
 *	concatenated arguments, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *concatenated;
	int i, j, len = 0, total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			len++;
		}
	}
	total_len = ac + len + 1;
	concatenated = (char *)malloc(total_len * sizeof(char));

	if (concatenated == NULL)
		return (NULL);

	len = 0;

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			concatenated[len] = av[i][j];
			len++;
		}
		concatenated[len] = '\n';
		len++;
	}
	concatenated[len] = '\0';
	return (concatenated);
}

