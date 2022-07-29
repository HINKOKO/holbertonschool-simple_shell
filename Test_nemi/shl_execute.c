#include "main.h"

int shl_execute(char **args)
{
	pid_t child;

	child = fork();
	if (child == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (child > 0)
	{
		wait(NULL);
	}
	else
	{
		return (1);
	}
	return (0);
}
