#include "monty.h"
/**
 * free_node - frees a node
 * @stack_head:linked list
 *
 * Return: void
 */

void free_node(stack_t **stack_head)
{
	/* declare variables */
	stack_t *currentNode;

	/* initialize variable */
	currentNode = NULL;

	if (stack_head && *stack_head)
	{
		if (*stack_head != NULL)
		{
			currentNode = *stack_head;
			*stack_head = (*stack_head)->next;
			free(currentNode);
		}
	}
}
