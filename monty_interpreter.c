#define _POSIX_C_SOURCE 200809L
#include "monty.h"
stack_t *stack_top = NULL;

/**
 * open_file - open a file
 * @file: file name
 *
 * Return: return file deescriptor or exit if file can't be open
 */
int open_file(char *file)
{

	int fd, f_status;

	fd = -1;
	f_status = -1;

	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file <%s>\n", file);
		exit(EXIT_FAILURE);
	}

	/* confirm file exist and grants read access */
	f_status = access(file, R_OK);
	if (f_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file <%s>\n", file);
		exit(EXIT_FAILURE);
	}

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file <%s>\n", file);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - entry point of the interpreter program
 * @ac: count of the command line args passed to the program
 * @av: array of pointer to the command line args passed to the program
 *
 * Return: EXIT_SUCCESS on successful execution or EXIT_FAILURE otherwise
 */
int main(int ac, char *av[])
{
	/* declare variables */
	int fd, status, f_status;


	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open_file(av[1]);

	/* read file lines */
	while (1)
	{
		status = process_file_line(fd);
		/* perform error check */
		if (status == 0)
			break;
		if (status == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read file <%s>\n", av[1]);
			close(fd);
			exit(EXIT_FAILURE);
		}
	}


	/* exit program */
	close(fd);
	exit(EXIT_SUCCESS);
}

