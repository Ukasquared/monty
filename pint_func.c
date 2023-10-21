#include "monty.h"
/**
 * pint_func - prints the value at the top of the stack
 *@stack_top: linked list
 *@line_number: number of line
 *Return: void
 */

void pint_func(stack_t stack_top, unsigned int line_number)
{
	line_number++;
	if (!stack_top || *stack_top == NULL)
	{
		dprintf(STDERR_FILENO, " L%lu: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_top)->n);
}
