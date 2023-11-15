#include "hell.h"

/**
 *  * get_len - Get a length of an integer.
 *   * @n: a integer number.
 *    * Return: a Lenght of a number.
 *     */
int get_len(int n)
{
    unsigned int nu;
    int length = 1;

    if (n < 0)
    {
        length++;
        nu = n * -1;
    }
    else
    {
        nu = n;
    }

    while (nu > 9)
    {
        length++;
        nu = nu / 10;
    }

    return (length);
}
/**
 *  * aux_itoa - Converts an integer to a string.
 *   * @n: The integer number to convert.
 *    * Return: The resulting string.
 *     */
char *aux_itoa(int n)
{
    unsigned int nu;
    int length = get_len(n);
    char *buffer;

    buffer = malloc(sizeof(char) * (length + 1));
    if (buffer == 0)
        return (NULL);

    *(buffer + length) = '\0';

    if (n < 0)
    {
        nu = n * -1;
        buffer[0] = '-';
    }
    else
    {
        nu = n;
    }

    length--;
    do {
        *(buffer + length) = (nu % 10) + '0';
        nu = nu / 10;
        length--;
    }
    while (nu > 0);

    return (buffer);
}

/**
 *  * _atoi - Converts a string to an integer.
 *   * @s: The input string.
 *    * Return: The resulting integer.
 *     */
int _atoi(char *s)
{
    unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, index;

    while (*(s + count) != '\0')
    {
        if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
            break;

        if (*(s + count) == '-')
            pn *= -1;

        if ((*(s + count) >= '0') && (*(s + count) <= '9'))
        {
            if (size > 0)
                m *= 10;
            size++;
        }
        count++;
    }

    for (index = count - size; index < count; index++)
    {
        oi = oi + ((*(s + index) - 48) * m);
        m /= 10;
    }

    return (oi * pn);
}

