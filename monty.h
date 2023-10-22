#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFSIZE 120

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: dobly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct list_s - singly linked list
 * @str: string -(malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	size_t len;
	struct list_s *next;
} list_t;

/* declare global variable for stack top */
extern stack_t *stack_top;

/* function prototypes */
void (*accept(char *token))(stack_t **stack, unsigned int line_number);

ssize_t is_empty_string(char *str, char *delim);
list_t *create_token_list(char *str, char *delim);
char **create_token_arr(list_t *h);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
int process_file_line(int fd);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char **parse_line(char *str, char *delim);
size_t list_len(const list_t *h);
void add_func(stack_t **stack_top, unsigned int line_number);
void free_node(stack_t **stack_head);
void pint_func(stack_t **stack_top, unsigned int line_number);
void pall_func(stack_t **stack_top, unsigned int line_number);
void pop_func(stack_t **stack_top, unsigned int line_number);
void push_func(stack_t **stack_top, unsigned int line_number);
void swap_func(stack_t **stack_top, unsigned int line_number);

#endif
