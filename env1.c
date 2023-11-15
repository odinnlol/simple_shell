#include "hell.h"

/**
 * cmp_env_name - a Compares environment variable names
 * with the name passed.
 * @nenv: a name of the environment variable to compare.
 * @name: a name passed for comparison.
 *
 * Return: 0 if they are not equal, another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
    int idx;

    for (idx = 0; nenv[idx] != '='; idx++)
    {
        if (nenv[idx] != name[idx])
        {
            return (0);
        }
    }

    return (idx + 1);
}

/**
 * _getenv - a get the value of an environment variable.
 * @name: a name of the environment variable to retrieve.
 * @_environ: a environment variable.
 *
 * Return: a value of the environment variable if found.
 * otherwise returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
    char *ptr_env;
    int idx, mov;

    ptr_env = NULL;
    mov = 0;
    
    for (idx = 0; _environ[idx]; idx++)
    {
        mov = cmp_env_name(_environ[idx], name);
        if (mov)
        {
            ptr_env = _environ[idx];
            break;
        }
    }

    return (ptr_env + mov);
}

/**
 * _env - Prints the environment variables.
 *
 * @datash: the Data structure containing relevant information.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
    int idx, li;

    for (idx = 0; datash->_environ[idx]; idx++)
    {
        for (li = 0; datash->_environ[idx][li]; li++)
            ;

        write(STDOUT_FILENO, datash->_environ[idx], li);
        write(STDOUT_FILENO, "\n", 1);
    }
    datash->status = 0;

    return (1);
}

