#include "monty.h"

/**
 * swap_funct - swaps two element on the stack
 * @stack_top: linked list
 * @line_number: number of line
 * Return: void
 */

void swap_funct(stack_t **stack_top, unsigned int line_number)
{
	int temp;
	stack_t *ptr;

	if (!stack_top || !(*stack_top) || !(*stack_top)->next)
	{
		dprintf(STDERR_FILENO, "L%lu: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack_top;
	temp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = temp;
}
