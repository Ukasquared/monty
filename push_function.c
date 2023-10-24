#include "monty.h"

/**
 * push_func - inserts a node into the stack
 * @stack_top: linked list
 * @line_number: tracks line number
 * Return: void
 */

void push_func(stack_t **stack_top, unsigned int line_number)
{
	/* declare the stack_t pointers */
	stack_t *new;
	(void)line_number;

	line_count++;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		/* free arr struct */
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* check if an integer is passed */
	new->n = num;
	new->prev = NULL;
	new->next = NULL;
	if (*stack_top == NULL)
		*stack_top = new;
	else
	{
		(*stack_top)->prev = new;
		new->next = *stack_top;
		*stack_top = new;
	}
}
