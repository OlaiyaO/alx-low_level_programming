#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Description: This program calculates the minimum number of coins needed
 * to make change for a given amount of cents using a set of coin values.
 *
 * Return: 0 if successful, 1 for errors or if the number of cents is negative.
 */

int main(int argc, char *argv[])
{
	int cents, count, num_coins;
	int coins[] = {25, 10, 5, 2, 1};

	cents = atoi(argv[1]);

	num_coins = sizeof(coins) / sizeof(coins[0]);
	count = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}
	for (int i = 0; i < num_coins; i++)
	{
		while (cents >= coins[i])
		{
			cents -= coins[i];
			count++;
		}
	}
	printf("%d\n", count);
	return (0);
}

