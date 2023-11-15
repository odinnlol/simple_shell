#include "hell.h"

/**
 * without_comment - Removes the comments from the input string.
 *
 * @bi: The input string.
 * Return: The input string without comments.
 */
char *without_comment(char *bi)
{
    int idx, up_to;

    up_to = 0;
    for (idx = 0; bi[idx]; idx++)
    {
        if (bi[idx] == '#')
        {
            if (idx == 0)
            {
                free(bi);
                return (NULL);
            }

            if (bi[idx - 1] == ' ' || bi[idx - 1] == '\t' || bi[idx - 1] == ';')
                up_to = idx;
        }
    }

    if (up_to != 0)
    {
        bi = _realloc(bi, idx, up_to + 1);
        bi[up_to] = '\0';
    }

    return (bi);
}

/**
 * shell_loop - Main loop of the shell.
 * @datash: Data structure relevant (av, input, args)
 *
 * Return: No return value.
 */
void shell_loop(data_shell *datash)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			loop = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
