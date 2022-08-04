#include "shell.h"

/**
 *handle_signal - function that handle the signal Ctrl^C
 *Indeed, when Ctrl^C is typed, the program doesn't quit
 *but displays a new line ready to go
 *@signum: unused here.
 */

void handle_signal(__attribute__((unused)) int signum)
{
	write(STDOUT_FILENO, "\n", 2);
	_prompt();
}
