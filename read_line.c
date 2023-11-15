#include "hell.h"

/**
 * read_line - Reads of the input string.
 *
 * @i_eof: The rtrn value of the getline function.
 * Return: an input string.
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
