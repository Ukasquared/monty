#define _POSIX_C_SOURCE 200809L
#include "monty.h"
/**
 * open_file - open a file in read-only mode
 * @file_path: string containing the file name
 *
 * Return: file descriptor of the opened file or exit
 */

/* open a file */
size_t open_file(char *file_path)
{
	int fd;

	/* initialize variable */
	fd = open(file_path, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open from file <%s>\n", file_path);
		exit(EXIT_FAILURE);
	}

	return (fd);
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
	char  *line, *token;
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
char **create_token_arr(list_t *h)
{
	/* declare variables */
	list *temp;
	char **ptr_arr;
	size_t arr_size, arr_idx;

	/* initialize variables */
	temp = h;
	arr_idx = 0;
	arr_size = list_len(h) + 1;

	ptr_arr = malloc(sizeof(char *) * arr_size);
	if (ptr_arr == NULL)
		return (NULL);

	while (temp != NULL)
	{
		ptr_arr[arr_idx] = strdup(temp->str);
		if (ptr_arr[arr_idx] == NULL && errno == ENONEM)
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
	return (ptr_arr);
}
