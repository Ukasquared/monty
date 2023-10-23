#define _XOPEN_SOURCE 700
#include "monty.h"
#include <ctype.h>
/**
 * execute_op - executes the opcode function
 * @dt: data structure containing details of the bytecode
 * @line_c: command line number in the file
 *
 * Description: execute op will take in the entire byte array and then check if
 * the array elements is greater than 1. If the array elements is greater than
 * 1, it will if the opcode that was passed is push. if the opcode passed
 * is push, it then tries to covert the second element to an integer
 * Return: returns 1 on success or -1 on error
 */

int execute_op(arr_t *dt, size_t line_c)
{
	void (*f)(stack_t **stack, unsigned int line_num);
	int num = 0;

	/* if (dt->arr_size > 2) */
	if (strcmp(dt->arr_toks[0], "push") == 0)
	{
		/* negative number */
		if (dt->arr_toks[1][0] == '-')
		{
			if (isdigit(dt->arr_toks[1][1]) == 0)
			{
				dprintf(STDERR_FILENO, "L<%lu>: usage push integer\n",
						line_c);
				return (-1);
			}
		}

		if (isdigit(dt->arr_toks[1][0]) == 0)
		{
			dprintf(STDERR_FILENO, "L<%lu>: usage push integer\n",
					line_c);
			return (-1);
		}

		num = atoi(dt->arr_toks[1]);
		f = accept(dt->arr_toks[0]);
		f(&stack_top, num);
		return (1);
	}

	f = accept(dt->arr_toks[0]);
	f(&stack_top, line_c);

	return (1);
}
/**
 * process_file_line - process
 * @f: file descriptor
 * @line_count: ..
 *
 * Return: ..
 */
int process_file_line(FILE *f, size_t line_count)
{
	ssize_t supply_count;
	char *lineptr;
	size_t n;
	arr_t *bcode_dt;
	int op_stat;

	/* initialize variables */
	supply_count = 0;
	lineptr = NULL;
	n = 0;
	errno = 0;
	op_stat = 0;

	/* get line from file */
	supply_count = getline(&lineptr, &n, f);
	/* perform error checks */
	if (supply_count == -1)
	{
		if (errno != 0)
		{
			free(lineptr);
			return (-1);
		}
		return (0);
	}

	/* remove new line character from line */
	if (strchr(lineptr, '\n') != NULL)
		over_write_nl(lineptr);

	/* parse the line read from file*/
	bcode_dt = parse_line(lineptr, " ");
	/* error check for empty line in file */
	if (bcode_dt->arr_toks[0] == NULL)
		return (1);
	/* error check for invalid opcode */
	if (accept(bcode_dt->arr_toks[0]) == NULL)
	{
		/* print invalid instruction error message */
		dprintf(STDERR_FILENO, "L<%lu>: unknown instruction <%s>\n",
				line_count, bcode_dt->arr_toks[0]);
		fclose(f);
		exit(EXIT_FAILURE);
	}

	/* execute op code */
	op_stat = execute_op(bcode_dt, line_count);
	if (op_stat == -1)
		return (-1);

	return (1);
}
