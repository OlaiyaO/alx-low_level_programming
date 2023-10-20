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
	int index, innerIndex, tempIndex;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (index = 0; index < size; index += 10)
	{
		printf("%.8x:", index);
		for (innerIndex = index; innerIndex < index + 10; innerIndex++)
		{
			if (innerIndex % 2 == 0)
				printf(" ");
			if (innerIndex < size)
				printf("%.2x", *(b + innerIndex));
			else
				printf("  ");
		}
		printf(" ");

		for (tempIndex = index; tempIndex < index + 10; tempIndex++)
		{
			if (tempIndex >= size)
				break;
			if (*(b + tempIndex) < 32 || *(b + tempIndex) > 126)
				printf("%c", '.');
			else
				printf("%c", *(b + tempIndex));
		}
		printf("\n");
	}
}
