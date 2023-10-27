#include "monty.h"
/**
 * free_stack - frees allocated memory in a linked list
 * @stack: pointer to the linked list
 *
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	/* declare variables */
	stack_t *currentNode;

	/* initialize variable */
	currentNode = NULL;

	if (stack)
	{
		while (stack->next != NULL)
		{
			currentNode = stack;
			stack = stack->next;
			free(currentNode);
		}
		free(stack);
	}
}
