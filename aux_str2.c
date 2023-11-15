#include "hell.h"

/**
 * _strdup - Duplicates a strg in heap memory.
 * @s: Type of a char pointer pointing to the source string.
 * Return: the duplicated string.
 */
char *_strdup(const char *s)
{
    char *new;
    size_t lix;

    lix = _strlen(s);
    new = malloc(sizeof(char) * (lix + 1));
    if (new == NULL)
        return (NULL);
    _memcpy(new, s, lix + 1);
    return (new);
}

/**
 * _strlen - Returns a length of a str.
 * @s: Type char pointer pointing to the strng.
 * Return: Always 0.
 */
int _strlen(const char *s)
{
    int lix;

    for (lix = 0; s[lix] != 0; lix++)
    {
    }

    return (lix);
}

/**
 * cmp_chars - Compare characters of strings.
 * @str: The input strng.
 * @delim: The delimiter character to compare.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
    unsigned int idx, li, mi;

    for (idx = 0, mi = 0; str[idx]; idx++)
    {
        for (li = 0; delim[li]; li++)
        {
            if (str[idx] == delim[li])
            {
                mi++;
                break;
            }
        }
    }

    if (idx == mi)
        return (1);
    
    return (0);
}

/**
 * _strtok - Splits a string by a specified delimiter.
 * @str: The input string.
 * @delim: The delimiter character.
 *
 * Return: A string representing the split parts.
 */
char *_strtok(char str[], const char *delim)
{
    static char *splitted, *str_end;
    char *str_start;
    unsigned int idx, bool;

    if (str != NULL)
    {
        if (cmp_chars(str, delim))
            return (NULL);
        splitted = str;
        idx = _strlen(str);
        str_end = &str[idx];
    }
    str_start = splitted;
    if (str_start == str_end)
        return (NULL);

    for (bool = 0; *splitted; splitted++)
    {
        if (splitted != str_start)
            if (*splitted && *(splitted - 1) == '\0')
                break;

        for (idx = 0; delim[idx]; idx++)
        {
            if (*splitted == delim[idx])
            {
                *splitted = '\0';
                if (splitted == str_start)
                    str_start++;
                break;
            }
        }
        if (bool == 0 && *splitted)
            bool = 1;
    }
    if (bool == 0)
        return (NULL);
    return (str_start);
}

/**
 * _isdigit - Determines if a string represents a number.
 *
 * @s: The input string to be checked.
 * Return: 1 if the string is a number, 0 otherwise.
 */
int _isdigit(const char *s)
{
    unsigned int idx;

    for (idx = 0; s[idx]; idx++)
    {
        if (s[idx] < 48 || s[idx] > 57)
            return (0);
    }

    return (1);
}
