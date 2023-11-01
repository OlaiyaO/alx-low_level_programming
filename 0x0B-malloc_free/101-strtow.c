#include "main.h"
#include <stdlib.h>

void splitWords(char **wordArray, char *str);
void createWord(char **wordArray, char *str, int start, int end, int index);

/**
 * strtow - Splits a string into words.
 * @str: The input string to split.
 *
 * Return: A pointer to an array of strings (words) or NULL on failure.
 */

char **strtow(char *str)
{
	int i, flag, len;
	char **words;

	if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
		return (NULL);

	i = flag = len = 0;

	while (str[i])
	{
		if (flag == 0 && str[i] != ' ')
			flag = 1;
		if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			flag = 0;
			len++;
		}
		i++;
	}

	len += flag == 1 ? 1 : 0;
	if (len == 0)
		return (NULL);

	words = (char **)malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
		return (NULL);

	splitWords(words, str);
	words[len] = NULL;
	return (words);
}

/**
 * splitWords - A function to fetch words into an array.
 * @wordArray: The array to store words.
 * @str: The input string.
 */

void splitWords(char **wordArray, char *str)
{
	int i, j, start, flag;

	i = j = flag = 0;

	while (str[i])
	{
		if (flag == 0 && str[i] != ' ')
		{
			start = i;
			flag = 1;
		}
		if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			createWord(wordArray, str, start, i, j);
			j++;
			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		createWord(wordArray, str, start, i, j);
}

/**
 * createWord - Creates a word and inserts it into the array.
 * @wordArray: The array of strings.
 * @str: The input string.
 * @start: The starting index of the word.
 * @end: The ending index of the word.
 * @index: The index of the array to insert the word.
 */

void createWord(char **wordArray, char *str, int start, int end, int index)
{
	int i, j;

	i = end - start;
	wordArray[index] = (char *)malloc(sizeof(char) * (i + 1));

	for (j = 0; start < end; start++, j++)
		wordArray[index][j] = str[start];
	wordArray[index][j] = '\0';
}

