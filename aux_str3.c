#include "hell.h"

/**
 * rev_string - Reverses of a string in place.
 * @s: The input strng to be reversed.
 * Return: No return value.
 */
void rev_string(char *s)
{
    int count = 0, idx, li;
    char *str, temp;

    while (count >= 0)
    {
        if (s[count] == '\0')
            break;
        count++;
    }
    str = s;

    for (idx = 0; idx < (count - 1); idx++)
    {
        for (li = idx + 1; li > 0; li--)
        {
            temp = *(str + li);
            *(str + li) = *(str + (li - 1));
            *(str + (li - 1)) = temp;
        }
    }
}

