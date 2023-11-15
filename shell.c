#include "hell.h"

/**
 * free_data - structure frees for data
 *
 * @datash: Pointer in to the data structure to be initialized
 * Return: no retrn is expected
 */
void free_data(data_shell *datash)
{
    unsigned int idx;

    for (idx = 0; datash->_environ[idx]; idx++)
    {
        free(datash->_environ[idx]);
    }

    free(datash->_environ);
    free(datash->pid);
}

/**
 * set_data - Initialize the data structure
 *
 * @datash:  Pointer in to the data structure to be initialized
 * @av: Argument vector containing the initialization data
 * Return: no retrn is expected
 */
void set_data(data_shell *datash, char **av)
{
    unsigned int idx;

    datash->av = av;
    datash->input = NULL;
    datash->args = NULL;
    datash->status = 0;
    datash->counter = 1;

    for (idx = 0; environ[idx]; idx++)
        ;

    datash->_environ = malloc(sizeof(char *) * (idx + 1));

    for (idx = 0; environ[idx]; idx++)
    {
        datash->_environ[idx] = _strdup(environ[idx]);
    }

    datash->_environ[idx] = NULL;
    datash->pid = aux_itoa(getpid());
}

/**
 * main - the strt point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
    data_shell datash;
    (void) ac;

    signal(SIGINT, get_sigint);
    set_data(&datash, av);
    shell_loop(&datash);
    free_data(&datash);
    if (datash.status < 0)
        return (255);
    return (datash.status);
}
