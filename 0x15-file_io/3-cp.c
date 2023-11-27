#include "main.h"

/**
 * errexit - print error message and exit
 * @str: error message format
 * @file: file name
 * @code: exit code
 */

void errexit(const char *str, const char *file, int code)
{
	dprintf(STDERR_FILENO, str, file);
	exit(code);
}

/**
 * copy_file - copy content from source to destination file
 * @src_file: source file
 * @dest_file: destination file
 */

void copy_file(const char *src_file, const char *dest_file)
{
	int fd_src, fd_dest, num_read, num_write;
	char buffer[BUFSIZ];

	fd_src = open(src_file, O_RDONLY);
	if (fd_src == -1)
		errexit("Error: Can't read from file %s\n", src_file, 98);

	fd_dest = open(dest_file, O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_dest == -1)
		errexit("Error: Can't write to %s\n", dest_file, 99);

	while ((num_read = read(fd_src, buffer, BUFSIZ)) > 0)
	{
		num_write = write(fd_dest, buffer, num_read);

		if (num_write == -1 || num_write != num_read)
			errexit("Error: Can't write to %s\n", dest_file, 99);
	}

	if (num_read == -1)
		errexit("Error: Can't read from file %s\n", src_file, 98);

	if (close(fd_dest) == -1 || close(fd_src) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptors\n");
		exit(100);
	}
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: array of argument tokens
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}
