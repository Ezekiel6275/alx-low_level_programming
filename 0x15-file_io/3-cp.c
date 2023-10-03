#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates a buffer of a specified size.
 * @file: The name of the file for error messages.
 *
 * Return: A pointer to the newly-allocated buffer, or NULL on failure.
 */
char *create_buffer(char *file)
{
	char *buffer = malloc(1024);

	if (buffer == NULL)
	{
	dprintf(STDERR_FILENO, "Error: Can't malloc\n");
	exit(98);
	}

	return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int status = close(fd);

	if (status == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
	}
}

/**
 * main - Copies the contents of one file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or appropriate exit codes on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, read_count, write_count;
	char *buffer;

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
	}

	buffer = create_buffer(argv[2]);
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	free(buffer);
	exit(98);
	}
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
	free(buffer);
	exit(99);
	{
		do
	}
	read_count = read(fd_from, buffer, 1024);
	if (read_count == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	free(buffer);
	close_file(fd_from);
	close_file(fd_to);
	exit(98);
	}

	write_count = write(fd_to, buffer, read_count);
	if (write_count == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
	free(buffer);
	close_file(fd_from);
	close_file(fd_to);
	exit(99);
	}

	} while (read_count > 0);

	free(buffer);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
