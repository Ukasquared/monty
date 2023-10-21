#include "monty.h"

/**
 * pop_funct - prints the value at the top of the stack
 * @stack: linked list
 * @line_number: number of line
 * Return: void
 */

void pop_funct(stack_t **stack, unsigned int line_number)
{
	line_number++;
	if (!stack || *stack == NULL)
	{
		dprintf(STDERR_FILENO, " L%lu: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	free_node(stack);
}
