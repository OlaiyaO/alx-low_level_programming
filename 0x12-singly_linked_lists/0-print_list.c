#include "lists.h"

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: A pointer to the head of the list.
 *
 * Return: The number of nodes.
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			_putchar('[');
			_putchar('0');
			_putchar(']');
			_putchar(' ');
			_putchar('(');
			_putchar('n');
			_putchar('i');
			_putchar('l');
			_putchar(')');
			_putchar('\n');
		}
		else
		{
			_putchar('[');
			print_number(h->len);
			_putchar(']');
			_putchar(' ');
			print_str(h->str);
			_putchar('\n');
		}
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * print_number - Prints an unsigned integer.
 * @n: The number to be printed.
 */

void print_number(unsigned int n)
{
	if (n / 10 != 0)
		print_number(n / 10);

	_putchar(n % 10 + '0');
}

/**
 * print_str - Prints a string.
 * @str: The string to be printed.
 */

void print_str(const char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
