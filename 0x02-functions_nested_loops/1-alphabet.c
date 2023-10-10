#include <unistd.h>
#include "main.h"
/**
 * print_alphabet - Prints the lowercase alphabet followed by a newline.
 */
void print_alphabet()
{
	char letter = 'a';

	while (letter <= 'z')
	{
		_putchar(letter);
		letter++;
	}
	_putchar('\n');
}
