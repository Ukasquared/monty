#include "monty.h"

/**
 * pop_funct - prints the value at the top of the stack
 * @stack_top: linked list
 * @line_number: number of line
 * Return: void
 */

void pop_funct(stack_t **stack_top, unsigned int line_number)
{
	stack_t *temp;
	line_number--`;
	if (!stack_top || *stack_top == NULL)
	{
		dprintf(STDERR_FILENO, " L%lu: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack_top;
	*stack_top = (*stack_top)->next;
	free_node(temp);
}
