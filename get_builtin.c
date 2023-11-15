#include "hell.h"

/**
 * get_builtin - a Retrieves a function pointer for a builtin command based on the command name.
 * @cmd: a name of the command.
 * Return: A function of the pointer to the corresponding builtin command.
 */
int (*get_builtin(char *cmd))(data_shell *)
{
    builtin_t builtin[] = {
        { "env", _env },
        { "exit", exit_shell },
        { "setenv", _setenv },
        { "unsetenv", _unsetenv },
        { "cd", cd_shell },
        { "help", get_help },
        { NULL, NULL }
    };
    int idx;

    for (idx = 0; builtin[idx].name; idx++)
    {
        if (_strcmp(builtin[idx].name, cmd) == 0)
            break;
    }

    return (builtin[idx].f);
}

