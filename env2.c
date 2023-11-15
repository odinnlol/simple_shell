#include "hell.h"

/**
 * copy_info - the Copies information to create
 * the new environment or alias.
 * @name: a name (environment or alias).
 * @value: a value (environment or alias).
 *
 * Return: a new environment or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - Sets an environment variable.
 *
 * @name: a name of the environment variable.
 * @value: a value of the environment variable.
 * @datash: Data structure containing relevant information (environ).
 * Return: No return value.
 */
void set_env(char *name, char *value, data_shell *datash)
{
    int idx;
    char *var_env, *name_env;

    for (idx = 0; datash->_environ[idx]; idx++)
    {
        var_env = _strdup(datash->_environ[idx]);
        name_env = _strtok(var_env, "=");
        if (_strcmp(name_env, name) == 0)
        {
            free(datash->_environ[idx]);
            datash->_environ[idx] = copy_info(name_env, value);
            free(var_env);
            return;
        }
        free(var_env);
    }

    datash->_environ = _reallocdp(datash->_environ, idx, sizeof(char *) * (idx + 2));
    datash->_environ[idx] = copy_info(name, value);
    datash->_environ[idx + 1] = NULL;
}

/**
 * _setenv - the Compares environment variables names
 * with the name passed.
 * @datash: a Data relevant (environment name and value).
 *
 * Return: 1 on success.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - the Deletes an environment variable.
 *
 * @datash: a Data relevant (environment name).
 *
 * Return: 1 on success.
 */
int _unsetenv(data_shell *datash)
{
    char **realloc_environ;
    char *var_env, *name_env;
    int idx, li, mi;

    if (datash->args[1] == NULL)
    {
        get_error(datash, -1);
        return (1);
    }
    mi = -1;
    for (idx = 0; datash->_environ[idx]; idx++)
    {
        var_env = _strdup(datash->_environ[idx]);
        name_env = _strtok(var_env, "=");
        if (_strcmp(name_env, datash->args[1]) == 0)
        {
            mi = idx;
        }
        free(var_env);
    }
    if (mi == -1)
    {
        get_error(datash, -1);
        return (1);
    }
    realloc_environ = malloc(sizeof(char *) * (idx));
    for (idx = li = 0; datash->_environ[idx]; idx++)
    {
        if (idx != mi)
        {
            realloc_environ[li] = datash->_environ[idx];
            li++;
        }
    }
    realloc_environ[li] = NULL;
    free(datash->_environ[mi]);
    free(datash->_environ);
    datash->_environ = realloc_environ;
    return (1);
}

