#define _POSIX_C_SOURCE 200809L
#include "monty.h"
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
	ssize_t supply_count;
	int fd;
	size_t n, line_num;
	char *lineptr, **bytecode_arr;
	stack_t *head, *stack_top;


	/* initialize variables */
	supply_count = 0;
	lineptr = NULL;
	n = 0;
	line_num = 0;
	head = NULL;
	stack_top = NULL;
	errno = 0;


	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open_file(av[1]);

	while (1)
	{
		/* get line from file */
		supply_count = _getline(&lineptr, &n, fd);
		/* perform error checks */
		if (supply_count == -1)
		{
			if (errno == 0)
			{
				break;
			}
			else
			{
				free(lineptr);
				exit(EXIT_FAILURE);
			}
		}
		/* increment file line counter */
		line_num++;
		/* parse the line read from file*/
		bytecode_arr = parse_line(lineptr);
		/* perform error checks */
		if (bytecode_arr == NULL)
			continue;
		/* get opcode function using the first item in array*/
		/* if opcode function is returned */
		/* if the array_size == 2 */
		/* convert the second item in the array to integer and pass it to the
		 * opcode function */
		/* pass the head of the stack to the opcode function */
		/* the opcode function will return pointer to stack top */
	}


	free(lineptr);
	exit(EXIT_SUCCESS);
}

