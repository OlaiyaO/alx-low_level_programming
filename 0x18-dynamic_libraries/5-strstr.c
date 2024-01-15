#include "main.h"
#include <stdio.h>

/**
 * _strstr - Locates a substring within a string.
 * @haystack: The string to search within.
 * @needle: The substring to search for.
 *
 * Return: A pointer to the beginning of the located substring, or NULL if
 * the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *h = haystack;
		char *n = needle;

		while (*h && *n && *h == *n)
		{
			h++;
			n++;
		}
		if (!*n)
			return (haystack);
		haystack++;
	}
	return (NULL);
}
