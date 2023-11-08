#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * opcodes_printer - Prints the opcodes of a function.
 * @s: Pointer to the function to print opcodes for.
 *
 * Return: No return value.
 */

void opcodes_printer(char *s);

/**
 * main - Entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 1 for incorrect number of arguments,
 * 2 for negative bytes.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Error\n");
		return (1);
	}

	int num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		fprintf(stderr, "Error\n");
		return (2);
	}

	opcodes_printer((char *)&opcodes_printer);

	return (0);
}

/**
 * opcodes_printer - Prints the opcodes of a function.
 * @s: Pointer to the function to print opcodes for.
 *
 * Return: No return value.
 */

void opcodes_printer(char *s)
{
	int i;
	for (i = 0; i < atoi(s); i++)
	{
		printf("%02x", s[i] & 0xFF);
		if (i < atoi(s) - 1)
		{
			printf(" ");
		} else
		{
			printf("\n");
		}
	}
}
