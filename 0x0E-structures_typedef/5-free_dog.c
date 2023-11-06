#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Free memory allocated for a dog
 * @d: Pointer to a dog_t
 */

void free_dog(dog_t *d)
{
	if (d)
	{
		free(d);
	}
}
