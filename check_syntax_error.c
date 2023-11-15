#include "hell.h"

/**
 * repeated_char - Counts the repetitions of a character in a string.
 *
 * @input: The input string.
 * @idx: The idx of the character to count repetitions.
 * Return: The number of repetitions of the character.
 */
int repeated_char(char *input, int idx)
{
    if (*(input - 1) == *input)
        return (repeated_char(input - 1, idx + 1));

    return (idx);
}

/**
 * error_sep_op - Identifies syntax errors.
 *
 * @input: The input string to analyze.
 * @idx: The idx of the current character being examined.
 * @last: The last character read.
 * Return: The idx of error. 0 when there are no
 * errors
 */
int error_sep_op(char *input, int idx, char last)
{
    int count;

    count = 0;
    if (*input == '\0')
        return (0);

    if (*input == ' ' || *input == '\t')
        return (error_sep_op(input + 1, idx + 1, last));

    if (*input == ';')
        if (last == '|' || last == '&' || last == ';')
            return (idx);

    if (*input == '|')
    {
        if (last == ';' || last == '&')
            return (idx);

        if (last == '|')
        {
            count = repeated_char(input, 0);
            if (count == 0 || count > 1)
                return (idx);
        }
    }

    if (*input == '&')
    {
        if (last == ';' || last == '|')
            return (idx);

        if (last == '&')
        {
            count = repeated_char(input, 0);
            if (count == 0 || count > 1)
                return (idx);
        }
    }

    return (error_sep_op(input + 1, idx + 1, *input));
}

/**
 * first_char - Finds the idx of the first character in an input string.
 *
 * @input: The input string to search.
 * @idx: The idx at which to start searching.
 * Return: 1 if there is an error, 0 otherwise.
 */
int first_char(char *input, int *idx)
{
    for (*idx = 0; input[*idx]; (*idx) += 1)
    {
        if (input[*idx] == ' ' || input[*idx] == '\t')
            continue;

        if (input[*idx] == ';' || input[*idx] == '|' || input[*idx] == '&')
            return (-1);

        break;
    }

    return (0);
}

/**
 * print_syntax_error - Prints a syntax error message when one is found.
 *
 * @datash: The data structure.
 * @input: The input string being analyzed.
 * @idx: The idx of the syntax error.
 * @bool: to control the error message display.
 * Return: No return value.
 */
void print_syntax_error(data_shell *datash, char *input, int idx, int bool)
{
    char *msg, *msg2, *msg3, *error, *counter;
    int length;

    if (input[idx] == ';')
    {
        if (bool == 0)
            msg = (input[idx + 1] == ';' ? ";;" : ";");
        else
            msg = (input[idx - 1] == ';' ? ";;" : ";");
    }

    if (input[idx] == '|')
        msg = (input[idx + 1] == '|' ? "||" : "|");

    if (input[idx] == '&')
        msg = (input[idx + 1] == '&' ? "&&" : "&");

    msg2 = ": Syntax error: \"";
    msg3 = "\" unexpected\n";
    counter = aux_itoa(datash->counter);
    length = _strlen(datash->av[0]) + _strlen(counter);
    length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

    error = malloc(sizeof(char) * (length + 1));
    if (error == 0)
    {
        free(counter);
        return;
    }
    _strcpy(error, datash->av[0]);
    _strcat(error, ": ");
    _strcat(error, counter);
    _strcat(error, msg2);
    _strcat(error, msg);
    _strcat(error, msg3);
    _strcat(error, "\0");

    write(STDERR_FILENO, error, length);
    free(error);
    free(counter);
}

/**
 * check_syntax_error - Intermediate function to
 * identify and print a syntax error.
 *
 * @datash: The data structure.
 * @input: The input string.
 * Return: 1 if there is a syntax error, 0 otherwise.
 */
int check_syntax_error(data_shell *datash, char *input)
{
    int begin = 0;
    int f_char = 0;
    int idx = 0;

    f_char = first_char(input, &begin);
    if (f_char == -1)
    {
        print_syntax_error(datash, input, begin, 0);
        return (1);
    }

    idx = error_sep_op(input + begin, 0, *(input + begin));
    if (idx != 0)
    {
        print_syntax_error(datash, input, begin + idx, 1);
        return (1);
    }

    return (0);
}

