/*
 * File: 6-main.c
 * Author: Oniya Olaiya.
 */

#include "main.h"
#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Description: This function is the entry point for the program.
 *		It calls the reverse_array function to reverse the array.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char str[] = "Expect the best. Prepare for the worst. Capitalize on whatcomes.\n"
		     "hello world! hello-world 0123456hello world\thello world.hello world\n";
	char *ptr;

	ptr = cap_string(str);
	printf("%s", ptr);
	printf("%s", str);

	return (0);
}
