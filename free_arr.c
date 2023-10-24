#include "monty.h"
/**
 * free_arr - frees allocated memory in a linked list
 * arr: pointer to the linked list
 *
 * Return: Nothing
 */
void free_arr(char **arr)
{
	int i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
