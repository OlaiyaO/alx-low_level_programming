/*
 * File: -main.c
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

	char s[] = "ROT13 (\"rotate by 13 places\",sometimes hyphenated ROT-13) is a simple letter substitution cipher.\n";
	char *p;

	p = rot13(s);

	printf("%s", p);
	printf("------------------------------------\n");
	printf("%s", s);
	printf("------------------------------------\n");

	p = rot13(s);

	printf("%s", p);
	printf("------------------------------------\n");
	printf("%s", s);
	printf("------------------------------------\n");

	p = rot13(s);

	printf("%s", p);
	printf("------------------------------------\n");
	printf("%s", s);

	return (0);
}
