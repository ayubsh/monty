#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <ctype.h>
#include <aio.h>

typedef intptr_t ssize_t;

#define INSTRUCTIONS              \
	{                           \
		{"push", push},       \
		    {"pall", pall},   \
		    {"pint", pint},   \
		    {"pop", pop},     \
		    {"swap", swap},   \
                    {"add", _add},   \
		{                     \
			NULL, NULL      \
		}                     \
	}

/**
* struct help - argument for the current opcode
* @data_struct: stack mode, stack (default) and queue
* @argument: the arguments of the string
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
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


void push(stack_t **stack, unsigned int l_count);
void pall(stack_t **stack, unsigned int l_count);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
stack_t *add_node(stack_t **stack, const int n);
int is_digit(char *string);
stack_t *queue_node(stack_t **stack, const int n);
void _add(stack_t **stack, unsigned int l_count);
void pint(stack_t **stack, unsigned int l_count);
void swap(stack_t **stack, unsigned int l_count);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);
void pop(stack_t **stack, unsigned int l_count);

void opcode(stack_t **stack, char *str, unsigned int l_count);

#endif
