#include "hell.h"

/**
 * get_error - a Calls the appropriate error message based on the context (builtin, syntax, or permission).
 * @datash: Data structure containing relevant information (arguments).
 * @erval: a error value that determines the context.
 * Return: a appropriate error message.
 */
int get_error(data_shell *datash, int erval)
{
    char *error;

    switch (erval)
    {
    case -1:
        error = error_env(datash);
        break;
    case 126:
        error = error_path_126(datash);
        break;
    case 127:
        error = error_not_found(datash);
        break;
    case 2:
        if (_strcmp("exit", datash->args[0]) == 0)
            error = error_exit_shell(datash);
        else if (_strcmp("cd", datash->args[0]) == 0)
            error = error_get_cd(datash);
        break;
    }

    if (error)
    {
        write(STDERR_FILENO, error, _strlen(error));
        free(error);
    }

    datash->status = erval;
    return (erval);
}

