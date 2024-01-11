#include "main.h"

/**
 * read_textfile - Reads a text file and prints
 *		it to the POSIX standard output.
 * @filename: Name of the file to read.
 * @letters: Number of letters to read and print.
 * Return: Actual number of letters read and printed; 0 on failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor, read_result;
	char *buffer;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}

	read_result = read(file_descriptor, buffer, letters);
	if (read_result == -1 || !write_to_stdout(buffer, (size_t)read_result))
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	free(buffer);
	close(file_descriptor);
	return (read_result);
}

/**
 * allocate_buffer - Allocates memory for a buffer.
 * @size: Size of the buffer to allocate.
 * Return: A pointer to the allocated buffer; NULL on failure.
 */

char *allocate_buffer(size_t size)
{
	return (malloc(sizeof(char) * size));
}

/**
 * free_buffer - Frees the memory of a buffer.
 * @buffer: Pointer to the buffer to free.
 */

void free_buffer(char *buffer)
{
	free(buffer);
}

/**
 * write_to_stdout - Writes the buffer to the standard output.
 * @buffer: Pointer to the buffer to write.
 * @size: Size of the buffer.
 * Return: 1 on success, 0 on failure.
 */

int write_to_stdout(char *buffer, size_t size)
{
	return (write(STDOUT_FILENO, buffer, size) == (ssize_t)size);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: File descriptor to close.
 */

void close_file(int fd)
{
	close(fd);
}
