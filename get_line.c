#include "hell.h"

/**
 * bring_line - Assigns of the line variable for get_line.
 * @lineptr: Pointer to a buffer that stores the input string.
 * @buffer: a string that is being assigned to the line.
 * @bi: the Size of the line.
 * @li: the Size of the buffer.
 */
void bring_line(char **lineptr, size_t *bi, char *buffer, size_t li)
{
    if (*lineptr == NULL)
    {
        if (li > BUFSIZE)
            *bi = li;
        else
            *bi = BUFSIZE;
        *lineptr = buffer;
    }
    else if (*bi < li)
    {
        if (li > BUFSIZE)
            *bi = li;
        else
            *bi = BUFSIZE;
        *lineptr = buffer;
    }
    else
    {
        _strcpy(*lineptr, buffer);
        free(buffer);
    }
}
/**
 * get_line - Reads input from stream.
 * @lineptr: Pointer to a buffer that stores the input.
 * @bi: Size of the line buffer.
 * @stream: The stream to read from.
 * Return: The number of bytes read.
 */
ssize_t get_line(char **lineptr, size_t *bi, FILE *stream)
{
    int index;
    static ssize_t input;
    ssize_t retval;
    char *buffer;
    char t = 'z';

    if (input == 0)
        fflush(stream);
    else
        return (-1);
    input = 0;

    buffer = malloc(sizeof(char) * BUFSIZE);
    if (buffer == 0)
        return (-1);
    while (t != '\n')
    {
        index = read(STDIN_FILENO, &t, 1);
        if (index == -1 || (index == 0 && input == 0))
        {
            free(buffer);
            return (-1);
        }
        if (index == 0 && input != 0)
        {
            input++;
            break;
        }
        if (input >= BUFSIZE)
            buffer = _realloc(buffer, input, input + 1);
        buffer[input] = t;
        input++;
    }
    buffer[input] = '\0';
    bring_line(lineptr, bi, buffer, input);
    retval = input;
    if (index != 0)
        input = 0;
    return (retval);
}

