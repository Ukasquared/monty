#include "monty.h"

/**
 * pop_func - deletes the value at the top of the stack
 * @stack_top: linked list
 * @line_number: number of line
 * Return: void
 */

void pop_func(stack_t **stack_top, unsigned int line_number)
{
	if (!stack_top || *stack_top == NULL)
	{
		dprintf(STDERR_FILENO, " L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	free_node(stack_top);
}
