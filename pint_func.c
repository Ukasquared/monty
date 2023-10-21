#include "monty.h"
/**
 pint_funct - prints the value at the top of the stack
 @stack: linked list
 @line_number: number of line
 Return: void
*/

void pint_func(stack_t stack, unsigned int line_number)
{
	line_number++;
	if (!stack || *stack == NULL)
	{
		dprintf(STDERR_FILENO," L%lu: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack->prev != NULL)
		*stack = stack->prev;
	printf("%d\n", stack->data);
}	
