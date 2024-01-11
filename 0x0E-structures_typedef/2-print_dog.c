#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Print a struct dog
 * @d: Pointer to a struct dog
 */

void print_dog(struct dog *d)
{
	if (d)
	{
		printf("Name: %s\n", d->name ? d->name : "(nil)");
		printf("Age: %.6f\n", d->age);
		printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
	}
}
