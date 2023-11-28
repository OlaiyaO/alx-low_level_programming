#include "main.h"

/**
 * errexit - print error message and exit
 * @str: error message format
 * @file: file name
 * @code: exit code
 *
 * Return: does not return
 */

void errexit(const char *str, const char *file, int code)
{
	dprintf(STDERR_FILENO, str, file);
	exit(code);
}

/**
 * open_files - open source and destination files and handle errors
 * @src_file: source file name
 * @dest_file: destination file name
 *
 * Return: an array of two integers [fd_src, fd_dest]
 */

int *open_files(const char *src_file, const char *dest_file)
{
	int *fds = malloc(sizeof(int) * 2);

	if (!fds)
		errexit("Error: Memory allocation error\n", "", 1);

	fds[0] = open(src_file, O_RDONLY);
	if (fds[0] == -1)
		errexit("Error: Can't read from file %s\n", src_file, 98);

	fds[1] = open(dest_file, O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fds[1] == -1)
	{
		close(fds[0]);
		errexit("Error: Can't write to %s\n", dest_file, 99);
	}

	return (fds);
}

/**
 * close_files - close source and destination files and handle errors
 * @fds: an array of two integers [fd_src, fd_dest]
 *
 * Return: does not return
 */

void close_files(int *fds)
{
	if (close(fds[1]) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fds[1]);
		exit(100);
	}

	if (close(fds[0]) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fds[0]);
		exit(100);
	}

	free(fds);
}

/**
 * copy_file - copy content from source to destination file
 * @src_file: source file
 * @dest_file: destination file
 *
 * Return: does not return
 */

void copy_file(const char *src_file, const char *dest_file)
{
	char buffer[1024];
	ssize_t num_read, num_written;

	int *fds = open_files(src_file, dest_file);

	while ((num_read = read(fds[0], buffer, 1024)) > 0)
	{
		ssize_t total_written = 0;

		while (total_written < num_read)
		{
			num_written =
				write(fds[1], buffer + total_written, num_read - total_written);

			if (num_written <= 0)
			{
				close_files(fds);
				errexit("Error: Can't write to %s\n", dest_file, 99);
			}

			total_written += num_written;
		}
	}

	if (num_read == -1)
	{
		close_files(fds);
		errexit("Error: Can't read from file %s\n", src_file, 98);
	}

	close_files(fds);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: array of argument tokens
 *
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
