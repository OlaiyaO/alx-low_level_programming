/*
 * File: -strncat.c
 * Author: Oniya Olaiya
 */

#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a number to the console.
 *
 * Description: This function capitalizes an array of characters.
 *
 * @b: The pointer location/buffer start.
 * @size: The size of the buffer.
 * Return: nothing.
 */

void print_buffer(char *b, int size)
{
	int i, j;
	unsigned char *ptr = (unsigned char *)b;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
				printf("%02x", ptr[i + j]);
			else
				printf("  ");
			if (j % 2 != 0 && j < 9)
				printf(" ");
		}

		printf(" ");

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				if (ptr[i + j] >= 32 && ptr[i + j] <= 126)
					printf("%c", ptr[i + j]);
				else
					printf(".");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
