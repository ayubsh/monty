#include "monty.h"


ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos;
	char *new_ptr;
	int c, new_size;

	if (lineptr == NULL || stream == NULL || n == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	c = getc(stream);
	if (c == EOF)
		return (-1);
	if (*lineptr == NULL)
	{
		*lineptr = malloc(128);
		if (*lineptr == NULL)
			return (-1);
		*n = 128;
	}
	pos = 0;
	while (c != EOF)
	{
		if (pos + 1 >= *n)
		{
			new_size = *n + (*n >> 2);
			if (new_size < 128)
				new_size = 128;
			new_ptr = realloc(*lineptr, new_size);
			if (new_ptr == NULL)
				return (-1);
			*n = new_size;
			*lineptr = new_ptr;
		}
		((unsigned char *)(*lineptr))[pos++] = c;
		if (c == '\n')
			break;
		c = getc(stream);
	}
	(*lineptr)[pos] = '\0';
	return (pos);
}


/**
 * is_digit - checks if a string is a digit
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
