#include "monty.h"

/**
 * main - entry point
 * @argv: list of arguments passed to our program
 * @argc: amount of args
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *mfile;
	size_t len = 0;
	char *line = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int l_count = 1;

	global.data_struct = 1;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mfile = fopen(argv[1], "r");
	if (!mfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, mfile)) != (-1))
	{
		if (*line == '\n')
		{
			l_count++;
			continue;
		}
		str = strtok(line, " \t\n");
		if (!str || *str == '#')
		{
			l_count++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, l_count);
		l_count++;
	}
	free(line);
	free_stack(stack);
	fclose(mfile);
	exit(EXIT_SUCCESS);
}


