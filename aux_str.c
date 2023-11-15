#include "hell.h"

/**
 *  * _strcat - concatenate two strings.
 *   * @dest: char pointer pointing to the destination of the copied string.
 *    * @src: const char pointer pointing to the source string.
 *     * Return: a pointer to the destination.
 *      */
char *_strcat(char *dest, const char *src)
{
    int idx;
    int li;

    for (idx = 0; dest[idx] != '\0'; idx++)
        ;

    for (li = 0; src[li] != '\0'; li++)
    {
        dest[idx] = src[li];
        idx++;
    }

    dest[idx] = '\0';
    return (dest);
}
/**
 *  * *_strcpy - aCopy the string pointed to by source.
 *   * @dest: a Type char pointer pointing to the destination of the copied string.
 *    * @src: a Type char pointer pointing to the source string.
 *     * Return: the pointer to the destination.
 *      */
char *_strcpy(char *dest, char *src)
{
    size_t o;

    for (o = 0; src[o] != '\0'; o++)
    {
        dest[o] = src[o];
    }

    dest[o] = '\0';

    return (dest);
}
/**
 *  * _strcmp - Function that compares two strings.
 *   * @s1: The first string to be compared.
 *    * @s2: The second string to be compared.
 *     * Return: Always returns 0.
 *      */
int _strcmp(char *s1, char *s2)
{
    int idx;

    for (idx = 0; s1[idx] == s2[idx] && s1[idx]; idx++)
        ;

    if (s1[idx] > s2[idx])
        return (1);
    if (s1[idx] < s2[idx])
        return (-1);

    return (0);
}
/**
 *  * _strchr - a locates a char in a str.
 *   * @s: a string to search in.
 *    * @c: a character to locate.
 *     * Return: the pointer to the first occurrence of the char c.
 *      */
char *_strchr(char *s, char c)
{
    unsigned int idx = 0;

    for (; *(s + idx) != '\0'; idx++)
    {
        if (*(s + idx) == c)
        {
            return (s + idx);
        }
    }

    if (*(s + idx) == c)
    {
        return (s + idx);
    }

    return ('\0');
}
/**
 *  * _strspn - gets the length of a prefix substring.
 *   * @s: a initial segment to check.
 *    * @accept: a accepted bytes.
 *     * Return: a number of accepted bytes.
 *      */
int _strspn(char *s, char *accept)
{
            int idx, li, bool;

                for (idx = 0; *(s + idx) != '\0'; idx++)
                                    {
                                                    bool = 1;
                                                                for (li = 0; *(accept + li) != '\0'; li++)
                                                                                        {
                                                                                                                        if (*(s + idx) == *(accept + li))
                                                                                                                                                            {
                                                                                                                                                                                            bool = 0;
                                                                                                                                                                                                                    break;
                                                                                                                                                                                                                                            }
                                                                                                                                            }
                                                                                if (bool == 1)
                                                                                                                break;
                                                                                        }
                            return (idx);
}

