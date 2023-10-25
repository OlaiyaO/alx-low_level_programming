#include "main.h"

/**
 * find_sqrt - Finds the square root recursively.
 * @n: The number to find the square root of.
 * @i: The current value to check.
 *
 * Return: The square root of n, or -1 if not found.
 */

int find_sqrt(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (find_sqrt(n, i + 1));
}


/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The square root of n, or -1 if it doesn't have a natural sqrt.
 */

int _sqrt_recursion(int n)
{
	return (find_sqrt(n, 1));
}
