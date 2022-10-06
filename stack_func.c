#include "monty.h"


/**
 * push - push element into the stack
 * @stack: stack given by main
 * @l_count: amount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int l_count)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_count);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}


/**
* pop - pops the very top element of the stack
* @stack: stack given by main in start.c
* @l_count: line number for error messages
*
* Return: void
*/
void pop(stack_t **stack, unsigned int l_count)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", l_count);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}


/**
 * pall - prints the stack
 * @stack: stack given by main in start.c
 * @l_count: amount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int l_count __attribute__((unused)))
{
	print_stack(*stack);
}
