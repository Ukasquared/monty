#include "monty.h"
/**
 * read_file - reads the characters in an open file
 * @buf: buffer to store the read characters
 * @fd: file descriptor of the open file
 *
 * Return: returns number of characters read, 0 on end of file or -1 for read
 * error
 */
ssize_t read_file(int fd, char **buf, size_t *n)
{
	char *new_mem, *mem;
	ssize_t n_read, supply_count;
	size_t buf_size, i;


	i = 0;
	errno = 0;
	buf_size = BUFSIZE;
	supply_count = 0;

	mem = *buf

	while ((n_read = read(fd, mem + supply_count, bufsize - supply_count)) > 0)
	{
		supply_count += n_read;

		/* check for newline character in the newly read data */
		for (i = supply_count - n_read; i < supply_count; i++)
		{
			if (mem[i] == '\n')
			{
				mem[i] == '\0';
				/* set file offset to the point where new line byte was found */
				if (lseek(fd, i, SEEK_SET) == -1)
				{
					/* print error message (please update)*/
				}
				return supply_count;
			}
		}
		/* check if the buffer is full, and if so, reallocate it */
		if (supply_count >= bufsize)
		{
			bufsize += BUFSIZE;
			new_mem = malloc(sizeof(char) * buf_size);
			if (new_mem == NULL)
			{
				/* Error malloc failed */
			}
			new_mem = strcpy(new_mem, mem);
			free(mem);
			mem = new_mem;
			*buf = mem;
			*n = bufsize;
		}
	}

	if (n_read == 0 && errno == 0)
	{
		/* EOF */
		return (0);
	}

	/* read failed */
	return (-1)
}
/**
 * _getline - read an entire line from file
 *
 *
 *
 *
 *
 *
 *
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char *mem;
	size_t buf_size, i;

	/* initialize variables */
	buf_size = BUFSIZE;
	supply_count = 0;
	mem = NULL;


	if (*lineptr == NULL || *n = 0)
	{
		mem = malloc(sizeof(char) * bufsize);
		if (mem == NULL)
		{
			/* Error malloc failed */
		}
		*lineptr = mem;
		*n = bufsize;
	}

	/* call read_file funct */
	supply_count = read_file(fd, lineptr, n);
	/* perform error check */
	if (supply_count == -1)
		return (-1);

	return (suppy_count);
}
