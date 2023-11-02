#include <stdlib.h>
#include <stdio.h>

/**
 * string_nconcat - Concatenates two strings, taking n bytes from s2
 * @s1: The first string
 * @s2: The second string
 * @n: The number of bytes to take from s2
 *
 * Return: A pointer to the newly allocated concatenated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int len1 = 0, len2 = 0, i = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	if (n >= len2)
		n = len2;

	new_str = malloc(len1 + n + 1);
	if (new_str == NULL)
		return (NULL);

	while (*s1)
		new_str[i++] = *s1++;

	while (n > 0)
	{
		new_str[i++] = *s2++;
		n--;
	}

	new_str[i] = '\0';
	return (new_str);
}

