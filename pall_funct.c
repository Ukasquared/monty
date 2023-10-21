#include "monty.h"

/**
 * pall_func - prints the value on the stack
 * @stack: linked list
 * @line_number: number of each processed line
 * Return: void
 */

void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	/* check if null was passed into the function */
	if (!stack || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%lu: usage: pall\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*loop backwards if the stack-prev is not NULL */
	while ((*stack)->prev != NULL)
		*stack = stack->prev;

	ptr = *stack;
	while (ptr != NULL)
	{
		line_number--;
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}
