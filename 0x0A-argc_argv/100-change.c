#include <stdio.h>
#include <stdlib.h>

/**
 * main - Calculates the minimum number of coins to make change.
 * @argc: Number of arguments.
 * @argv: Array of arguments (expecting one integer argument).
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int amount = 0;
	int coins = 0;
	char error_message[] = "Error";

	if (argc != 2)
	{
		printf("%s\n", error_message);
		return (1);
	}

	amount = atoi(argv[1]);

	while (amount >= 25)
	{
		amount -= 25;
		coins++;
	}
	while (amount >= 10)
	{
		amount -= 10;
		coins++;
	}
	while (amount >= 5)
	{
		amount -= 5;
		coins++;
	}
	while (amount >= 2)
	{
		amount -= 2;
		coins++;
	}
	if (amount == 1)
		coins++;

	printf("%d\n", coins);

	return (0);
}

