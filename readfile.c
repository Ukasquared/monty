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
	ssize_t n_read, n_write, supply_count, buf_size;
	int file_fd;
	char *buffer, *new_mem;


	supply_count = 0;
	buf_size = BUFSIZE;

	buffer = malloc(sizeof(char) * buf_size);


	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_fd = open_file(av[1]);

	while ((n_read = read(file_fd, buffer + supply_count,
					buf_size - supply_count)) > 0)
	{
		supply_count += n_read;

		/* check if buffer is full and if so reallocate it */

		if (supply_count >= buf_size)
		{

			buf_size += BUFSIZE;
			new_mem = realloc(buffer, buf_size);
			if (!new_mem)
				return (0);
			/* Assign new memory location to buffer */
			buffer = new_mem;
		}
		/* */

	}
	if (n_read == -1 || errno == EACCES)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close(file_fd);
		exit(EXIT_FAILURE);
	}
	close(file_fd);
	/*new_mem = strtok(buffer, "\n");*/
	/* temp_len = strlen(new_mem);*/
	n_write = write(STDOUT_FILENO, buffer, buf_size);
	/*n_write = write(STDOUT_FILENO, new_mem, temp_len);*/
	if (n_write == -1 || n_write < buf_size)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to stdout");
		exit(EXIT_FAILURE);
	}


	/* free allocated buffer memory */
	free(buffer);

	return (0);

}
/* write the content of the file on stdout */

