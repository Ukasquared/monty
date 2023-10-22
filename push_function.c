#include "main.h"

/**
 * push_func - inserts a node into the stack
 * @stack_top: linked list
 * @line_number: tracks line number
 * Return: void
 */

void push_func(stack_t **stack_top, unsigned int line_number)
{
	/* declare the stack_t pointers */
	stack_t *temp, *new;

	/* increase line number */
	line_number += 1;
	if (!stack_top)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	/* check if an integer is passed */
	if (bytecode_arr[1] != -1 && atoi(bytecode_arr[1]))
	{
		new->n = atoi(bytecode_arr[1]);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%lu: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->next = NULL;
	if (*stack_top == NULL)
		*stack_top = new;
	else
	{
		temp = *stack_top;
		(*stack_top)->prev = new;
		new->next = *stack_top;
		*stack_top = new;
	}
}
