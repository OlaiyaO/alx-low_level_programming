#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints opcodes of its own main function.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 1 for incorrect
 * number of arguments, 2 for negative bytes.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	int bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	char *main_address = (char *)main;
	int i;

	for (i = 0; i < bytes - 1; i++)
	{
		printf("%02x ", main_address[i]);
	}

	printf("%02x\n", main_address[i]);

	return (0);
}
