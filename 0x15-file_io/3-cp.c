#include "main.h"

/**
 * check_arguments - Checks the number of command-line arguments.
 * @ac: Number of arguments.
 * @av: Array of arguments.
 * Return: 1 if the number of arguments is correct, 0 otherwise.
 */

int check_arguments(int ac, char **av)
{
	if (ac != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", av[0]);
		return (0);
	}
	return (1);
}

/**
 * open_source_file - Opens the source file for reading.
 * @filename: Name of the source file.
 * Return: File descriptor on success, -1 on failure.
 */

int open_source_file(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	
	if (fd == -1)
		dprintf(2, "Error: Can't read from file %s\n", filename);
	return (fd);
}

/**
 * open_destination_file - Opens the destination file for writing.
 * @filename: Name of the destination file.
 * Return: File descriptor on success, -1 on failure.
 */

int open_destination_file(const char *filename)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	
	if (fd == -1)
		dprintf(2, "Error: Can't write to %s\n", filename);
	return (fd);
}

/**
 * copy_file_contents - Copies the contents from source to destination file.
 * @fd_from: File descriptor for the source file.
 * @fd_to: File descriptor for the destination file.
 * Return: 1 on success, 0 on failure.
 */

int copy_file_contents(int fd_from, int fd_to)
{
	char buffer[1024];
	ssize_t read_result, write_result;

	while ((read_result = read(fd_from, buffer, 1024)) > 0)
	{
		write_result = write(fd_to, buffer, read_result);
		if (write_result == -1 || write_result != read_result)
		{
			dprintf(2, "Error: Can't write to file\n");
			return (0);
		}
	}

	return (1);
}

/**
 * main - Copies the content of a file to another file.
 * @ac: Number of arguments.
 * @av: Array of arguments.
 * Return: 0 on success, 97, 98, 99, or 100 on failure.
 */

int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (!check_arguments(ac, av))
		return (97);

	fd_from = open_source_file(av[1]);
	if (fd_from == -1)
		return (98);

	fd_to = open_destination_file(av[2]);
	if (fd_to == -1)
	{
		close(fd_from);
		return (99);
	}

	if (!copy_file_contents(fd_from, fd_to))
	{
		close(fd_from);
		close(fd_to);
		return (99);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n",
				(close(fd_from) == -1) ? fd_from : fd_to);
		return (100);
	}

	return (0);
}
