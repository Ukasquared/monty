#define _POSIX_C_SOURCE 200809L
#include "monty.h"
/**
 * free_arr_struct - free allocated memory
 * @data: ..
 *
 * Return: returns nothing
 */
void free_arr_struct(arr_t *data)
{
	char **arr;
	size_t n;

	n = 0;
	arr = data->arr_toks;
	/* free 2D array */
	while (arr[n] != NULL)
	{
		free(arr[n]);
		n++;
	}
	free(arr);

	/* free struct */
	free(data);
}
/**
 * over_write_nl - search for the newline character in a string and replaces it
 * with a null byte character
 * @str: pointer to the string
 *
 * Return: returns Nothings
 */
void over_write_nl(char *str)
{
	/* declare variables */
	char *newline_str;
	size_t idx;

	/* initialize variables */
	newline_str = str;
	idx = 0;

	/* get index of new line character */
	while (newline_str[idx] != '\n')
		idx++;

	/* overwrite the newline character with a null byte */
	newline_str[idx] = '\0';
}
/**
 * is_empty_string - checks if a string has any non-delimiter character
 * @str: pointer to the string
 * @delim: pointer to the delimiter character
 *
 * Return: return 0 if the strings non-delimiter characters or -1 otherwise
 */
ssize_t is_empty_string(char *str, char *delim)
{
	/* declare variable */
	char *str_ptr;

	/* initialize variable */
	str_ptr = str;

	/* scan the string */
	while (*str_ptr == *delim)
		str_ptr++;

	if (*str_ptr == '\0')
		return (-1);

	return (0);
}
/**
 * create_token_list - builds a linked list of words in a strings
 * @str: pointer to the string
 * @delim: pointer to the delimiter character
 *
 * Return: returns a pointer to the linked list or NULL otherwise
 */
list_t *create_token_list(char *str, char *delim)
{
	/* declare variable */
	char *line, *token;
	list_t *head, *node;

	/* initialize variable */
	line = str;
	head = NULL;
	node = NULL;

	/* tokenize string */
	token = strtok(line, delim);
	while (token != NULL)
	{
		node = add_node_end(&head, token);
		if (node == NULL)
			return (NULL);
		token = strtok(NULL, delim);
	}

	return (head);
}
/**
 * create_token_arr - creates an array of pointer from a value in a linked list
 * @h: pointer to the head of a linked list
 *
 * Return: return an array of pointer or NULL otherwise
 */
arr_t *create_token_arr(list_t *h)
{
	/* declare variables */
	list_t *temp;
	char **ptr_arr;
	arr_t *arr_data;
	size_t arr_size, arr_idx;

	/* initialize variables */
	temp = h;
	arr_idx = 0;
	errno = 0;
	arr_data = NULL;
	arr_size = list_len(h) + 1;

	ptr_arr = malloc(sizeof(char *) * arr_size);
	if (ptr_arr == NULL)
		return (NULL);
	arr_data = malloc(sizeof(arr_t));
	if (arr_data == NULL)
		return (NULL);

	while (temp != NULL)
	{
		ptr_arr[arr_idx] = strdup(temp->str);
		if (ptr_arr[arr_idx] == NULL && errno == ENOMEM)
		{
			free_list(h);
			return (NULL);
		}
		arr_idx++;
		temp = temp->next;
	}
	/* null-terminate the array */
	ptr_arr[arr_idx] = NULL;

	free_list(h);
	/* populate arr_data struct */
	arr_data->arr_size = arr_size;
	arr_data->arr_toks = ptr_arr;

	return (arr_data);
}