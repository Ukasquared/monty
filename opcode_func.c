#include "monty.h"
/**
 * accept - accepts token as an argument
 * @token: the string token
 * @stack: the linked list
 * @line_number: linked list data
 * Return: function pointer if succesful
 */

void (*accept(char *token))(stack_t **stack, unsigned int line_number)
{
	int i;
	/* array of structs using the template in monty.h */
	instruction_t stack_arr[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", push_func},
		{"nop", NULL},
		{NULL, NULL},
	};
	/* loop through the array, compare and return corresponding function */
	for (i = 0; stack_arr[i].opcode != NULL;)
	{
		if (strcmp(stack_arr[i].opcode, token) == 0)
		{
			return (stack_arr[i].f);
		}
		i++;
	}
	/* prints error to standard error stream */
	/*dprintf(STDERR_FILENO, "L%lu: unknown instruction %s",
			line_number, token);*/
	/*returns NULL instead of pointer to function */
	return (NULL);
}
