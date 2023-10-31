#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_space - Checks if a character is a whitespace character.
 * @c: The character to be checked.
 *
 * Return: 1 if the character is a whitespace character, 0 otherwise.
 */

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

/**
 * count_words - Count the number of words in a string.
 * @str: The string to count words in.
 *
 * Return: The number of words found in the string.
 */

int count_words(char *str)
{
	int count = 0, in_word = 0;

	while (*str)
	{
		if (is_space(*str))
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

/**
 * create_word - Create a new word from the input string.
 * @str: The input string.
 * @start: The starting index of the word.
 * @end: The ending index of the word.
 *
 * Return: A new word.
 */
char *create_word(char *str, int start, int end)
{
	int i, len = end - start;
	char *word = (char *)malloc((len + 1) * sizeof(char));

	if (word == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		word[i] = str[start + i];
	}
	word[i] = '\0';
	return (word);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: Pointer to an array of strings (words), or NULL if it fails.
 */
char **strtow(char *str)
{
	char **words;
	int i, len, word_count = 0;
	int in_word = 0, word_start = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	len = strlen(str);
	word_count = count_words(str);
	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
	{
		if (is_space(str[i]) || str[i] == '\0')
		{
			if (in_word)
			{
				words[word_count] = create_word(str, word_start, i);
				if (words[word_count] == NULL)
				{
					for (i = 0; i < word_count; i++)
					{
						free(words[i]);
					}
					free(words);
					return (NULL);
				}
				word_count++;
				in_word = 0;
			}
		}
		else if (!in_word)
		{
			word_start = i;
			in_word = 1;
		}
	}
	words[word_count] = NULL;
	return (words);
}
