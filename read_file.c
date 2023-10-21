#include "monty.h"
/**
 * process_file_line - process
 *
 *
 *
 *
 *
 *
 */
int process_file_line(int fd)
{
	ssize_t supply_count;
	char *lineptr, **bytecode_arr;
	size_t n;

	/* initialize variables */
	suppy_count = 0;
	line_ptr = NULL;
	n = 0;



	/* get line from file */
	supply_count = _getline(&lineptr, &n, fd);
	/* perform error checks */
	if (supply_count == -1)
	{
		/* print error message */
		free(lineptr);
		return (-1);
	}
	if (supply_count == 0)
		return (0);
	/* increment file line counter */
	line_num++;
	/* parse the line read from file*/
	bytecode_arr = parse_line(lineptr);
	/* error check for empty line in file */
	if (bytecode_arr == NULL)
		return (1);
	/* error check for invalid opcode */
	if (accept(bytecode_arr[0]) == NULL)
	{
		/* print invalid instruction error message */
		dprintf("Invalid instruction");
		close(fd);
		exit(EXIT_FAILURE);
	}

	/* execute op code */
	execute_op()
}
