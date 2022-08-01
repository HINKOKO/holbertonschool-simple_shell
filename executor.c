#include "main.h"

/**
 *executor - exec the process
 *@buff: command entered to be executed
 *@env: the env in wich we exec commands
 */

void executor(char *buff, char **env)
{
	pid_t child;
	char **args = NULL;
	char *fullpath = NULL, *PATH;

	args = get_args(buff);
	if (args[0])
	{
		PATH = strdup(getenv("PATH"));
		fullpath = pathfinder(args[0], PATH);
		free(PATH);
		child = fork();
		if (child == 0)
		{
			if ((execve(fullpath, args, env)) == -1)
			{
				free_args(args);
				free(fullpath);
				return;
			}
		}

		else if (child > 0)
			wait(NULL);
		else
		{
			free_args(args);
			free(fullpath);
			exit(EXIT_FAILURE);
		}
		if (fullpath)
			free(fullpath);
	}
	free_args(args);
}
