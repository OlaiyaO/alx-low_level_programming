#!/bin/bash

# List of object files to be removed
OBJECT_FILES="0-isupper.o 0-memset.o 0-strcat.o 100-atoi.o 1-isdigit.o 1-memcpy.o 1-strncat.o 2-strchr.o 2-strlen.o 2-strncpy.o 3-islower.o 3-puts.o 3-strcmp.o 3-strspn.o 4-isalpha.o 4-strpbrk.o 5-strstr.o 6-abs.o 9-strcpy.o main.o _putchar.o"

# Remove each object file from the static library
for OBJECT_FILE in $OBJECT_FILES; do
	ar -d libmy.a "$OBJECT_FILE"
done

# Update the static library index (optional but recommended)
ranlib libmy.a
