#include <stdio.h>

void __attribute__((constructor)) hare_tortoise(void);

/**
 * hare_tortoise - Prints a message before main function execution.
 */

void hare_tortoise(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
