/*
 * File: 6-size.c
 * Author: Oniya Olaiya
 * Description: This program prints a message to the console.
 *              It serves as an example of using the `sizeof` function.
 */
#include <stdio.h>
/**
 * main - Program Entry Point
 *
 * Return: The return value is always 0 indicating successful run
 */
int main(void)
{
	printf("Size of char: %d byte(s)\n", sizeof(char));
	printf("Size of an int: %d byte(s)\n", sizeof(int));
	printf("Size of a long int: %d byte(s)\n", sizeof(long int));
	printf("Size of a long long int: %d byte(s)\n", sizeof(long long int));
	printf("Size of a float: %d byte(s)\n", sizeof(float));
	return (0);

}
