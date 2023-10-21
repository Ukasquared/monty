#include "monty.h"
/**
 * free_list - frees allocated memory in a linked list
 * @stack_head: pointer to the linked list
 *
 * Return: void
 */
void free_list(list_t **stack_head)
{
	/* declare variables */
	list_t *currentNode;


	/* initialize variable */
	currentNode = NULL;


	if (stack_head && *stack_head)
	{
		if ((*stack_head)->next != NULL)
		{
			currentNode = *stack_head;
			*stack_head = (*stack_head)->next;
			free(currentNode);
		}
	}
}
