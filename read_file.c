#include "monty.h"
#include <ctype.h>

int num = 0;

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

int execute_op(arr_t *dt, unsigned int line_c)
{
	void (*f)(stack_t **stack, unsigned int line_num);

	if (strcmp(dt->arr_toks[0], "push") == 0 && dt->arr_toks[1])
	{
		/* negative number */
		if (dt->arr_toks[1][0] == '-')
		{
			if (isdigit(dt->arr_toks[1][1]) == 0)
			{
				line_c++;
				dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_c);
				/*free struct and stack, and exit*/
				free_arr_struct(dt);
				free_stack(stack_top);
				exit(EXIT_FAILURE);
			}

			num = atoi(dt->arr_toks[1]);
			f = accept(dt->arr_toks[0]);
			f(&stack_top, line_c);
			/* free the arr struct and stack*/
			free_arr_struct(dt);
			return (1);
		}

		if (isdigit(dt->arr_toks[1][0]) == 0)
		{
			line_c++;
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_c);
			/*free struct and stack and exit*/
			free_arr_struct(dt);
			free_stack(stack_top);
			exit(EXIT_FAILURE);
		}

		num = atoi(dt->arr_toks[1]);
		f = accept(dt->arr_toks[0]);
		f(&stack_top, line_c);
		/*free arr strut*/
		free_arr_struct(dt);
		return (1);
	}

	f = accept(dt->arr_toks[0]);
	f(&stack_top, line_c);
	/*free arr toks*/
	free_arr_struct(dt);
	return (1);
}
/**
 * process_file_line - process
 * @f: file descriptor
 * @line_count: ..
 *
 * Return: ..
 */
int process_file_line(FILE *f, unsigned int line_count)
{
	ssize_t supply_count;
	char *lineptr;
	size_t n;
	arr_t *bcode_dt;

	/* initialize variables */
	supply_count = 0;
	lineptr = NULL;
	n = 0;
	errno = 0;

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
		free(lineptr);
		return (0);
	}

	/* remove new line character from line */
	if (strchr(lineptr, '\n') != NULL)
		over_write_nl(lineptr);

	/* parse the line read from file*/
	bcode_dt = parse_line(lineptr, " ");
	/* error check for empty line in file */
	if (bcode_dt == NULL)
	{
		free(lineptr);
		return (1);
	}
	/* error check for invalid opcode */
	if (accept(bcode_dt->arr_toks[0]) == NULL)
	{
		line_count++;
		/* print invalid instruction error message */
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_count, bcode_dt->arr_toks[0]);
		free_arr_struct(bcode_dt);
		fclose(f);
		exit(EXIT_FAILURE);
	}
	/* execute op code */
	execute_op(bcode_dt, line_count);
	/* if (op_stat == -1)
	{
		free_arr_struct(bcode_dt);
		return (-1);
	} */
	free_arr_struct(bcode_dt);
	return (1);
}