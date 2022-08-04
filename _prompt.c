#include "shell.h"

/**
 *_prompt - simple function only for displaying the prompt "> "
 *
 */

void _prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "> ", 2);
}
