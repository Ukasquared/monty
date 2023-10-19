#define _POSIX_C_SOURCE 200809L
#include "monty.h"
/**
 * open_file - open a file in read-only mode
 * @file_path: string containing the file name
 *
 * Return: file descriptor of the opened file or exit
 */

/* open a file */
size_t open_file(char *file_path)
{
	int fd;

	/* initialize variable */
	fd = open(file_path, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open from file <%s>\n", file_path);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

