#include "hell.h"

/**
 * get_sigint - the Handles the Ctrl+C signal in the prompt.
 * @sig: a signal handler function.
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
