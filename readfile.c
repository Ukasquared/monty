#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFSIZE 120

/* open a file */
size_t open_file(char *filename)
{
	int fd;

	/* initialize variable */
	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
/* read the content of the file */
int main(int ac, char *av[])
{
	/* declare variables */
	ssize_t n_read, n_write;
	int file_fd;
	char buffer[BUFSIZE];


	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_fd = open_file(av[1]);

	while ((n_read = read(file_fd, buffer, BUFSIZE)) > 0)
	{
		n_write = write(STDOUT_FILENO, buffer, n_read);

		if (n_write == -1 || n_write < n_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to stdout");
			close(file_fd);
			exit(EXIT_FAILURE);
		}
	}

	if (n_read == -1 || errno == EACCES)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close(file_fd);
		exit(EXIT_FAILURE);
	}

	close(file_fd);

	return (0);

}
/* write the content of the file on stdout */
