#include "monty.h"

/**
 * opcode - function in charge of running builtins
 * @stack: stack given by main
 * @str: string to compare
 * @l_count: amount of lines
 *
 * Return: nothing
 */
void opcode(stack_t **stack, char *str, unsigned int l_count)
{
	int i = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, l_count);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", l_count, str);
	exit(EXIT_FAILURE);
}
