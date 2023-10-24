#include "monty.h"

stack_t *stack_top = NULL;
unsigned int line_count = 0;

/**
 * open_file - open a file
 * @file: file name
 *
 * Return: return file deescriptor or exit if file can't be open
 */
FILE *open_file(char *file)
{

	int f_status;
	FILE *f;

	f_status = -1;

	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	/* confirm file exist and grants read access */
	f_status = access(file, R_OK);
	if (f_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	f = fopen(file, "r");
	if (f == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	return (f);
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
	int status; /*f_status */
	FILE *f;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = open_file(av[1]);

	/* read file lines */
	while (1)
	{
		status = process_file_line(f, line_count);
		/* perform error check */
		if (status == 0)
			break;
		if (status == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
			fclose(f);
			exit(EXIT_FAILURE);
		}
	}
	/* exit program */
	fclose(f);
	exit(EXIT_SUCCESS);
}