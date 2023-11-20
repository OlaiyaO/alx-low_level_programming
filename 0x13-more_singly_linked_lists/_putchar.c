#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written
 *
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
