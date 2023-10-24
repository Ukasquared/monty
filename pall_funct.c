#include "monty.h"

/**
 * pall_func - prints the value on the stack
 * @stack_top: linked list
 * @line_number: number of each processed line
 * Return: void
 */

void pall_func(stack_t **stack_top, unsigned int line_number)
{
	stack_t *ptr;

	ptr = *stack_top;
	while (ptr != NULL)
	{
		line_number--;
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
