#include <stdio.h>

/**
 * main - Prints the number of arguments passed
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[]) 
{
	(void)argv;
	printf("%d\n", argc - 1);
	return (0);
}
