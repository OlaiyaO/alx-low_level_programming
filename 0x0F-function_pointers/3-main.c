#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point. Performs simple operations.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 98 for wrong number of arguments,
 * 99 for invalid operator, 100 for division by zero.
 */

int main(int argc, char *argv[])
{
	int a, b, result;
	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	operation = get_op_func(argv[2]);

	if (operation == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((*argv[2] == '/' || *argv[2] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = operation(a, b);
	printf("%d\n", result);

	return (0);
}
