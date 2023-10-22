#include "monty.h"

/**
 * add_func - add the top two elements of the stack
 * @stack_top: linked list
 * @line_number: tracks number of each line
 * Return: void
 */

void add_func(stack_t **stack_top, unsigned int line_number)
{
	int sum, count;
	stack_t *ptr;

	count = 2;

	if (!stack_top || !(*stack) || !((*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%lu: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack_top;
	sum = ptr->n + ptr->next->n;
	while (count)
	{
		pop_funct(stack_top, line_number);
		count--;
	}
	bytecode_arr[1] = sum;
	push_func(stack_top, line_number);
}
