#include "monty.h"
/**
 * parse_line - generate a NULL terminated array containing the words in a
 * string
 * @str: pointer to the string
 * @delim: pointer to the character that separtes words in string
 *
 * Return: returns pointer to an array of pointers or exits the program
 */
arr_t *parse_line(char *str, char *delim)
{
	/* declare variables */
	char *full_str;
	list_t *head;
	arr_t *arr_data;

	/* initialize variables */
	full_str = str;
	head = NULL;
	arr_data = NULL;

	/* confirm argument passed is not empty */
	if (full_str == NULL || *full_str == '\0')
		return (NULL);

	/* check that string contains atleast one non-delimiter character */
	if (is_empty_string(full_str, delim) == -1)
		return (NULL);

	head = create_token_list(full_str, delim);
	if (head == NULL)
	{
		/* print malloc failed error */
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free(full_str);
		exit(EXIT_FAILURE);
	}

	arr_data = create_token_arr(head);
	if (arr_data == NULL)
	{
		/* print malloc failed error */
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free(full_str);
		free_list(head);
		exit(EXIT_FAILURE);
	}

	/* free input buffer */
	free(full_str);

	return (arr_data);
}