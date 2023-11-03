#include <unistd.h>

/**
 * _putchar - Write a character to the standard output (stdout)
 * @c: The character to write
 *
 * Return: On success, the character written is returned. On error, -1 is returned.
 */

int _putchar(char c)
{
	return write(1, &c, 1);
}

